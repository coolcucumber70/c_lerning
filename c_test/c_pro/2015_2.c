#include <stdio.h>
#define M 10
#define N 10
void ReadScore(float score[][M], int n, int m);
float scoresum(float a[], int n);
void CountScore(float averagescore[], float score[][M], int n, int m);
void maxmin(float a[], int n, float *max, float *min);
int main()
{
    int n,m,i;
    float score[N][M];
    float averagescore[N]={0};
    printf("Input the number of athletes\n");
    scanf("%d",&n);
    printf("Input the number of judges\n");
    scanf("%d",&m);
    ReadScore(score,n,m);
    CountScore(averagescore,score,n,m);
    printf("The final scores for each athletes\n");
    for(i=0;i<n;i++){
        printf("%.2f\n",averagescore[i]);
    }
}
void ReadScore(float score[][M], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%f", &score[i][j]);
        }
    }
}
void CountScore(float averagescore[], float score[][M], int n, int m)
{
    float max, min, sum;
    int i;
    for (i = 0; i < n; i++)
    {
        maxmin(score[i], m, &max, &min);
        sum = scoresum(score[i], m) - max - min;
        averagescore[i] = sum/(m-2);
    }
}
void maxmin(float a[], int n, float *max, float *min)
{
    *max = a[0];
    *min = a[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > *max)
            *max = a[i];
        if (a[i] < *min)
            *min = a[i];
    }
}
float scoresum(float a[], int n)
{
    int i;
    float sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}