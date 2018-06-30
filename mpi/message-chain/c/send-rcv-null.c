#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, myid, ntasks;
    int receiver, sender;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;
    int count;
    
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message buffers */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }


    // Set the receiver and sender
    if(myid<ntasks -1 && myid > 0){
      sender = myid - 1;
      receiver = myid + 1;
    }
    else if(myid<ntasks-1) {
      sender = MPI_PROC_NULL;
      receiver = myid + 1;
    }
    else {
      sender = myid - 1;
      receiver = MPI_PROC_NULL;
    }
    
    /* Start measuring the time spent in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();


    MPI_Sendrecv(message,size,MPI_INT,receiver,myid + 1,
		 receiveBuffer,size,MPI_INT,sender,MPI_ANY_TAG,
		 MPI_COMM_WORLD,&status);

    MPI_Get_count(&status,MPI_INT,&count);
    
    if(myid<ntasks - 1) {
      printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
	     myid, size, receiver, receiver);
    }
    if(myid>0) {
      printf("Receiver: %d. First element %d. Amount of data: %d.\n",
	     myid, receiveBuffer[0],count);
    }
    

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
