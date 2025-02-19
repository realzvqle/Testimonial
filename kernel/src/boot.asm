.global KiKernelLoaderEntry
KiKernelLoaderEntry:
    ldr x30, =stack_beginning
    mov sp, x30
    bl KiEntry
    b .