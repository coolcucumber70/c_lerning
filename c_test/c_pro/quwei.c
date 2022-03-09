// 编写一个简单的23 根火柴游戏程序，实现人跟计算机玩这个游戏的程序。
// 为了方便程序自动评测，假设计算机移动的火柴数不是随机的，而是将剩余的火柴根数对3求余后再加1来作为计算机每次取走的火柴数。如果剩下的火柴数为2或3，则将计算机打算移走的火柴数减1。如果剩下的火柴数为1时，必须取走1根火柴，计算机不可以不取。
#include<stdio.h>
int main(){
    int total=23;
    int num_usr,num_com;
    while(1){
        printf("请输入您移动的火柴数目：");
        scanf("%d",&num_usr);
        printf("您移动的火柴数目为：%d\n",num_usr);
        total-=num_usr;
        printf("您移动后剩下的火柴数目为：%d\n",total);
        if(total==0){
            printf("对不起！您输了！\n");
            break;
        }
        if(total<4){
          printf("计算机移动的火柴数目为：1\n");
          total-=1;  
          
        }
        else{
            num_com=total%3+1;
            printf("计算机移动的火柴数目为：%d\n",num_com);
            total-=num_com;  
        }
        printf("计算机移动后剩下的火柴数目为：%d\n",total);
         if(total==0){
            printf("恭喜您！您赢了！\n");
            break;
        }

    }
    return 0;

}