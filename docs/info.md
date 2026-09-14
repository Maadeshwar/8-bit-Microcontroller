<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## How it works

TinySoC is an ultra-compact, high-efficiency 8-bit Harvard Architecture microcontroller designed to fit securely inside a 1x1 Tiny Tapeout tile. It executes instructions out of an external ROM or memory emulator connected to the input pins, while handling internal data through its onboard 8-byte RAM and memory-mapped peripheral registers.

### The Pipeline
The CPU operates on a strict 3-stage State Machine:
1. **FETCH:** The Program Counter (PC) is outputted on the `uo_out` pins. The external memory responds instantly with an opcode on the `ui_in` pins, which is latched into the internal Instruction Register (IR).
2. **FETCH_OP:** For multi-byte instructions, the PC is incremented and the second byte (the operand) is latched from `ui_in`.
3. **EXEC:** The CPU executes the instruction, manipulating the Accumulator (ACC) or writing to internal RAM / Peripherals.

### Peripheral Architecture
To maximize silicon area, all peripherals are accessed via **Memory-Mapped I/O** rather than dedicated instructions.
* **UART:** A hardware UART transmitter and receiver hardcoded for 115200 baud at a 50 MHz clock (Clock Divider = 434). Writing to address `0x24` automatically latches the byte and shifts it out of `uio_out[5]`.
* **PWM:** An 8-bit free-running hardware timer constantly compares against the `PWM Duty` register at `0x26`. The result natively drives `uio_out[7]`.
* **GPIO:** A 5-bit array where direction and output states are explicitly controlled by registers `0x21` and `0x20`, mapping physically to `uio_out[4:0]`.
* **Watchdog Timer (WDT):** A 16-bit safety timer that will pull the chip into an internal soft reset state if the upper counter hits `0xFF` without being cleared by the software.

## How to test

Because this is a Harvard Architecture design with 0-cycle fetch latency, testing physically requires consideration of the external memory response time.

1. **High-Speed Execution (50 MHz):** Connect a fast parallel SRAM or ROM chip (with an access latency of <15ns) to the PMOD headers of the Tiny Tapeout demo board. The CPU will output the 8-bit address on the `uo_out` pins, and the ROM must return the instruction on the `ui_in` pins before the next clock edge. At 50 MHz, the UART will run at exactly 115200 baud.
2. **Emulated Execution (1 MHz or less):** If you are using the RP2040 on the Tiny Tapeout demo board to emulate the ROM using MicroPython or C, you must lower the system clock. The RP2040 firmware must read the GPIO pins, look up the firmware array, and write to the GPIO pins. This cannot happen in 20ns. Clock the project at 1 MHz. Note that your UART baud rate will scale proportionally (e.g., 1,000,000 / 434 = ~2304 baud).

### Pin Mapping Overview

* `ui[7:0]` - Instruction Bus (Input from ROM)
* `uo[7:0]` - Program Counter (Output to ROM address lines)
* `uio[4:0]` - GPIO Array (Bidirectional)
* `uio[5]` - UART TX
* `uio[6]` - UART RX
* `uio[7]` - PWM Output

## External hardware

To run this chip at maximum frequency, a high-speed parallel ROM or SRAM chip (e.g., 74-series logic or dedicated EEPROM) is required to be wired to the input and output PMOD headers. For low-speed execution, the standard Tiny Tapeout RP2040 Demo Board is perfectly sufficient.
