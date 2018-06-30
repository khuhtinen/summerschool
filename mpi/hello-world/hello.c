#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

  int N,n;

  MPI_Init(&argc,&argv);
  
  MPI_Comm_size(MPI_COMM_WORLD,&N);
  MPI_Comm_rank(MPI_COMM_WORLD,&n);
  
  printf("Hello world! ");

  if(n%2==0)
    printf("I'm thread %d/%d.\n",n,N);
  else
    printf("I'm %d. I'm odd.\n",n);

  MPI_Finalize();
  

  return 0;

}
