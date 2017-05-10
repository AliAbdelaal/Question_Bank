#include<stdio.h>

 int main(void)
  {
  int a = 1, b = 2, c = 3;

  printf("%d%d%d", a+b+c, (b = b*2), (c = c*2));

  return 0;

   }
