#ifndef RTL_H_INCLUDED
#define RTL_H_INCLUDED





#include "../superheader.h"


char* RtlStringConcatenate(char* destination, const char* source);
char* RtlIntegerToAsciiString(int num, char* str);
double RtlFabs(double x);
double RtlPow(double base, int exp);
float RtlSin(float x);
float RtlCos(float x);
void RtlSliceStrings(const char* sourcestring, char delimiter, char* firststring, char* secondstring, size_t firstsize, size_t secondsize);
bool RtlStringCompare(char* first_string, char* second_string);

#endif