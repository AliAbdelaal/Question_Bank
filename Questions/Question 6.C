#include<stdio.h>

void Pixels(int) ;
int arr[3] = {0};
int main ()
{
    Pixels(3);
    int i ;
    for(i=0;i<3;i++)
        printf("%d" , arr[i]) ;
}

void Pixels(int x)
{
    if(!x)
        return ;
    else
    {
       arr[x-1] = x ;
       Pixels(--x);
    }

}
