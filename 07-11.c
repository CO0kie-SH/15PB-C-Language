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

int main()
{
    m11_2_2();
    m11_4_1();
    
    printf("\n");
    system("pause");
    return 0;
}
