#include "functions.h"

int sum(int first, int second) {
   return first + second;
}

int difference(int first, int second) {
   return first - second;
}

size_t strlen2(const char* str) {
  if (str == NULL) {
    return 0;
  }
  int length = 0;
  const char* tmpPtr = str;
  while (*tmpPtr != '\0') {
    length++;
    tmpPtr++;
  }
  return length;
}



char* strchr2(const char* str, int c) {
  if (str==NULL) {
    return NULL;
  }
  const char* charPtr = str;
  while (*charPtr != '\0') {
    if (*charPtr == c) {
      return (char*) charPtr;
    }
    charPtr++;
  }
}
















































