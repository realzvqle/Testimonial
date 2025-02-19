.global KiKernelLoaderEntry




KiKernelLoaderEntry:
    ldr x30, =stack_beginning
    mov sp, x30
    // mrs x0, CurrentEl
    // cmp x0, #0b1000
    // beq in_el2
    // blo in_el1
    ldr x0, =bootmessage
    bl KiUartPrint
    bl KiInterrupt
    //bl KiTestAsmCIntergration
    bl KiEntry
    b .

in_el1:
    ldr x0, =bootmessage
    bl KiUartPrint
    b .

in_el2:
    //ldr x0, =bootmessage
    //bl KiUartPrint
    b .



bootmessage:
    .asciz "Loading System.........\n"