#include<stdio.h>
int fun(int);
int main()
{

    int i = fun(10);
    printf("%d\n", --i);
    return 0;
}
int fun(int i)
{
   return (i++);
}
