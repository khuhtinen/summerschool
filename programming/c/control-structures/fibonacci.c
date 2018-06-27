#include <stdio.h>

int main(int argc, char *argv[])
{
  long long unsigned int f0, f1, f2;
  int n = 2;

    // initialize variables and write the while loop
    // Remember to update all variables within the loop
    f0 = 0;
    f1 = 1;
    f2 = f0 + f1;

    printf("\t0\t%llu\n\t1\t%llu\n",f0,f1);

    while(n < 100) {
      printf("\t%d\t%llu\n",n,f2);
      f0 = f1;
      f1 = f2;
      f2 = f0 + f1;
      n++;
    }

    return 0;
}
