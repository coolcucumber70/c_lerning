#include<stdio.h>
#define N 20
void printstr(char*s);
int main(){
    char name1[N];
    char name2[N];
    char ch;
    int n;
    printf("input:n,ch\n");
    scanf("%d",&n);
    getchar(); //可以吃掉空格，也可以吃掉enter
    scanf("%c",&ch);//这玩意，吃字符   
    scanf("%s",name1);
    scanf("%s",name2);
    printf("\nres:\n");
    printf("%d ",n);
    printf("%c\n",ch);
    printstr(name1);
    printstr(name2);




}
void printstr(char*s){
    puts(s);

}