#include <stdio.h>

#define NX 102400

int main(void)
{
    long vecA[NX];
    long sum, psum, sumex;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i + 1;
    }

    sumex = (long) NX * (NX + 1) / ((long) 2);
    printf("Arithmetic sum formula (exact): \t %ld\n",
           sumex);

    sum = 0.0;

#pragma omp parallel for shared(sum,vecA) private(i) reduction(+:sum)
    for (i = 0; i < NX; i++) {
      sum += vecA[i];
    }
    printf("With reduction: \t %ld\n", sum);
    
    sum = 0.0;
    
#pragma omp parallel shared(sum,vecA) private(i,psum)
    {
      psum = 0.0;
#pragma omp for
      for(i=0; i<NX; i++) {
	psum += vecA[i];
      }
#pragma omp critical(sum)
      {
      sum += psum;
      }
    }
  
    printf("With critical: \t %ld\n", sum);
    
    return 0;

    

}
