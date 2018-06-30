#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

  int n;

  MPI_Init(&argc,&argv);
  
  MPI_Comm_rank(MPI_COMM_WORLD,&n);
  
  printf("Hello world! ");

  if(n%2==0)
    printf("I'm thread %d.\n",n);
  else
    printf("I'm %d. I'm odd.\n",n);

  if(n==0) {
    int N;
    MPI_Comm_size(MPI_COMM_WORLD,&N);
    printf("There is a total of %d of us.\n",N);
  }
  
  MPI_Finalize();
  

  return 0;

}
