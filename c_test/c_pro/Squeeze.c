#include <stdio.h>
void  Squeeze(char *s, char c);
void  Squeeze1(char *s, char c);
int main()
{
    char a[80]="assdssdfasf";
    char c='s';
    char*s;
    //scanf("%s",a);
    //scanf(" %c",&c);
    s=a;
    Squeeze(s,c);
    printf("%c",s[0]);
    printf("%s\n",s);
    return 0;
}
void  Squeeze(char *s, char c)
{
    int i,j=0;
    for (i=0;*(s+i)!='\0';i++)
    {
        if (*(s+i)!= c)
        {
            *(s+j) = *(s+i);
            j++;
        }
        
    }
    //printf("j=%d",j);
    s[j] = '\0';
}
void  Squeeze1(char *s, char c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i ++)
    {
        if(s[i] != c)
        {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0'; /* 在字符串t2的末尾添加字符串结束标志 */

}