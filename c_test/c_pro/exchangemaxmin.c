// 从键盘输入n个整数，用函数编程实现最大值和最小值的交换，并打印结果。
// **输入格式要求："%d"  
//   提示信息："Input n(n<=10):"  "Input %d numbers:"
// **输出结果格式要求："%5d"
//   提示信息："Exchange results:"
#include<stdio.h>
#define N 10
int main(){
    int a[N]={0};
    int n,i,tmp;
    printf("Input n(n<=10):");
    scanf("%d",&n);
    printf("Input %d numbers:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min_index=0,max_index=0;
    for(i=0;i<n;i++){
        if(a[i]>a[max_index]){
            max_index=i;
        }
        if(a[i]<a[min_index]){
            min_index=i;
        }
    }
    tmp=a[min_index];
    a[min_index]=a[max_index];
    a[max_index]=tmp;
    printf("Exchange results:");
    for(i=0;i<n;i++){
        printf("%5d",a[i]);

    }





}