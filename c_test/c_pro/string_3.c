#include<stdio.h>
#include<string.h>
#define LEN 10
#define N 150
// 请编程实现按奥运会参赛国国名(国家名字可以带空格)在字典中的顺序对其出场顺序进行排序。
// 假高参赛国家不超过150个。以下程序有错误，请找出并改正。
void sort(char country[][LEN],int n);
void printstr(char country[][LEN],int n);
int main(){
    char country[N][LEN];
    int n,i;
    printf("input country num:");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        gets(country[i]);
    }
    sort(country,n);
    printf("res:\n");
    printstr(country,n);
}
//bubble
void sort(char country[][LEN],int n){
    int i,j;
    char str[LEN];
    for(i=0;i<n-1;i++){
        int flag=1;
        for(j=0;j<n-i-1;j++){           
            if(strcmp(country[j],country[j+1])>0){
                strcpy(str,country[j]);
                strcpy(country[j],country[j+1]);
                strcpy(country[j+1],str);
                flag=0;
            }
        }
        if(flag==1){
            break;
        }
    }
}
void printstr(char country[][LEN],int n){
    int i;
    for(i=0;i<n;i++){
        puts(country[i]);
    }
}
