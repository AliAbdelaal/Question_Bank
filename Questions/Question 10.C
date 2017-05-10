#include<stdio.h>
struct A{
    int p;
    float q;
    long double *r;
};
int main(){
    struct A arr[10];
    printf("%d",sizeof arr);

    return 0;
}
