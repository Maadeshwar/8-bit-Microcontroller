; TinySoC Demo Application
; Demonstrates configuring UART baud rate, printing "Hi", and pulsing PWM.

init:
    ; 1. Setup Constants in RAM
    LDI 0x01
    STR 0x00    ; RAM[0] = 0x01 (Constant 1 for adding/delay)
    
    LDI 0x02
    STR 0x01    ; RAM[1] = 0x02 (Mask for tx_busy bit 1)
    
    LDI 0x00
    STR 0x02    ; RAM[2] = 0x00 (PWM brightness state)

    ; 2. Configure UART for 115200 baud at 50MHz (Divider = 434 = 0x01B2)
    LDI 0xB2    
    STR 0x28    ; BAUD_DIV_L
    LDI 0x01    
    STR 0x29    ; BAUD_DIV_H

    ; 3. Print 'H'
    LDI 0x48    ; 'H'
    STR 0x24    ; TX
wait_h:
    LDR 0x25    ; Read UART_STATUS
    AND 0x01    ; AND with RAM[1] (0x02) to isolate tx_busy
    JNZ wait_h  ; Loop if busy

    ; 4. Print 'i'
    LDI 0x69    ; 'i'
    STR 0x24    ; TX
wait_i:
    LDR 0x25    ; Read UART_STATUS
    AND 0x01    ; AND with RAM[1] (0x02)
    JNZ wait_i

main_loop:
    ; Increment brightness
    LDR 0x02    ; Load RAM[2] (brightness)
    ADD 0x00    ; Add RAM[0] (1)
    STR 0x02    ; Store back to RAM[2]
    STR 0x26    ; Update PWM duty cycle

    ; Delay
    CALL delay
    

    JMP main_loop

delay:
    LDI 0xFF    ; Load 255
delay_loop:
    SUB 0x00    ; Subtract RAM[0] (1)
    JNZ delay_loop
    RET
