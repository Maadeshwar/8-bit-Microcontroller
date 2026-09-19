; Full SoC Code Coverage Firmware

init:
    ; 1. RAM / LDI / STR Tests
    LDI 0x01
    STR 0x00      ; RAM[0] = 1 (Constant 1)
    LDI 0x02
    STR 0x01      ; RAM[1] = 2 (Constant 2 for TX mask)
    LDI 0x00
    STR 0x02      ; RAM[2] = 0 (Scratchpad)

    ; 2. Baud Rate Config (Coverage for 0x28, 0x29)
    LDI 0x05      ; Very fast baud for simulation (5 cycles)
    STR 0x28
    LDI 0x00
    STR 0x29

    ; 3. GPIO Config (Coverage for 0x21)
    LDI 0x0F      ; lower 4 bits output, highest bit input
    STR 0x21

    ; 4. PWM Config (Coverage for 0x26)
    LDI 0x80      ; 50% duty cycle (8-bit)
    STR 0x26

    ; 5. Timer Config (Coverage for 0x22)
    STR 0x22      ; Clear timer

    ; 6. ALU & Flags Coverage (ADD, SUB, AND, OR, XOR, SHL, SHR, JC, JZ, JNZ)
    LDI 0xFF      ; Load 255
    ADD 0x00      ; Add 1 (RAM[0]). 255 + 1 = 256 (0) -> Carry=1, Zero=1
    JC carry_ok   ; Should jump because Carry=1
    JMP 0xF0      ; FAIL1
carry_ok:
    JZ zero_ok    ; Should jump because Zero=1
    JMP 0xF1      ; FAIL2
zero_ok:
    
    LDI 0x05
    SUB 0x00      ; 5 - 1 = 4. Zero=0, Carry=0
    JNZ sub_ok    ; Should jump because Zero=0
    JMP 0xF2      ; FAIL3
sub_ok:

    ; Logic operations
    LDI 0xAA      
    STR 0x03      ; RAM[3] = 0xAA (10101010)
    LDI 0x55
    AND 0x03      ; 0x55 AND 0xAA = 0x00 -> Zero=1
    JZ and_ok
    JMP 0xF3      ; FAIL4
and_ok:

    LDI 0x55
    OR 0x03       ; 0x55 OR 0xAA = 0xFF
    STR 0x04      ; RAM[4] = 0xFF
    XOR 0x04      ; 0xFF XOR 0xFF = 0x00
    JZ xor_ok
    JMP 0xF4      ; FAIL5
xor_ok:

    LDI 0x01
    STR 0x05      ; RAM[5] = 1
    LDI 0x10      ; 16
    SHR 0x05      ; 16 >> 1 = 8
    SHL 0x05      ; 8 << 1 = 16
    STR 0x02      ; RAM[2] = 16

    ; 7. NOP coverage
    NOP
    NOP

    ; 8. CALL / RET coverage
    CALL sub_rtn
    
    ; 9. UART TX Coverage
    LDI 0x41      ; 'A'
    STR 0x24      ; TX

wait_tx:
    LDR 0x25      ; STATUS
    AND 0x01      ; RAM[1]
    JNZ wait_tx

    ; 10. UART RX Coverage
wait_rx:
    LDR 0x25
    AND 0x00      ; RAM[0]
    JZ wait_rx

    LDR 0x23      ; Read RX Data
    STR 0x20      ; Write RX Data to GPIO Out (Coverage for 0x20)
    
    ; Read GPIO In
    LDR 0x20      ; Read GPIO In

freeze:
    JMP freeze

sub_rtn:
    RET

fail:
    JMP 0xFF      ; Generic fail
