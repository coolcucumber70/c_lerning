#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
#include "sort.h"
#include<time.h>
void cal(void(*sort)(int*,int),int a[],int len);
int main()
{ 
  Sqlist s;
  initList(&s);
  int i;
  for(i=0;i<100;i++)
  {
    insertElem(&s,i,rand()%1000);

  }
  //cal(InsertSort,s.data,s.length);
  cal(BinaryInsertSort,s.data,s.length);
  
  printlist(&s);
  return 0;

}
void cal(void(*sort)(int*,int),int a[],int len)
{
  time_t start = clock();
  sort(a,len);
  time_t finish = clock();
  double Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
  printf("%lf\n", Total_time*1000);
}
