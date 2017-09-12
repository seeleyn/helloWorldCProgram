#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h> //for size_t
#include <stdbool.h>

int sum(int first, int second);

int difference(int first, int second);

size_t strlen2(const char* str);

char* strchr2(const char* str, int c);


char* strstr2(const char* haystack, const char* needle);

bool starts_with(const char* str, const char* substr);

char* strstr3(const char* haystack, const char* needle);

int strcmp2(const char* str1, const char* str2);

#endif
