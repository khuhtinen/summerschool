#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double real;
  double imag;
} complex; 


void square(complex * z) {
  
  complex * res;
  res->real = z->real*z->real - z->imag*z->imag;
  res->imag = 2*z->real*z->imag;

  z->real = res->real;
  z->imag = res->imag;
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
  complex *z;
  z->real = 0.0;
  z->imag = 0.0;

  for(i=0; i<N; i++) {
    square(z);
    add(z,c);
  }

}




int main() {
  

  return 0;
}
