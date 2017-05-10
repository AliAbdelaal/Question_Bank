#include<stdio.h>
int main(){
    int a=5,b=10;
    if(++a||++b)
         printf("%d%d",a,b);
    else
         printf("0");
}
