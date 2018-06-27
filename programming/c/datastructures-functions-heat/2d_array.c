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

    for(i=0;i<NX;i++) {
      for(j=0;j<NY;j++) {
	if(i==0) {
	  array[i][j] = 85.0; //Upper boundary
	}
	else if(i==NX-1) {
	  array[i][j] = 5.0; //Lower boundary
	}
	else if(j==0) {
	  array[i][j] = 20.0; //Left boundary
	}
	else if(j==NY-1) {
	  array[i][j] = 70.0; //Right boundary
	}
	else {
	  array[i][j] = 0.0;
	}
      }
    }

    // Initialize first the zeros
#error Initialize the zeros for interior

    // Initial conditions for left and right
#error add boundary conditions for left and right

    // and top and bottom boundaries
#error add boundary conditions for top and bottom

    return 0;
}
