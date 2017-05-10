#include<Stdio.h>

int main ()
{
    int x = 3 , y = 2  , i;
    int sum = 0 ;
    for(i=0;i<4;i++)
        sum+= (x*2)/(y*2) ;
    printf("%d",sum) ;
}
