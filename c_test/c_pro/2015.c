#include <stdio.h>
int isnum(int n);
int main()
{
    int n=200;
    int m=2;
    int i;
    double sum=0;
    for(i=1;i<=n;i++){
        if(isnum(i)){
            sum+=(double)1/i;
        }
    }
    printf("sum=%lf",sum);
}
int isnum(int n)
{
    while (n != 0)
    {
        
        if(n%10==6){
            return 1;
        }
        n = n / 10;        
    }
    return 0;
}