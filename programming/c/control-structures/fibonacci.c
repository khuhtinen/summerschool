#include <stdio.h>

int main(int argc, char *argv[])
{
  long unsigned int f0, f1, f2;
  int n = 2;

    // initialize variables and write the while loop
    // Remember to update all variables within the loop
    f0 = 0;
    f1 = 1;
    f2 = f0 + f1;

    printf("\t0\t%lu\n\t1\t%lu\n",f0,f1);

    while(n < 100) {
      n++;
      printf("\t%d\t%lu\n",n,f2);
      f0 = f1;
      f1 = f2;
      f2 = f0 + f1;
    }

    return 0;
}
