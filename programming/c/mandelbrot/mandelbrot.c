#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double real;
  double imag;
} complex; 


void *square(complex * z) {
  
  complex * res;
  res->real = z->real*z->real - z->imag*z->imag;
  res->imag = 2*z->real*z->imag;

  z->real = res->real;
  z->imag = res->imag;
}

void *add(complex * z, complex * c) {
  
  z->real += c->real;
  z->imag += c->imag;

}

int main() {
  

  return 0;
}
