#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#define MaxSize 100
#define INF 2147483647;
//线性表
typedef struct Sqlist{
    int data[MaxSize];
    int length;
}Sqlist;
void initList(Sqlist* L);
int getElem(Sqlist L, int p, int* e);
void printlist(Sqlist*L);
int insertElem(Sqlist* L, int p, int e);
int findElem(Sqlist L, int e);
int deleteElem(Sqlist* L, int p, int* e);
void reversearry(int a[],int k,int n);//408 2010 反转
void reverse(int a[],int l,int r);
int findzhongweishu(int a[],int b[],int n);
int majority(int a[],int n);
void deletetwosamenode(int a[],int b[],int c[],int an,int bn, int cn);//2006 1 删除a中bc都有的元素
int main()
{
    int a[8]={1,2,3,5,7,8,9,10};
    int b[9]={2,4,5,6,7,8,9,10,12};
    int c[10]={1,2,3,4,6,8,9,12,13,15};
    deletetwosamenode(a,b,c,8,9,10);
    return 0;
}
void initList(Sqlist* L) {
    L->length = 0;
}
int getElem(Sqlist L, int p, int* e){
    if (p < 0 || p >= L.length) {
        return 0;
    }
    *e = L.data[p];
    return 1;
}
void printlist(Sqlist*L)
{
    int i;
    int len=L->length;
    for(i=0;i<len;i++)
    {
        printf("%d\t",L->data[i]);
    }
}
int insertElem(Sqlist* L, int p, int e) {
    if (p < 0 || p > L->length || L->length == MaxSize) {
        return 0;
    }
    int i;
    for (i = L->length-1; i >= p; i--) {
        L->data[i+1] = L->data[i];
    }
    L->data[p] = e;
    ++(L->length);
    return 1;
}
int findElem(Sqlist L, int e) {
    int i;
    for ( i= 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return -1;
}
int deleteElem(Sqlist* L, int p, int* e) {
    if (p < 0 || p >= L->length) {
        return 0;
    }
    *e = L->data[p];
    int i;
    for (i = p; i < L->length-1; i++) {
        L->data[i] = L->data[i+1];
    }
    --(L->length);
    return 1;
}
void reversearry(int a[],int k,int n)//k代表左移k位
{
    reverse(a,0,n-1);
    reverse(a,0,k-1);
    reverse(a,k,n-1);

}
void reverse(int a[],int l,int r)
{

    int tmp;
    while(l<r)
    {
        tmp=a[r];
        a[r]=a[l];
        a[l]=tmp;
        l++;
        r--;
    }
}
int findzhongweishu(int a[],int b[],int n)
{
    int p=0,q=0,result,i;
    for(i=0;i<n;i++){
        if(a[p]<b[q]){
            result=a[p];
            p++;}
        else{
            result=b[q];
            q++;
        }
    }
    return result;
}
int majority(int a[],int n)
{
    int i;
    int num=a[0],cout=1;
    for(i=1;i<n;i++)
    {
        if(cout==0)
        {
            num=a[i];
        }
        if(a[i]==num)
        {
            cout++;
        }
        else
        {
            cout--;
        }
    }
    cout=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        cout++;
    }
    if(cout>(n/2))
    {
        return num;
    }
    else{
        return -1;
    }
    
}
void deletetwosamenode(int a[],int b[],int c[],int an,int bn, int cn)
{
    int btr=0,ctr=0,atr=0,i;
    while(btr<bn&&ctr<cn&&atr<an)
    {
        if(b[btr]==c[ctr]){
            while(atr<an)
            {
                if(a[atr]<b[btr]){
                    atr++;
                }
                else if(a[atr]==b[btr]){
                    for(i=atr;i<an-1;i++)
                    {
                        a[i]=a[i+1];
                    }
                    an=an-1;
                    btr++;
                    ctr++;
                    break;
                }
                else{
                    btr++;
                    ctr++;
                    break;
                }
            }

        }
        else if(b[btr]>c[ctr]){
            ctr++;
        }
        else{
            btr++;
        }
    }
    for(i=0;i<an;i++)
    {
        printf("%d ",a[i]);
    }

}