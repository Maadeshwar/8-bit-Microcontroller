<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## How it works

TinySoC is a custom 8-bit Harvard Architecture microcontroller explicitly designed to fit inside a 1x1 Tiny Tapeout tile (which provides precisely 24 user IO pins: 8 inputs, 8 outputs, and 8 bidirectionals).

The architecture features:
- **Harvard Architecture**: Fetches instructions from an external ROM asynchronously via dedicated `ui` (Instruction In) and `uo` (Program Counter Out) pins.
- **8-bit Instruction Set**: A compact 8-instruction ISA supporting `NOP`, `LDI`, `LDR`, `STR`, `ADD`, `SUB`, `JMP`, and `JZ`.
- **16-byte Internal RAM**: For scratchpad memory and variables (Mapped to `0x00 - 0x0F`).
- **Memory-Mapped Peripherals**:
  - `0x10`: GPIO Data Direction Register (DDR)
  - `0x11`: GPIO Output Register (PORT)
  - `0x12`: GPIO Input Register (PIN)
  - `0x14`: UART TX Data Register (Write to trigger TX)
  - `0x15`: UART RX Data Register (Read for RX data)
  - `0x16`: Hardware Timer Compare Match Register

## How to test

Connect a Parallel ROM or an external microcontroller (like an RP2040/ESP32 acting as an instruction emulator) to the 8 input and 8 output pins. The TinySoC will immediately begin executing instructions starting from address `0x00`. 
Interact with the memory-mapped GPIO pins or send/receive UART signals via the bidirectional `uio` pins.

## External hardware

- Parallel Instruction ROM (or Microcontroller to emulate it)
- USB-to-UART bridge (optional, for serial communication)
