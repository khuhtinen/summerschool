#include <cstdio>

class democlass {
public:
  // Two member variables, a and b
  int a, b;

  void print() const {
    printf("a=%d, b=%d\n",a,b);
  };
  
};

int main(void)
{
  democlass demo;
  demo.a = 10;
  demo.b = 20;

  demo.print();
  
  demo.a = 11;
  
  demo.print();

  return 0;
}
