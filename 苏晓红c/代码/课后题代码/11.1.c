#include<stdio.h>
main(){
    int a[]={100,200,300,400,500};
    int* p=a;
    printf("%d ,",*p);
    printf("%d ,",*(++p));
    printf("%d ,",(*p)++);
    printf("%d ",*p);
    printf("%d ,",*p--);
    printf("%d ,",--(*p));
    printf("%d\n,",*p);

}