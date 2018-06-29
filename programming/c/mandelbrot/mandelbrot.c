#include <stdio.h>
#include <stdlib.h>

#define NX 1000
#define NY 1000

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


double norm(complex *z) {
  return (z->real)*(z->real) + (z->imag)*(z->imag);
}

/*
  Returns the last iterate that is not larger than 2
 */
int iterate(complex *c, int N) {

  int i = 0;
  complex z;
  z.real = 0.0;
  z.imag = 0.0;

  do {
    square(&z);
    add(&z,c);
    i++;
  } while((norm(&z)<4)&&(i<N));

  return i;

}


/*
  Produce table approximating the Mandelbrot set
 */
void write_table(double array[NX][NY]) {

  complex c;
  c.real = 0.0;
  c.imag = 0.0;


  int i,j;
  double y = -2.0;
  double x;

  for(i=0;i<NY;i++) {
    x = -2.5;
    for(j=0;j<NX;j++) {
      c.real = x;
      c.imag = y;

      array[i][j] = (double) iterate(&c,200);


      x+= 4.0/((double) NY);
    }
    y+= 4.0/((double) NX);
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

  write_table(array);

  /*
  int i,j;
  for(i=0;i<NX;i++) {
    for(j=0;j<NY;j++) {
      printf("%d\t",(int) array[i][j]);
    }
    printf("\n");
  }
  */
  
  draw_result(array);

  return 0;
}
