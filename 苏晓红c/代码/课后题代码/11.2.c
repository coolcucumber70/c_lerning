#include<stdio.h>
main(){
    char*arry[]={"howim","are","you"};
    printf("%p,%p,%p\n",arry[0],arry[1],arry[2]);
    printf("%p,%p,%p,%p",arry,&arry[0],&arry[1],&arry[2]);

}
