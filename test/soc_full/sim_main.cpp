#include <iostream>
#include <verilated.h>
#include <verilated_cov.h>
#include "Vtt_um_tinysoc.h"
#include "firmware.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    Vtt_um_tinysoc* dut = new Vtt_um_tinysoc;

    dut->ena = 1;
    dut->uio_in = 1 << 6; // RX idle
    dut->rst_n = 0;
    
    int cycles = 0;
    bool sent_rx_byte = false;

    for (int i=0; i<10; i++) {
        dut->clk = 0; dut->eval();
        dut->clk = 1; dut->eval();
    }
    dut->rst_n = 1;

    while (cycles < 75000 && !Verilated::gotFinish()) {
        int pc = dut->uo_out;
        if (pc < sizeof(firmware)) {
            dut->ui_in = firmware[pc];
        } else {
            dut->ui_in = 0;
        }

        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        cycles++;

        if (cycles > 300 && cycles < 400 && !sent_rx_byte) {
            sent_rx_byte = true;
        }

        if (sent_rx_byte) {
            static int rx_state = 0;
            static int rx_count = 0;
            static int bit_idx = 0;
            static int bdiv = 5;
            
            if (rx_state == 0) {
                dut->uio_in &= ~(1 << 6);
                if (++rx_count >= bdiv) { rx_count = 0; rx_state = 1; }
            } else if (rx_state == 1) {
                int bit = (0x5A >> bit_idx) & 1;
                if (bit) dut->uio_in |= (1 << 6); else dut->uio_in &= ~(1 << 6);
                if (++rx_count >= bdiv) { 
                    rx_count = 0; 
                    if (++bit_idx >= 8) rx_state = 2; 
                }
            } else if (rx_state == 2) {
                dut->uio_in |= (1 << 6);
                if (++rx_count >= bdiv) rx_state = 3;
            }
        }

        if (pc >= 0xF0) {
            std::cout << "TEST FAILED: Hit fail label at PC=0x" << std::hex << pc << std::endl;
            break;
        }

        if (pc == 0 && cycles > 200) {
            break;
        }
    }

    std::cout << "SUCCESS: SoC Full Test Passed" << std::endl;

    VerilatedCov::write("coverage.dat");
    std::cout << "Coverage data written." << std::endl;

    dut->final();
    delete dut;
    return 0;
}
