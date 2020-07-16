#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void m11_2_2(){
    int a = 15, b = 21, m = 0;
    printf("11-2-2 有以下程序，运行结果为\n");
    switch (a % 3){
        case 0: m++; break;
        case 1: m++;
            switch (b % 2) {
                default:m++;
                case 0:m++; break;
            }
    }
    printf("%d\n", m);
    return;
}

void m11_4_1(){
    int input = 1;
    printf("11-4-1 输出一个菜单，如下所示：\n");
    printf("01 开始游戏\n");
    printf("02 游戏设置\n");
    printf("03 退出\n");
    while (input!=3)
    {
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("01 开始游戏\n");
            break;
        case 2:
            printf("02 游戏设置\n");
            break;
        case 3:
            printf("03 退出\n");
            break;
        default:
            break;
        }
    }
    return;
}
void m11_5_1(){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    char seasons[4][4]={"春","夏","秋","冬"};
    int year,month,season,isY=0,day=0;
    printf("11-5-1 编写一个程序，输入年份和月份，判断该年是否是润年，\n");
    printf("并根据给出的月份判断是什么季节和该月有多少天？\n");
    scanf("%d %d",&year,&month);
    //闰年计算
    if(year % 400 ==0)
        isY = 1;
    else if(year % 4 ==0){
        isY = year % 100 ==0 ? 0:1;
    }
    //季节计算1-3 123 456 789 101112
    if (month>=10 && month<=12) season=3;
    else if (month>=7)          season=2;
    else if (month>=4)          season=1;
    else if (month>=1)          season=0;
    //天数计算
    day=days[month-1];
    if(isY && month==2) day++;
    //输出
    printf("%d年%s是闰年 当前是%s %d月共有%d天。\n",year,isY ? "":"不",seasons[season],month,day);
}
int main()
{
    m11_2_2();
    m11_4_1();
    m11_5_1();

    printf("\n");
    system("pause");
    return 0;
}
