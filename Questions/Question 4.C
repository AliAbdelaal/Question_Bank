#include<stdio.h>
int main ()
{
    int x ,  *pt ;
    x = 25 ;
    pt = & x ;
    *pt = 27 ;
    printf("%d" , x ) ;
}
