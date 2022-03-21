#include<stdio.h>
#include<string.h>
#define N
char*sumstr(char*a,char*b);
int main(){
    char a[]="1234567";
    char b[]="1234";
    sumstr(a,b);
}
char*sumstr(char*a,char*b){
    int len1=strlen(a);
    int len2=strlen(b);
    char*sum;
    int len;
    char c;
    if(len1>=len2){
        len=len1;
        sum=a;
    }
    else{
        len=len2;
        sum=b;
    }
    int flag=0,i;
    for(i=0;i<len;i++){
        int num=(int)(a[len1-1-i]+b[len2-1-i]-'0'-'0')+flag;
        if(num>9){
            flag=1;
            num=num%10;
        }
        else{
            flag=0;
        }
        c=(char)(num-0)+'0';
        sum[len-1-i]=c;      
    }
    //len=(len1-len)?(len1-1-len):(len2-1-len);
    //sum[len]+=(char)(flag-0);
    puts(sum);

}