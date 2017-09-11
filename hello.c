#include <stdio.h>
#include <string.h>
#include "functions.h"


void assert_equals(const char* expected, const char* actual) {
  int expected_is_null = (expected == NULL) ? 1 : 0;
  int actual_is_null = (actual == NULL) ? 1 : 0;
  int passed = 0;

  if (expected_is_null || actual_is_null) {
    passed = (expected_is_null && actual_is_null) ? 1 : 0;
  } else {
    passed = (strcmp(expected,actual) == 0) ? 1 : 0;
  }
  passed ? printf("PASS") : printf("FAILURE");
  printf(": expected=");
  expected_is_null ? printf("NULL") : printf("'%s'",expected);
  printf(", actual=");
  actual_is_null ? printf("NULL") : printf("'%s'",actual);
  if (!passed) {
    printf(" <------------------ FAIL");
  }
  printf("\n");
}

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

void safe_println(const char* input) {
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
  safe_println(locationPtr4);

  char* locationPtr5 = strchr2(haystack,'A');
  printf("strchr2 found ");
  safe_println(locationPtr5);
  
}

void string_examples2() {

  char* result = strstr3(NULL,NULL);
  assert_equals(NULL, result);

  result = strstr3("",NULL);
  assert_equals(NULL, result);

  result = strstr3(NULL,"");
  assert_equals(NULL, result);

  result = strstr3("","");
  assert_equals("", result);

  result = strstr3("abc def","");
  assert_equals("abc def", result);

  result = strstr3("abc def","abc");
  assert_equals("abc def",result);
  
  result = strstr3("abc def","def");
  assert_equals("def",result);

  result = strstr3("abc def","c d");
  assert_equals("c def",result);

  result = strstr3("abc def","efg");
  assert_equals(NULL,result);
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
