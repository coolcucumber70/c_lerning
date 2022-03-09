// 按如下函数原型，用二维数组作为函数参数，编程计算并输出n×n阶矩阵的转置矩阵。
// 其中，n由用户从键盘输入。已知n值不超过10。
// void Transpose(int a[][N], int n);
// void InputMatrix(int a[][N], int n);
// void PrintMatrix(int a[][N], int n);
// **输入提示信息要求："Input n:\n" "Input %d*%d matrix:\n"
// **输入格式："%d"
// **输出提示信息："The transposed matrix is:\n"
// **输出要求："%d\t"
//             输出矩阵时，每输出一行就换行
// 注：不能使用指针、结构体、共用体、文件、goto、枚举类型进行编程。
#include<stdio.h>
#define N 10
void InputMatrix(int a[][N], int n){
    int i,j;
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            printf("Input %d*%d matrix:\n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void PrintMatrix(int a[][N], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}
void Transpose(int a[][N], int n){
    int i,j,tmp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
           tmp=a[i][j];
           a[i][j]=a[j][i];
           a[j][i]=tmp;
        }
    }
}
int main(){
    int n;
    int data[N][N]={0};
    printf("input n:");
    scanf("%d",&n);
    InputMatrix(data,n);
    PrintMatrix(data,n);
    Transpose(data,n);
    printf("Transpose\n");
    PrintMatrix(data,n);
    return 0;
}

