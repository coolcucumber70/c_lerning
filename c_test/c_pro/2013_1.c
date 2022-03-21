#include<stdio.h>
int Median(int answer[], int n);
int main(){
    int n,i,feedback;
    int answer[11]={0};
    printf("Input total number of feedbacks\n");
    scanf("%d",&n);
    printf("Input feedbacks\n");
    for(i=0;i<n;i++){
        scanf("%d",&feedback);
        answer[feedback]++;       
    }
    int res=Median(answer,n);
    printf("Median value:%d",res);
}
int Median(int answer[], int n){
    int num=n/2,i;
    int sum=0;
    for(i=1;i<=n;i++){           
        if(sum<num){
            sum+=answer[i];
        }
        else{
            return i;
        }
    }
}