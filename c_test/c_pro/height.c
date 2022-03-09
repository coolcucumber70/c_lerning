#include<stdio.h>
int main(){
    char sex,sports,diet;
    float faHeight,moHeight,myheight;
    printf("Are you a boy(M) or a girl(F)");
    scanf("%c",&sex);
    printf("Please input your father's height(cm):");
    scanf("%f",&faHeight);
    printf("Please input your mother's height(cm):");
    scanf("%f",&moHeight);
    printf("Do you like sports(Y/N)?");
    scanf(" %c",&sports);
    //printf("Do you have a good habit of diet(Y/N)?");
    scanf(" %c",diet);
    if(sex=='M'){
        
    }
    else{
        myheight=(faHeight*0.923+moHeight)/2 ;
    }
    //printf("Your future height will be %f(cm)",myheight);
    if(sports=='Y'){
        myheight==myheight*(1+0.02);}
    printf("Your future height will be %f(cm)",myheight);
    if(diet=='Y'){
        myheight=myheight*(1+0.015);}
    printf("Your future height will be %f(cm)",myheight);
}