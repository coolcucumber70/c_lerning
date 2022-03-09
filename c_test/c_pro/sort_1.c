// 输入不超过20个非负整数（输入每个整数后按回车，以-1结束且不计入整数个数），用一维数组作函数参数编程实现如下功能：
// （1）录入每个整数，函数原型：unsigned short ReadNumber(int num[])，num存储输入的整数，返回值为输入整数的个数；
// （2）按由高到低的顺序排序，函数原型：void SortNumberDescending(int num[], unsigned short n)，n为整数个数；
// （3）对这些整数求和及平均值，函数原型：void SummingAveraging(int num[], unsigned short n, int *pSum, float *pAver)，pSum指向和变量，pAver指向平均值变量；
// （4）输出这些整数，函数原型：void  PrintNumber(int num[], unsigned short n) 。
// 主函数中按以下示例形式提示输入、调用函数（1）、调用函数（2）、提示输出、调用函数（4）、调用函数（3）、输出整数和及平均值。
#include<stdio.h>
#define N 25
unsigned short ReadNumber(int num[]){
    unsigned short i=0;
    while(1){
        scanf("%d",&num[i]);
        if(num[i]==-1){
            break;
        }
        i++;
    }
    return i;

}
void SortNumberDescending(int num[], unsigned short n){
    int i,j,tmp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(num[j]<num[j+1]){
                tmp=num[j];
                num[j]=num[j+1];
                num[j+1]=tmp;
            }
        }
    }
}
void SummingAveraging(int num[], unsigned short n, int *pSum, float *pAver){
    int i;
    *pSum=0;
    *pAver=0;
    for(i=0;i<n;i++){
        *pSum+=num[i];
    }
    *pAver=(float)*pSum/n;    
}
void  PrintNumber(int num[], unsigned short n){
    
    int i;
    for(i=0;i<n;i++){
        printf("%d\n",num[i]);
    }
}
int main(){
    int num[N]={0};
    int Sum=0;
    float Aver=0;
    printf("Input Numbers:\n");
    int n=ReadNumber(num);
    SortNumberDescending(num,n);
    printf("\nSort in descending order:\n");
    PrintNumber(num,n);
    SummingAveraging(num,n,&Sum,&Aver);
    printf("\nSum=%d,Aver=%.2f\n",Sum,Aver);

}
