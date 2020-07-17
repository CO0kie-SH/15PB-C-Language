#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void m15_4_7(){
    int n=0,i=0,sum=0;
    size_t m=1;
    printf("15-4-7 从键盘获取一个数字n，能够计算出n!结果中包含的“0”的个数。\n");
    printf("(阶乘 例如：12！为479001600.得出的结果中含有”0”的个数为4。)\n");
    scanf("%d",&n);
    while (++i<=n)
        m*=i;
    while (m>0)
    {
        printf("\t%lld\n",m);
        if(m%10==0) sum++;
        m/=10;
    }
    printf("\n结果\t%lld\n",sum);
}

void m15_5_1(){
    int n=0,i=0,sum=0,yu=0;
    size_t m=1;
    printf("15-5-1 从键盘获取一个数字n，能够计算出任意n!尾部的0的个数。\n");
    printf("(阶乘 例如：12！为479001600.得出的结果中尾部0的个数为2。)\n");
    scanf("%d",&n);
    while (++i<=n)
        m*=i;
    do
    {
        yu=m%10;
        if (yu==0) sum++;
        printf("yu=%d\t%lld\n",yu,m);
        m/=10;
    } while (yu==0);
    printf("\n结果\t%lld\n",sum);
}

int main()
{
    char a='A';
    
    printf("%c\n\n",a<'a'?a+32:a);
    m15_4_7();
    m15_5_1();
    system("pause");
    return 0;
}
