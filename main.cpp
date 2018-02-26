//九度2.7  计算某天是周几
#include <stdio.h>
#include <string.h>

int Month[13][2] = {0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};
char Monthstring[13][20] = {"","january","february","martch","april","may","june","july","august","september","october","november","december"};
char Weekstring[7][20] = {"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
int runnian (int year)
{
    if(year%400 == 0) return 1;
    if((year%100!=0)&&(year%4==0)) return 1;
    return 0;
}

struct day
{
    int year;
    int month;
    int day;

    void nextday()
    {
        day++;
        int l = runnian(year);
        if(day>Month[month][l])
        {
             day = 1;
             month++;
        if(month>12)
         {
            month = 1;
            year++;
         }

        }
    }
};
int buf[5001][13][32];//都是定义的比他实际上有的大1 因为平时不从0开始计数

int main()
{
    day today;
    today.day = 1;
    today.month = 1;
    today.year = 0;
    int cnt = 0;
    while(today.year<=5000)
    {
        buf[today.year][today.month][today.day] = cnt;
        today.nextday();
        cnt ++;
    }//把5000年以内每天和0年1月1日差几天存到该日的buf数组里

    int y1,m1,d1;
    char m [20];
    int result;
    while(scanf("%d %s %d",&d1,m,&y1)!=EOF)
    {
        for(m1 = 1;m1<=12;m1++)
        {
            if(strcmp(m,Monthstring[m1])==0)
            break;
        }
         result = buf[y1][m1][d1] - buf[2012][7][16];//纯相隔几天
          /*  if(result>0) result = result +1;
            else
            {
                result = -result;
                result = result +1;
            }*/
            result +=1;//加20120716这天是周一

            result = (result%7 +7)%7;//负的变正（减20120716是负的）
            printf("%s",Weekstring[result]);
    }
    return 0;
}
