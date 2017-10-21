#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "linkedList.h"
#include "doublyLinkedList.h"

const int BITS_PER_BYTE = 8;

void assert_equals_int(int expected, int actual) {
  bool passed = (expected == actual);
  passed ? printf("PASS") : printf("FAILURE");
  printf(": expected=%d",expected);
  printf(", actual=%d",actual);
  if (!passed) {
    printf(" <------------------ FAIL");
  }
  printf("\n");
}


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

void string_examples3() {
  int result = strcmp2(NULL,"");
  assert_equals_int(-1,result);

  result = strcmp2("",NULL);
  assert_equals_int(1,result);

  result = strcmp2(NULL,NULL);
  assert_equals_int(0,result);

  result = strcmp2("","");
  assert_equals_int(0,result);

  result = strcmp2("","a");
  assert_equals_int(-1,result);

  result = strcmp2("a","");
  assert_equals_int(1,result);

  result = strcmp2("apple","bananna");
  assert_equals_int(-1,result);

  result = strcmp2("apple","apple");
  assert_equals_int(0,result);

  result = strcmp2("bananna","apple");
  assert_equals_int(1,result);

  result = strcmp2("apple","applejack");
  assert_equals_int(-1,result);

  result = strcmp2("applejack","apple");
  assert_equals_int(1,result);

  result = strcmp2("APPLE","apple");
  assert_equals_int(-1,result);

  result = strcmp2("apple","APPLE");
  assert_equals_int(1,result);

  result = strcmp2("123","124");
  assert_equals_int(-1,result);

  result = strcmp2("124","123");
  assert_equals_int(1,result);

  result = strcmp2("123","123");
  assert_equals_int(0,result);
}

void concat_examples() {
  char str1[101];
  char str2[101];
  char str3[101];
  strcpy(str1,"abc");
  strcpy(str2,"def");
  strcpy(str3,"");
  
  printf("str1 is '%s'\n",str1);
  printf("str2 is '%s'\n",str2);
  printf("str3 is '%s'\n",str3);

  char* result = strcat2(str1,"def");
  assert_equals("abcdef",result);

  strcpy(str1,"");  
  strcpy(str2,"def");  
  result = strcat2(str1,str2);
  assert_equals("def",result);

  strcpy(str1,"abc");  
  strcpy(str2,"");  
  result = strcat2(str1,str2);
  assert_equals("abc",result);

  strcpy(str1,"");  
  strcpy(str2,"");  
  result = strcat2(str1,str2);
  assert_equals("",result);

  strcpy(str1,"");  
  strcpy(str2,"");  
  result = strcat2(NULL,str2);
  assert_equals(NULL,result);

  strcpy(str1,"");  
  strcpy(str2,"");  
  result = strcat2(str1,NULL);
  assert_equals(NULL,result);

  strcpy(str1,"");  
  strcpy(str2,"");  
  result = strcat2(NULL,NULL);
  assert_equals(NULL,result);
}



/*
struct node* linked_list_examples() {
  struct node alpha;
  alpha.data = 100;
  struct node bravo;
  bravo.data = 101;
  alpha.next = &bravo;
  struct node charlie;
  charlie.data = 102;
  bravo.next = &charlie;
  charlie.next = NULL;
  
  int length = get_length(&alpha);
  assert_equals_int(3,length);
  length = get_length(&bravo);
  assert_equals_int(2,length);
  length = get_length(&charlie);
  assert_equals_int(1,length);
  length = get_length(NULL);
  assert_equals_int(0,length);

  struct node* result = get_nth(&alpha,0);
  assert_equals_int(100,result->data);
  result = get_nth(&alpha,1);
  assert_equals_int(101,result->data);
  result = get_nth(&alpha,2);
  assert_equals_int(102,result->data);
  result = get_nth(&alpha,3);
  assert_equals(NULL,result);
  result = get_nth(&alpha,10);
  assert_equals(NULL,result);
  result = get_nth(NULL,10);
  assert_equals(NULL,result);
//  printf("result->data is %d\n",result->data);
}*/







struct node* linked_list_append_data_example() {
  struct node* headPtr = NULL;
  append_data(&headPtr, 300);
  append_data(&headPtr, 301);
  append_data(&headPtr, 302);
  append_data(&headPtr, 303);
  print_list(headPtr);


  int popValue = pop(&headPtr);
  printf("Popped %d\n",popValue);
  print_list(headPtr);

  popValue = pop(&headPtr);
  printf("Popped %d\n",popValue);
  print_list(headPtr);

  popValue = pop(&headPtr);
  printf("Popped %d\n",popValue);
  print_list(headPtr);

  popValue = pop(&headPtr);
  printf("Popped %d\n",popValue);
  print_list(headPtr);

  popValue = pop(&headPtr);
  printf("Popped %d\n",popValue);
  print_list(headPtr);

  popValue = pop(NULL);

  delete_list(&headPtr);  
  print_list(headPtr);  
}





void insert_nth_examples() {
  struct node* headPtr = NULL;
  insert_nth(&headPtr, 100, 0);
  print_list(headPtr);

  insert_nth(&headPtr, 101, 0);
  print_list(headPtr);

  insert_nth(&headPtr, 102, 1);
  print_list(headPtr);

  insert_nth(&headPtr, 103, 1);
  print_list(headPtr);

  insert_nth(&headPtr, 104, 3);
  print_list(headPtr);

  insert_nth(&headPtr, 105, 5);
  print_list(headPtr);

  delete_list(&headPtr);
}




void sorted_insert_examples() {
  struct node* headPtr = NULL;

  sorted_insert(&headPtr, 105);
  print_list(headPtr);
  
  sorted_insert(&headPtr, 102);
  print_list(headPtr);

  sorted_insert(&headPtr, 103);
  print_list(headPtr);

  sorted_insert(&headPtr, 106);
  print_list(headPtr);

  sorted_insert(&headPtr, 100);
  print_list(headPtr);

  sorted_insert(&headPtr, 101);
  print_list(headPtr);

  sorted_insert(&headPtr, 104);
  print_list(headPtr);

  sorted_insert(&headPtr, 107);
  print_list(headPtr);

  delete_list(&headPtr);
}


void reverse_examples() {
  struct node* list1Ptr = NULL;
  int i = 0;
  for (i; i < 5; i+=1) {
      append_data(&list1Ptr,100+i);      
  }

  printf("list 1: ");
  print_list(list1Ptr);

  struct node* list2Ptr;
  list2Ptr = reverse(list1Ptr);

  printf("list 2 is: ");
  print_list(list2Ptr);


  delete_list(&list2Ptr);
}

void doubly_linked_list_examples() {
  printf("Testing doubly linked lists\n");
  struct node2LL* list1Ptr = NULL;
  int i=0;
  for (i; i<10; i+=1) {
    append_data2LL(&list1Ptr,100+i);
  }
  there_and_back_again2LL(list1Ptr);

  delete_node2LL(&list1Ptr,105);
  
  printf("After delete\n");
  there_and_back_again2LL(list1Ptr);
  delete_list2LL(&list1Ptr);
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
            if (j%4==0) {
              printf(" ");
            }
        }
    }
    puts("");
}

int get_nth_bit(int num, int n) {
  int checkBit = 1 << n;
  int result = num & checkBit;
  return result == checkBit ? 1 : 0;
}

int set_nth_bit_to_1(int num, int n) {
  int checkBit = 1 << n;
  return num | checkBit;
}

int set_nth_bit_to_0(int num, int n) {
  int checkBit = 1 << n;
  return num & ~checkBit;
}

void print_bits(int input) {
  int numOfBits = sizeof(input) * 8;
  int i=numOfBits - 1;
  // checkBit must be unsighted so that right shifts 
  // do not cause 1's to be filled in from the right
  unsigned int checkBit = 1 << (numOfBits - 1);

  for (i; i >=0; i--) {
    int temp = input & checkBit;
    if (temp == checkBit) {
      printf("1");
    } else {
      printf("0");
    }
    if (i%4==0) {
      printf(" ");
    }
    checkBit = checkBit >> 1;
  }
  printf("\n");
}

int count_1s_unoptimized(int input) {
  int numOfBits = sizeof(input) * BITS_PER_BYTE;
  unsigned int checkBit = 1 << (numOfBits - 1);
  int numOfOneBits = 0;
  while (checkBit > 0) {
    int temp = input & checkBit;
    if (temp == checkBit) {
      numOfOneBits++;
    }
    checkBit = checkBit >> 1;
  }
  return numOfOneBits;
}

int count_1s_optimized(int num) {
  int counter = 0;
  while (num != 0) {
    num = num & (num - 1);
    counter++;
  }
  return counter;
}

int reverse_bits(int num) {
  int numOfBits = sizeof(num) * 8;
  int result = 0;
  int i;
  for (i=0; i<numOfBits; i++) {
    int bit = get_nth_bit(num, i);
    int resultBitIndex = numOfBits-i-1;
    if (bit == 0) {
      result = set_nth_bit_to_0(result, resultBitIndex);
    } else {
      result = set_nth_bit_to_1(result, resultBitIndex);
    }
  }
  return result;
}

int reverse_bits2(int num) {
  int bitsLeftToShift = sizeof(num) * BITS_PER_BYTE;
  int result = 0;
  int i;
  while (num != 0) {
    int least_sig_input_bit = num & 1;
    result = result | 1;
    num >> 1;
    result << 1;
    bitsLeftToShift--;
  }
  result << bitsLeftToShift;
  return result;
}

void bit_examples() {
  int input = 0x8000E0FE;//0x7E5C3B1A;
  printf("input: ");
  printBits(sizeof(input),&input);

  int result = reverse_bits(input);
  printf("result from method 1: ");
  printBits(sizeof(result),&result);

  int result2 = reverse_bits(input);
  printf("result from method 2: ");
  printBits(sizeof(result2),&result2);

  printf("Making sure the input hasn't changed\n");
  printf("input: ");
  printBits(sizeof(input),&input);
  //TODO check that the input hasn't been modified;
}

int main(void)
{
  printf("\n\n\n");
  //basic();
  //arrays();
  //string_examples();
  //string_examples2();
  //string_examples3();
  //concat_examples();
  //linked_list_examples();
  //linked_list_append_data_example();
  //insert_nth_examples();
  //sorted_insert_examples();
  //reverse_examples();
  //doubly_linked_list_examples();
  bit_examples();
  printf("\n\n");
  return 0;
}
