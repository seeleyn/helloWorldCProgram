#include <stdio.h>
#include <string.h>
#include "functions.h"


void basic() {
  int radius=25;
  int *radiusPtr = &radius;
  int *otherRadiusPtr = radiusPtr;
  printf("radiusPtr points to %d\n",*radiusPtr);
  printf("otherRadiusPtr points to %d\n",*otherRadiusPtr);
  printf("*&radius %d\n",*&radius);

  //printf("radiusPtr stores address      %u\n",radiusPtr);
  //printf("otherRadiusPtr stores address %u\n",otherRadiusPtr);
}


void arrays() {
  //basic array example
  int arr[4] = {100, 200, 300, 400};
  printf("arr[0] is %d\n",arr[0]);
  printf("arr[1] is %d\n",arr[1]);
  printf("arr[2] is %d\n",arr[2]);
  printf("arr[3] is %d\n",arr[3]);

  //example of using ++ to increment a pointer
  int *intPtr = arr;
  int i=0;
  for (i=0; i<4; i++) {
    printf("intPtr[%d] is %d\n",i,*intPtr);
    intPtr++;
  }

  //example of pointer arithmetic
  int *tmpPtr = arr;
  printf("*(tmpPtr)   is %d\n",*(tmpPtr));
  printf("*(tmpPtr+1) is %d\n",*(tmpPtr+1));
  printf("*(tmpPtr+2) is %d\n",*(tmpPtr+2));
  printf("*(tmpPtr+3) is %d\n",*(tmpPtr+3));
}

void safePrintln(const char* input) {
  if (input != NULL) {
      printf("'%s'\n",input);
  } else {
    printf("NULL\n");
  }
}

void string_examples() {
  char* str = "hello world?\n";
  printf("%s",str);
  int len = strlen(str);
  printf("strlen(str) returned  %d\n",len);
  int len2 = strlen2(str);
  printf("strlen2(str) returned %d\n\n\n",len);
  

  char* haystack = "abcdefghijklmnopqrstuvwxyz";
  char needle = 't';
  char* locationPtr = strchr(haystack,needle);
  char* locationPtr2 = strchr2(haystack,needle);
  printf("strchr found %s\n",locationPtr);
  printf("strchr2 found %s\n",locationPtr2);

  char* locationPtr4 = strchr2(NULL,needle);
  printf("strchr2 found ");
  safePrintln(locationPtr4);

  char* locationPtr5 = strchr2(haystack,'A');
  printf("strchr2 found ");
  safePrintln(locationPtr5);
  
}

void string_examples2() {

  char* result = strstr2(NULL,NULL);
  printf("strstr2: expect NULL found ");
  safePrintln(result);

  result = strstr2("",NULL);
  printf("strstr2: expect NULL found ");
  safePrintln(result);

  result = strstr2(NULL,"");
  printf("strstr2: expect NULL found ");
  safePrintln(result);

//  result = strstr2("","");
//  printf("strstr2: expect '' found "); //this is a special case
//  safePrintln(result);

  result = strstr2("abc def","abc");
  printf("strstr2: expect 'abc def' found ");
  safePrintln(result);

  result = strstr2("abc def","c d");
  printf("strstr2: expect 'c def' found ");
  safePrintln(result);

  result = strstr2("abc def","def");
  printf("strstr2: expect 'def' found ");
  safePrintln(result);

  result = strstr2("abc def","efg");
  printf("strstr2: expect NULL found ");
  safePrintln(result);
}

int main(void)
{
  printf("\n\n\n");
  //basic();
  //arrays();
  //string_examples();
  string_examples2();
  printf("\n\n");
  return 0;
}
