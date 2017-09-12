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


char* strstr2(const char* haystack, const char* needle) {
  if (haystack == NULL || needle == NULL) {
    return NULL;
  }
  while (haystack[0] != '\0') {
    if (haystack[0] == needle[0]) {
      const char* h = haystack;
      const char* n = needle;
      while (h[0] == n[0] && n[0] != '\0') {
        h++;
        n++;
      }
      if (n[0] == '\0') {
        return (char*) haystack;
      }
    }
    haystack++;
  }
  return NULL;
}


bool starts_with(const char* str, const char* substr) {
  if (str==NULL || substr==NULL) {
    return false;
  }
  while (str[0] == substr[0] && str[0] != '\0') {
    str++;
    substr++;
  }
  return (substr[0] == '\0');
}


char* strstr3(const char* haystack, const char* needle) {
  if (haystack==NULL || needle==NULL) {
    return NULL;
  }
  if (needle[0] == '\0') return (char*)haystack;
  while (haystack[0] != '\0') {
    if (starts_with(haystack,needle)) {
      return (char*) haystack;
    }
    haystack++;
  }
  return NULL;
}

int strcmp2(const char* str1, const char* str2) {
  if (str1 == NULL || str2 == NULL) {
    return 0; //TODO Figure out what to do here
  }
  while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0') {
    str1++;
    str2++;
  }
  if (*str1 == '\0' && *str2 == '\0') {
    return 0;
  } else if (*str1 == '\0' && *str2 != '\0') {
    return -1;
  } else if (*str1 != '\0' && *str2 == '\0') {
    return 1;
  } else {
    return (*str1 < *str2) ? -1 : 1;
  }
}







































