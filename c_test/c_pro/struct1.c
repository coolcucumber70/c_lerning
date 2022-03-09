#include<stdio.h>
// 写一个程序包含如下的函数，完成：
// 考虑每个月的实际天数，同时也考虑闰年的情况。

struct date_rec
  {
    int day ;
    int month ;
    int year ;
  } ;
//struct date_rec current_date ;
//(a) 输入current_date的值：
void input_date(struct date_rec *current_date);
//(b) 将current_date增加1天：
void increment_date(struct date_rec *current_date);
//(c) 显示current_date的值：
void output_date(struct date_rec *current_date);
void input_date(struct date_rec *current_date){
    int day,month,year;
    printf("input year month day:");
    scanf("%d,%d,%d",&year,&month,&day);
    current_date->day=day;
    current_date->month=month;
    current_date->year=year;
}
void increment_date(struct date_rec *current_date){
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(current_date->year%4==0&&current_date->year%100!=0){months[1]=29;}
    else{months[1]=28;}
    if(current_date->day==months[current_date->month-1]){
        if(current_date->month==12){
            current_date->month=1;
            current_date->day=1;
            current_date->year++;
            }
        else{
            current_date->month++;
            current_date->day=1;
            }
            
        }
    else{
            current_date->day++;
        };
}
void output_date(struct date_rec *current_date){
    printf("data:%dyear%dmonth%dday\n",current_date->year,current_date->month,current_date->day);
}
int main(){
    struct date_rec current_date;
    input_date(&current_date);
    output_date(&current_date);
    increment_date(&current_date);
    output_date(&current_date);

}


