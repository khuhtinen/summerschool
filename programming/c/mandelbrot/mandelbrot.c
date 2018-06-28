#include <stdio.h>
#include <stdlib.h>

#define NX 10
#define NY 10

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
void write_table(int array[NX][NY]) {

  complex c;
  c.real = 0.0;
  c.imag = 0.0;


  int i,j;
  double x = -2.0;
  double y = -2.0;

  for(i=0;i<NX;i++) {
    for(j=0;j<NY;j++) {
      c.real = x;
      c.imag = y;

      iterate(&c,100);

      if(norm(&c) < 100.0) {
	array[i][j] = 1;
      } else {
	array[i][j] = 0;
      }

      x+= 4.0/((double) NX);
      y+= 4.0/((double) NY);
    }
  }

}


int main() {
  
  int array[NX][NY];
  int i,j;

  write_table(array);

  return 0;
}
