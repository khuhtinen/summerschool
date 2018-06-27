#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
    float array[NX][NY];

    // Initialize first the zeros
    for(i = 0; i<NX; i++) {
      for(j = 0; j<NY; j++) {
	array[i][j] = 0;
      }
    }

    // Initial conditions for left and right
    for(i = 1; i<NX-1; i++) {
      array[i][0] = 20.0; //Left
      array[i][NY-1] = 70.0; //Right
    }

    // and top and bottom boundaries
    for(i = 1; i<NY-1; i++) {
      array[0][i] = 85.0; //Upper
      array[NX-1][i] = 5.0; //Lower
    }

    return 0;
}
