#include <stdio.h>
#include "functions.h"



void basic() {
  int radius=25;
  int *radiusPtr = &radius;
  int *otherRadiusPtr = radiusPtr;
  printf("radiusPtr points to %d\n",*radiusPtr);
  printf("otherRadiusPtr points to %d\n",*otherRadiusPtr);
  printf("*&radius %d\n",*&radius);

  printf("radiusPtr stores address      %u\n",radiusPtr);
  printf("otherRadiusPtr stores address %u\n",otherRadiusPtr);
}

int main(void)
{
  printf("\n\n\n");
  basic();
  return 0;
}
