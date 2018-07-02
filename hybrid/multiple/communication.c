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
  MPI_Comm_rank(MPI_COMM_WORLD,&my_id);

  MPI_Comm_size(MPI_COMM_WORLD,&np);
  
#pragma omp parallel private(omp_rank, msg, i)
  {
    //Get my thread number and the total number of threads
    omp_rank = omp_get_thread_num();
    nt = omp_get_num_threads();
    
    //Initialize my int to be sent or received
    if(my_id==0) {
      msg = omp_rank;
    }
    else{
      msg = -1;
    }

    // Initial print
    printf("My initial: process %d thread %d msg %d \n",my_id,omp_rank,msg);

    
    
    // Print result
    printf("My final: process %d thread %d msg %d \n",my_id,omp_rank,msg);
    
  }

  MPI_Finalize();
  
}
