#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED













void KiUartPutChar(char c);
void KiUartPrint(const char *s);
char KiUartGetChar();
char KiUartGetCharNonWait();
void KiUartPrintF(char *format);
void KiDebugUartPrint(const char *s);





#endif