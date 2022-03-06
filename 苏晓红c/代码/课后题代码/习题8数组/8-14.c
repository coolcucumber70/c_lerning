#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(NULL));
    int i,face,res[7]={0};
    for(i=1;i<6000;i++){
        face=rand()%6+1;
        res[face]++;
    }
    for(i=1;i<=6;i++){
        printf("p%d=%%%0.2f\n",i,(float)res[i]/6000*100);
    }
}