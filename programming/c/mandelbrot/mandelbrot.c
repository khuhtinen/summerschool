#include <stdio.h>
#include <stdlib.h>

#define NX 100
#define NY 100

typedef struct {
  double real;
  double imag;
} complex; 


void square(complex * z) {
  
  complex res;
  res.real = z->real*z->real - z->imag*z->imag;
  res.imag = 2*z->real*z->imag;

  z->real = res.real;
  z->imag = res.imag;
}

void add(complex * z, complex * c) {
  
  z->real += c->real;
  z->imag += c->imag;

}

/*
  Computes the N:th iterate of 0 for the polynomial z^2+c.
 */
void iterate(complex *c, int N) {

  int i;
  complex z;
  z.real = 0.0;
  z.imag = 0.0;

  for(i=0; i<N; i++) {
    square(&z);
    add(&z,c);
  }

  c->real = z.real;
  c->imag = z.imag;

}

double norm(complex *z) {
  return (z->real)*(z->real) + (z->imag)*(z->imag);
}

/*
  Produce table approximating the Mandelbrot set
 */
void write_table(double array[NX][NY]) {

  complex c;
  c.real = 0.0;
  c.imag = 0.0;


  int i,j;
  double x = -2.0;
  double y;

  for(i=0;i<NX;i++) {
    y = -2.0;
    for(j=0;j<NY;j++) {
      c.real = x;
      c.imag = y;

      iterate(&c,100);

      if(isnan(norm(&c))) {
	array[i][j] = 0.0;
      } else {
	array[i][j] = 100.0;
      }

      y+= 4.0/((double) NY);
    }
    x+= 4.0/((double) NX);
  }

}

void draw_result(double array[NX][NY]) {
  
  int error_code;

  // Call the png writer routine
  error_code = save_png((double *) array, NX, NY, "mandelbrot_set.png",'c');

  if (error_code == 0) {
        printf("Wrote the output file mandelbrot_set.png\n");
    } else {
        printf("Error while writing output file mandelbrot_set.png\n");
    }

}


int main() {
  
  double array[NX][NY];
  int i,j;

  write_table(array);
  draw_result(array);

  return 0;
}
