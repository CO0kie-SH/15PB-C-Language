#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void m11_2_2(){
    int a = 15, b = 21, m = 0;
    printf("11-2-2 �����³������н��Ϊ\n");
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
    printf("11-4-1 ���һ���˵���������ʾ��\n");
    printf("01 ��ʼ��Ϸ\n");
    printf("02 ��Ϸ����\n");
    printf("03 �˳�\n");
    while (input!=3)
    {
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("01 ��ʼ��Ϸ\n");
            break;
        case 2:
            printf("02 ��Ϸ����\n");
            break;
        case 3:
            printf("03 �˳�\n");
            break;
        default:
            break;
        }
    }
    return;
}
void m11_5_1(){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    char seasons[4][4]={"��","��","��","��"};
    int year,month,season,isY=0,day=0;
    printf("11-5-1 ��дһ������������ݺ��·ݣ��жϸ����Ƿ������꣬\n");
    printf("�����ݸ������·��ж���ʲô���ں͸����ж����죿\n");
    scanf("%d %d",&year,&month);
    //�������
    if(year % 400 ==0)
        isY = 1;
    else if(year % 4 ==0){
        isY = year % 100 ==0 ? 0:1;
    }
    //���ڼ���1-3 123 456 789 101112
    if (month>=10 && month<=12) season=3;
    else if (month>=7)          season=2;
    else if (month>=4)          season=1;
    else if (month>=1)          season=0;
    //��������
    day=days[month-1];
    if(isY && month==2) day++;
    //���
    printf("%d��%s������ ��ǰ��%s %d�¹���%d�졣\n",year,isY ? "":"��",seasons[season],month,day);
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
