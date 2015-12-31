#include <stdio.h>
#include <stdlib.h>

extern long int fibonacci(long int num);

int main(int argc, char* argv[])
{
  long int i = 40;
  long int ret = 0;
  ret = fibonacci(i);
  printf("%ld\n",ret);
}
