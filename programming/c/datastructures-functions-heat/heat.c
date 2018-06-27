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

void init_field(field * f, double dx, double dy) {

  f->nx = NX;
  f->ny = NY;
  f->dx = dx;
  f->dy = dy;
  f->dx2 = dx*dx;
  f->dy2 = dy*dy;

  int i,j;
  for(i = 1; i<NX+1; i++) {
    for(j = 1; j<NY+1; j++) {
      f->data[i][j] = 0.0;
    }
  }

  //Boundary values
  for(i=0; i<NX+2; i++) {
    f->data[i][0] = 85.0;
    f->data[i][NY+1] = 70.0;
  }

  for(i=0; i<NY+2; i++) {
    f->data[0][i] = 20.0;
    f->data[NX+1][i] = 70.0;
  }

}

void do_laplacian(field * f) {
  
  int i,j;

  double laplace[f->nx+2][f->ny+2];
  
  for (i = 0; i<f->nx+2; i++) {
    laplace[i][0] = laplace[i][f->ny+1] = 0.0;
  }

  for (i = 0; i<f->ny+2; i++) {
    laplace[0][i] = laplace[f->nx+1][i] = 0.0;
  }

  for (i = 1; i<f->nx+1; i++) {
    for (j = 1; j<f->ny+1; j++) {
      laplace[i][j] = 
	  (f->data[i-1][j] - 2*f->data[i][j] + f->data[i+1][j])/(f->dx2)
	  +(f->data[i][j-1] - 2*f->data[i][j] + f->data[i][j+1])/(f->dy2);
    }
  }

  for (i = 0; i<f->nx+2; i++) {
    for(j = 0; j<f->ny+2; j++) {
      f->data[i][j] = laplace[i][j];
    }
  }

}

void draw_result(field * f) {
  
  int error_code;
  
  // Call the png writer routine
  error_code = save_png((double *) f->data, NX+2, NY+2, "datastructures_functions_heat-a_b.png", 'c');

  if (error_code == 0) {
    printf("Wrote the output file datastructures_functions_heat-a_b.png\n");
  } else {
    printf("Error while writing output file datastructures_functions_heat-a_b.png\n");
  }

}

int main() {

  field f;
  
  init_field(&f, 0.01, 0.01);
  do_laplacian(&f);  
  draw_result(&f);

  return 0;

}
