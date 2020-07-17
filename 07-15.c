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

int main()
{
    char a='A';
    
    printf("%c\n\n",a<'a'?a+32:a);
    m15_4_7();
    system("pause");
    return 0;
}
