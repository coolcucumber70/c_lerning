
#include<stdio.h>
//相差为2的两个素数称为孪生素数。编程输出给定区间内[a,b]的所有孪生素数对。
int issushu(int num){
    int i=0;
    for(i=2;i<num;i++){
        if(num%i==0) return 0;
    }
    return 1;
}
int sumsushu(int a,int b){
    int i,b1=0,b2=0,sum=0;
    if(a%2==0)a=a+1;
    if(b%2==0)b=b-1;
    for(i=a;i<=b;i+=2){
        b2=issushu(i);
        sum+=(b1==1&&b2==1)?1:0;
        b1=b2;
    }
    return sum;

}
int main(){
    int sum=sumsushu(11,16);
    printf("sum=%d",sum);
}
