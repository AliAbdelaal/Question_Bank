#include<stdio.h>

int main(){

int arr[]={0,10,20,30,40};
    int*ptr=arr;
    ptr+=2 ;
    printf("%d",*ptr);
    return 0;
}
