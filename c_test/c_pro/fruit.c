#include<stdio.h>
int main(){
    int n=100000;
    int num;
    int i,l,r;
    while(1){
        num=0;
        for(i=1;i<=n;i++){
            if((i-1)%3==0&&(n-i)%5==0){
                num++;
            }          
        }
        if(num<10){n++;}
        else if(num==10000){
            printf("num =%d,n=%d\n",num,n);
            n++;
        }
        else if(num==10001){
            //printf("num=%d,n=%d\n",num,n);
            n++;
            }
        else if(num==10002){
            printf("num=%d,n=%d\n",num,n);
            break;
            }

    }
}