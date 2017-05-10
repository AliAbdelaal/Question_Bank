#include<stdio.h>
int main(){
     static int i;
     int j=1;
     int arr[5]={1,2,3,4};
     switch(arr[j]){
        case 1: i++;break;
        case 2: i+=2;j=3;break;
        case 3: i%=2;j=4;break;
        default: --i;
     }
     printf("%d",i);
}
