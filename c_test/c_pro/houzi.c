#include <stdio.h>
int main()
{
    int n;
    do
    {
        printf("Input days:\n");
        scanf("%d", &n);
        //getchar();
    } while (n <= 0);
    int count = 1;
    int i;
    for (i = 1; i < n; i++)
    {
        count = (count + 1) * 2;
    }
    printf("x=%d\n", count);
}