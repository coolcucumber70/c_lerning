#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char weekday[][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char s[10];
    printf("input week:\n");
    gets(s);
    for(i=0;i<7;i++)
    {
        if(strcmp(s,weekday[i])==0){
            printf("%s is %d\n",s,i);
            return; 
        }
    }
    printf("no found!\n");
    return;

}