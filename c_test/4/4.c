#include <stdio.h>
//4.1getchar
int exgetchar ()
{
   char c;
   printf("input:\n");
   c = getchar();
   printf("output:\n");
   putchar(c);
   return 0;
}
int exscanf(){
    int a,b;
    printf("a,b?");
    scanf("%d %d",&a,&b);
    printf("a=%d,b=%d",a,b);
    return 0;

}
int main(){
   //exscanf();
   exgetchar();
   return 0;
}