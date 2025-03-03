#ifndef RUNTIMELIB_H_INCLUDED
#define RUNTIMELIB_H_INCLUDED






#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

typedef struct _version{
    uint8_t osver;
    uint16_t kver;
    char* type;
} version;

char* RtlStringConcatnate(char* destination, const char* source);
char* RtlIntegerToAscii(int num, char* str);
double RtlFabs(double x);
double RtlPow(double base, int exp);
float RtlSin(float x);
float RtlCos(float x);
void RtlSliceStrings(const char* sourcestring, char delimiter, char* firststring, char* secondstring, size_t firstsize, size_t secondsize);
bool RtlStringCompare(char* first_string, char* second_string);
version RtlGetCurrentVersion();
int RtlAsciiToInteger(const char *str);
void RtlUartPrintUnsigned64Integer(char* prev, uint64_t integer);
size_t RtlGetStringLength(const char *str);
#endif