#include<stdio.h>
#include<string.h>
#define N 80
void insertstr(char*str);
int main(){
    char str[N];
    printf("input str:");
    gets(str);
    insertstr(str);
    puts(str);
    return 0;
    
}
void insertstr(char*str){
    char tmp[N];
    strcpy(tmp,str);
    char*p=tmp;
    char*q=str;
    while(*p!='\0'){
        *q=*p;
        *(q+1)=' ';
        q=q+2;
        p++;
    }
    *q='\0';
}