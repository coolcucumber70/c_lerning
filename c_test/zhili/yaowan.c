int main(){
    int a[101]={0};
    int i,j,k=0,cout=0;
    for(i=1;i<=100;i++){
        k++;
        for(j=k;j<=100;j=j+k){
            a[j]=!a[j];
        }
    }
    for(i=1;i<=100;i++){
        if(a[i]){cout++;}
    }
    printf("cout=%d",cout);


}