
extern "C" {
#include "pngwriter.h"
}

#include "matrix.h"


// This function saves the field values to a png file
void print_field( Matrix<double>& f ) {
    int error_code;

    error_code = save_png( 
            (double*) &f(0,0),
            f.nx, 
            f.ny, 
	    			"array2d.png", 
            'c');

    if (error_code == 0) {
        printf("Wrote output file array2d.png\n");
    } else {
        printf("Error while writing output file array2d.png\n");
    }

}


void initialize_matrix(Matrix<double> &m) {

  int i,j;

  //initialize interior
  for(i=1;i<m.nx-1;i++) {
    for(j=1;j<m.ny-1;j++) {
      m(i,j) = 0.0;
    }
  }

  //boundary conditions
  for(i=0;i<m.nx;i++) {
    m(i,0) = 85.0;
    m(i,m.ny-1) = 5.0;
  }

  for(j=0;j<m.ny;j++) {
    m(0,j) = 20.0;
    m(m.nx-1,j) = 70.0;
  }

}

void laplacian(Matrix<double> &m, double dx, double dy) {

  int i,j;

  Matrix<double> lap(m.nx,m.ny);

  for(i=1;i<m.nx-1;i++) {
    for(j=1;j<m.ny-1;j++) {
      lap(i,j) = ( m(i-1,j) - 2*m(i,j) + m(i+1,j) ) / (dx*dx)
	+ (m(i,j-1) - 2*m(i,j) + m(i,j+1)) / (dy*dy);
    }
  }

  m = lap;

}


// main function
int main() 
{

  // TODO create empty 2d matrix called mat
  Matrix<double> mat(258,258);

  // TODO implement initialization function
  initialize_matrix(mat);

  double dx = 0.01;
  double dy = 0.01;

  // TODO implement function to compute Laplacian of mat
  laplacian(mat,dx,dy);

  print_field(mat);

}
