#include<stdio.h>
#define PI 3.14
//3.1输出三位数个十百之和
int sum(int num){
    int g,s,b;
    g=num%10;
    s=(num%100)/10;
    b=num/100;
    printf("sum=%d",g+s+b);
}
//3.1,2,3计算半径r的圆的面积和周长
int c_and_s(float r){
    const float pi=3.14;//不可更改
    float c=2*PI*r;
    float s=PI*r*r;
    printf("c=%f,s=%f",c,s);
}
int main(){
    sum(259);
    c_and_s(5.3);
    return 0;
}