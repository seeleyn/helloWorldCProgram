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
  int arr[4] = {1, 2, 3, 4};
  printf("arr[0] is %d\n",arr[0]);
  printf("arr[1] is %d\n",arr[1]);
  printf("arr[2] is %d\n",arr[2]);
  printf("arr[3] is %d\n",arr[3]);

  int *intPtr = arr;
  int i=0;
  for (i=0; i<4; i++) {
    printf("intPtr[%d] is %d\n",i,*intPtr);
    intPtr++;
  }
}

int main(void)
{
  printf("\n\n\n");
  //basic();
  arrays();
  return 0;
}
