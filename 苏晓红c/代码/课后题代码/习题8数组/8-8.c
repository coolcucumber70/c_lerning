#include<stdio.h>
#define M 20
#define N 6
int main(){
    int i,j,grade,feedback[M]={0},count[N]={0};
    for(i=0;i<M;i++){
        scanf("%d",&feedback[i]);
    }
    for(i=0;i<M;i++)
    {
        switch (feedback[i])
        {
        case 1:count[1]++;break;
        case 2:count[2]++;break;
        case 3:count[3]++;break;
        case 4:count[4]++;break;
        case 5:count[5]++;break;
        default:printf("input error\n");
        }
    }
    printf("FeedBack\tCount\tHistogram\n");
    for(grade=1;grade<=N-1;grade++){
        printf("%8d\t%5d\t",grade,count[grade]);
        for(j=0;j<count[grade];j++){
            printf("%c",'*');
        }
        printf("\n");
    }
    return 0;

}