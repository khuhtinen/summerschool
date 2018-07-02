#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int my_id, omp_rank;
    int provided, required = MPI_THREAD_FUNNELED;

    /* TODO: Initialize MPI with thread support. */
    MPI_Init_thread(&argc,&argv,required,&provided);
    
    /* TODO: Find out the MPI rank and thread ID of each thread and print
     *       out the results. */
    MPI_Comm_rank(MPI_COMM_WORLD,&my_id);

#pragma omp parallel private(omp_rank)
    {
    omp_rank = omp_get_thread_num();

    printf("Hello world ! From rank %d, thread %d.\n",my_id,omp_rank);
    }

    if(my_id==0) {
      if(provided == MPI_THREAD_SINGLE) {
	printf("MPI_THREAD_SINGLE\n");
      }
      else if(provided == MPI_THREAD_FUNNELED) {
	printf("MPI_THREAD_FUNNELED\n");
      }
      else if(provided == MPI_THREAD_SERIALIZED){
	printf("MPI_THREAD_SERIALIZED\n");
      }
      else if(provided == MPI_THREAD_MULTIPLE) {
	printf("MPI_THREAD_MULTIPLE\n");
      }
      else{
	printf("Something else\n");
      }
    }
    
    MPI_Finalize();
    return 0;
}
