#include<stdio.h>
#include<string.h>
#define N 50
void insertspqce(char*s);
void inverse(char*s);
void mystrcat(char*s,char*d);
int main(){
    char str[N],dst[N];
    printf("INPUTstr:\n");
    gets(str);
    printf("INPUTdst:\n");
    gets(dst);
    mystrcat(str,dst);
    //insertspace(str);
    //inverse(str);
    printf("PUT:%s\n",str);
}
//10.6insertspace插入空格
void insertspace(char*s){
    char t[N];
    char*p=t;
    strcpy(t,s);
    for(;*p!='\0';p++,s++){
        *s=*p;
        s++;
        *s=' ';
    }
    *s='\0';
}
//10.7逆序
void inverse(char*s){
    int q=strlen(s)-1;
    int p=0;
    char tmp;
    while(p<q){
        tmp=s[p];
        s[p]=s[q];
        s[q]=tmp;
        p++;
        q--;
    }
}
//10.8
void mystrcat(char*s,char*d){
    int i=strlen(s);
    while((*d)!='\0'){
        s[i]=*d;
        i++;
        d++;
    }
    s[i]='\0';
}