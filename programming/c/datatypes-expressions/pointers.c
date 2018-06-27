#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    // declare a pointer variable and assign it to address of e.g. a

    // Evaluate expressions using both the original and the pointer variable
    // and investigate the value / value pointed to

    int *p = &a;

    a = 5;
    printf("Value of a: %d, p: %d\n",a,*p);
    

    return 0;
}
