#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
int main()
{ 
  Sqlist s;
  initList(&s);
  int i;
  for(i=0;i<10;i++)
  {
    insertElem(&s,i,rand());
  }
  printlist(&s);
  return 0;

}
