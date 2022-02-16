#include <stdio.h>
#include<stdlib.h>
//功能：从读入的整数数据中**，统计大于零的整数个数和小于零的整数个数。**用输入零来结束输入，程序中用变量i统计大于零的整数个数，用变量j统计小于零的整数个数。
int panduanzhengdfu()
{
int n,i,j;
printf("Enter iNT number,with 0 to end\n");
i=j=0;
scanf("%d",&n);
while(n!=0)
{
if(n>0)i=i+1;
if(n<0)j=j+1;
scanf("%d",&n);
}
printf("i=%4d, j=%4d\n",i,j);
}
//功能**：输入三个整数x,y,z，请把这三个数由小到大输出。**
int sort3()
{
    int x,y,z;
    int tmp;
    scanf("%d %d %d",&x,&y,&z);
    if(x>y){
        tmp=x;
        x=y;
        y=tmp;
    }
    if(x>z){
        tmp=x;
        x=z;
        z=tmp;
    }
    if(y>z){
        tmp=y;
        y=z;
        z=tmp; 
    }
    printf("small to big:%d,%d,%d",x,y,z);
}
//3、功能：将字母转换成密码，转换规则是将当前字母变成其后的第四个字母，但W变成A、X变成B、Y变成C、Z变成D。小写字母的转换规则同样。
int passwordchange(){
    char c=getchar();
    if((c>='A'&&c<='V')||(c>='a'&&c<='v')){
            c=c+4;
        }
    if((c>='V'&&c<='Z')||(c>='v'&&c<='z'))
        {
            c=c-22;
        }
    printf("c=%c\n",c);
    putchar(c);    

}
//4、功能**：求一个二维数组中每行的最大值和每行的和。**
int sumtwo(int n,int a[][5])//int (*a)[5]
{
    int i,j;
    int*max_ary=(int*)malloc(n*4);
    int*sum_ary=(int*)malloc(n*4);
    for(i=0;i<n;i++){
        int max=0;
        int sum=0;
        for(j=0;j<n;j++){
            if(a[i][j]>max)
               max=a[i][j];
            sum+=a[i][j];
        }
        max_ary[i]=max;
        sum_ary[i]=sum;
    }
    for(i=0;i<n;i++){
        printf("%d列中max=%d,sum=%d\n",i,max_ary[i],sum_ary[i]);
    }


}
//5、功能**：将一个数组中的元素按逆序存放。**
int nixuarry(int* a,int n){ 
    int i,k=n/2,tmp;
    for(i=0;i<k;i++){
        tmp=a[n-1-i];
        a[n-1-i]=a[i];
        a[i]=tmp;
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
//6\下面的程序是求1!+3!+5!+……+n!的和
int jiecheng(int n){
    int i,sum=0,tmp=1;
    for(i=1;i<=n;i+=2){
        sum+=tmp;
        tmp=tmp*(i+1)*(i+2);
    }
    printf("sum=%d",sum);
}
//7、删除指定字符串
int delstr(){
    char str [20],ch;
    printf("input chars:\n");
    puts(str);
    printf("del char:\n");
    ch=getchar();
    int i=0,k=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!=ch){
            str[k]=str[i];
            k=k+1;
        } 
    }
     str[k]='0';

    puts(str);
    return 0;
}
int main(){
    static b[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    //int a[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    //nixuarry(b,12);
    //jiecheng(3);
    delstr();
    
    //sumtwo(5,a);
    //passwordchange();
    //sort3();
}