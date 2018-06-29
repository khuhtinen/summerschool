#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{

  int n,nthreads;
  
  printf("Hello world!\n");
#pragma omp parallel private(n) shared(nthreads)
  {
#pragma omp single
    {
    nthreads = omp_get_num_threads();
    }
    n = omp_get_thread_num();
    #pragma omp critical
    {
    printf("...from thread %d/%d\n",n,nthreads);
    }
  }
  
  return 0;
}
