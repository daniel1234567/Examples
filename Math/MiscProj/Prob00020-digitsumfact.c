#include <stdio.h>

#define SIZE 158
char f100[158] = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";

void
main (){

  int i, res = 0;

  for(i=0; i<SIZE; i++)
    res += (int) (f100[i] - '0');

  printf("Solution is %d", res );
}
