#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double real;
  double imag;
} complex; 


complex *square(complex * z) {
  
  complex * res;
  res->real = z->real*z->real - z->imag*z->imag;
  res->imag = 2*z->real*z->imag;

  return res;
}

int main() {
  

  return 0;
}
