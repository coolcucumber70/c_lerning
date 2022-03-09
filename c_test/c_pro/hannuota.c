#include<stdio.h>
int cout=0;
void dfs(int n,char a,char b,char c){

    if(n==1){
        cout++;
        printf("%d--%d: %c->%c\n",cout,n,a,b);
        return;
    }
    dfs(n-1,a,c,b);
    cout++;
    printf("%d--%d:%c->%c\n",cout,n,a,b);
    dfs(n-1,c,b,a);
}
int main(){
    int n=3;
    dfs(n,'a','b','c');
    return 0;
}