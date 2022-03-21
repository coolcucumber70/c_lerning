#include<stdio.h>
int main(){
    double sum=1;
    double tmp=1;
    int i;

    for(i=1;i<64;i++){
        tmp=tmp*2;
        sum+=tmp;
    }
    printf("sum=%lf",sum);
}