#include<stdio.h>
int main ()
{
    int number = 256 ;
    while(number)
    {
        printf("%d" , number%10) ;
        number/=10 ;
    }
}
