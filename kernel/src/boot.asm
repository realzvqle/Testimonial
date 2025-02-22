.global KiKernelLoaderEntry




KiKernelLoaderEntry:
    ldr x30, =stack_beginning
    mov sp, x30
    ldr x0, =bootmessage
    bl KiUartPrint
    bl KiInterrupt
    bl KiEntry
    b .


bootmessage:
    .asciz "Loading System.........\n"