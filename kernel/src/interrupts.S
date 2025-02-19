.global KiTestAsmCIntergration 
.global KiInterrupt
.global KiVectorTable


// KiTestAsmCIntergration:
//     stp x29, x30, [sp, #-16]!  
//     ldr x0, =message
//     bl KiUartPrint
//     ldp x29, x30, [sp], #16 
//     ret






KiInterrupt:
    stp x29, x30, [sp, #-16]!  
    adr x0, KiVectorTable
    msr VBAR_EL1, x0
    ldp x29, x30, [sp], #16 
    ret

KiVectorTable:
    b .
.balign 0x80
    b KiExceptionEntry
.balign 0x80
    b .
.balign 0x80
    b .
.balign 0x80
    b KiExceptionEntry

KiExceptionEntry:
    sub sp, sp, #192
    stp x0, x1, [sp, #0]
    stp x2, x3, [sp, #16]
    stp x4, x5, [sp, #32]
    stp x6, x7, [sp, #48]
    stp x8, x9, [sp, #64]
    stp x10, x11, [sp, #80]
    stp x12, x13, [sp, #96]
    stp x14, x15, [sp, #112]
    stp x16, x17, [sp, #128]
    stp x18, x29, [sp, #144]
    stp x30, xzr, [sp, #160]

    mrs x0, ESR_EL1
    mrs x1, FAR_EL1
    stp x0, x1, [sp, #176]
    mov x0, sp
    bl KiExceptionHandler
    
    ldp x0, x1, [sp, #0]
    ldp x2, x3, [sp, #16]
    ldp x4, x5, [sp, #32]
    ldp x6, x7, [sp, #48]
    ldp x8, x9, [sp, #64]
    ldp x10, x11, [sp, #80]
    ldp x12, x13, [sp, #96]
    ldp x14, x15, [sp, #112]
    ldp x16, x17, [sp, #128]
    ldp x18, x29, [sp, #144]
    ldp x30, xzr, [sp, #160]
    add sp, sp, #192
    eret




// message:
//     .asciz "ASM - C Intergration Successful!\n"
