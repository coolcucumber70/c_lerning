#include<stdio.h>
int main(){
    printf("Please enter rate, year, capital:\n");
    double rate,captical;
    int n,i;
    scanf("%lf,%d,%lf",&rate,&n,&captical);
    for(i=0;i<n;i++){
        captical=captical*(1+rate);
    }
    printf("deposit =%lf\n",captical);
    return 0;
}