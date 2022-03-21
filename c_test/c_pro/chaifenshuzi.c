#include<stdio.h>
int main(){
    int n=-2304;
    //printf("input n:\n");
    //scanf("%d",&n);
    int a=n/100;
    int b=n%100;
//     sum=%d,sub=%d,multi=%d\n"
// ""
    printf("sum=%d,sub=%d,multi=%d\n",a+b,a-b,a*b);
    if(b==0){
        printf("The second operator is zero!\n");
    }
    else{
        printf("dev=%.2f,mod=%d\n",(double)a/b,a%b);

    }

}