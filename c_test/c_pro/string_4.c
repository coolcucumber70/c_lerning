#include<stdio.h>
#include<stdlib.h>
#define N 50
//int checknum(char c);
void getnumstr(char*str);
void printstr(char*str);
int main(){
    printf("input num:\n");
    char* str1=(char*)malloc(N);
    char str2[N];
    scanf("%s",str1);
    //scanf("%s",str2);
    //getchar();
    gets(str2);
    getnumstr(str1);
    getnumstr(str2);
    printf("res=\n");
    printstr(str1);
    puts(str2);
    printf("end\n");

}
void getnumstr(char*str){
    char* p=str;
    while(*p){
        if(*p>='0'&&*p<='9'){
            *str=*p;
            str++;
        }
        p++;
    }
    *str='\0';
}
void printstr(char*str){
    while(*str){
        printf("%c",*str);
        str++;
    }
    printf("\n");
}