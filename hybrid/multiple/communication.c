#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

int main(int argc, char* argv[]) {

  int np, nt;
  int my_id, omp_rank, msg;
  int recvd;
  int provided, required = MPI_THREAD_MULTIPLE;
  int i;
  
  MPI_Init_thread(&argc,&argv,required,&provided);

  if(provided < MPI_THREAD_MULTIPLE) {
    printf("MPI_THREAD_MULTIPLE not supported.\n");
    MPI_Abort(MPI_COMM_WORLD, -1);

  }
  
  MPI_Comm_rank(MPI_COMM_WORLD,&my_id);
  MPI_Comm_size(MPI_COMM_WORLD,&np);
  
#pragma omp parallel private(omp_rank, nt, msg, i)
  {
    //Get my thread number and the total number of threads
    omp_rank = omp_get_thread_num();
    nt = omp_get_num_threads();
    
    if(my_id == 0) {
      msg = omp_rank + 10;
      for(i=1;i<np;i++) {
	MPI_Send(&omp_rank,1,MPI_INT,i,omp_rank,MPI_COMM_WORLD);
      }
    }
    else {
      MPI_Recv(&msg,1,MPI_INT,0,omp_rank,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    }
    
    // Print result
    printf("My final: process %d thread %d msg %d \n",my_id,omp_rank,msg);
    
  }

  MPI_Finalize();
  
}
