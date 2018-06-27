#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define NX 258
#define NY 258

typedef struct {
  int nx;
  int ny;
  double dx;
  double dy;
  double dx2;
  double dy2;
  double data[NX+2][NY+2];
} field;

void init_field(field * f, int nx, int ny, double dx, double dy) {

  f->nx = nx;
  f->ny = ny;
  f->dx = dx;
  f->dy = dy;
  f->dx2 = dx*dx;
  f->dy2 = dy*dy;

  int i,j;
  for(i = 1; i<nx+1; i++) {
    for(j = 1; j<ny+1; j++) {
      f->data[i][j] = 0.0;
    }
  }

  //Boundary values
  for(i=0; i<nx+2; i++) {
    f->data[i][0] = 85.0;
    f->data[i][ny+1] = 70.0;
  }

  for(i=0; i<ny+2; i++) {
    f->data[0][i] = 20.0;
    f->data[nx+1][0] = 70.0;
  }

}

int main() {

  return 0;

}
