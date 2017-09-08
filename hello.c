#include <stdio.h>
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

int main(void)
{
  printf("\n\n\n");
  //basic();
  arrays();
  return 0;
}
