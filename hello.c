#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


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

struct node {
  int data;
  struct node* next;
};

int get_length(struct node* head) {
  if (head == NULL) {
    return 0;
  }
  int length = 0;
  struct node* current = head;
  while (current != NULL) {
    current = current->next;
    length++;
  }
  return length;
}

struct node* get_nth(struct node* head, int n) {
  if (head == NULL || n<0) {
    return NULL;
  }
  int current_index = 0;
  struct node* current = head;
  while (current_index < n) {
    if (current == NULL) {
      return NULL;
    }
    current = current->next;
    current_index++;
  }
  return current;
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

void print_list(struct node* head) {
  struct node* current = head;
  int index = 0;
  while (current != NULL) {
    printf("{%d:%d} -> ",index,current->data);
    current = current -> next;
    index++;
  }
  printf("NULL\n");
}

void delete_list(struct node** headPtrPtr) {
  if (headPtrPtr == NULL) {
    return;
  }
  struct node* currentPtr = *headPtrPtr;
  struct node* nextPtr = NULL;
  while (currentPtr != NULL) {
    nextPtr = currentPtr->next;
    currentPtr->next = NULL;
    free(currentPtr);
    currentPtr = nextPtr;
  }
  *headPtrPtr = NULL;
}

void append_data(struct node** headRef, int data) {
  if (headRef==NULL) {
    return;
  }
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (*headRef == NULL) {
    *headRef = newNode;
  } else {
    struct node* current = *headRef;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

int pop(struct node** headPtrPtr) {
  if (headPtrPtr == NULL) {
    printf("Error: Cannot pop list because headPtrPtr is NULL\n");
    return 0;
  }
  struct node* headPtr = *headPtrPtr;
  if (headPtr == NULL) {
      printf("Error: Cannot pop list because list is empty\n");
      return 0;
  }
  struct node* newHeadPtr = headPtr->next;
  int data = headPtr->data;
  *headPtrPtr = newHeadPtr;
  headPtr->next = NULL;
  free(headPtr);
  return data;
}


struct node* linked_list_append_data_example() {
  struct node* headPtr = NULL;
  append_data(&headPtr, 300);
  append_data(&headPtr, 301);
  append_data(&headPtr, 302);
  append_data(&headPtr, 303);
  print_list(headPtr);

/*
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
*/
  delete_list(&headPtr);  
  print_list(headPtr);  
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
  linked_list_append_data_example();
  printf("\n\n");
  return 0;
}
