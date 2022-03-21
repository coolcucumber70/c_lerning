#include<stdio.h>
#define N 80
int CountWords(char str[]);
int main(){
    char s1[N];
    char*s2="i am word";
    char s3[N]={'i',' ','a','m',' ','w','o','r','d','\0'};
    char s4[N]="i am word"; 
    int count1,count2,count3,count4;
    printf("input s:\n");
    gets(s1);
    count1=CountWords(s1);
    count2=CountWords(s2);
    count3=CountWords(s3);
    count4=CountWords(s4);
    printf("%d %d %d %d",count1,count2,count3,count4);
}
int CountWords(char str[]){
    char*p=str;
    int sum=0;
    if(*p!=' '){
        sum++;
    }
    while(*p!='\0'){
        if(*p==' '&&*(p+1)!=' '){
            sum++;
        }
        p++;
    }
    return sum;

}