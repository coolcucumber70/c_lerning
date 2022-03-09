#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int main(){
    double s,k,vc,vp;
    //s=120,vc=25,vp=5;
    double t1,t2,t3;
    printf("put s: vc: vp: \n");
    scanf("%lf,%lf,%lf",&s,&vc,&vp);
    //printf("%lf %lf %lf",s,vc,vp);
    double l=0,r=s;
    int i=0;
    do{
        k=(l+r)/2;
        t1=(k/vc)+(s-k)/vp;
        t2=k/vc+(k-(k/vc)*vp)/(vc+vp);
        t3=t2+(s-t2*vp)/vc;
        if(t1>t3){
            l=k;
        }
        else{
            r=k;
        }
        i++;
        printf("i=%d\n",i);

    }while (((t1-t3)>0.01)||((t3-t1)>0.01));
    printf("k=%f\n",k);
    return 0;
   
}