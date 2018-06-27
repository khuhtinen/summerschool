#include <stdio.h>

void add_one_to_both(int* a, int* b) {

  *a += 1;
  *b += 1;

}

int main() {
  int a, b;
  a = 10;
  b = 20;
  
  printf("a=%d, b=%d\n",a,b);
  add_one_to_both(&a,&b);
  printf("a=%d, b=%d\n",a,b);

}
