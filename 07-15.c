#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void m15_4_7(){
    int n=0,i=0,sum=0;
    size_t m=1;
    printf("15-4-7 �Ӽ��̻�ȡһ������n���ܹ������n!����а����ġ�0���ĸ�����\n");
    printf("(�׳� ���磺12��Ϊ479001600.�ó��Ľ���к��С�0���ĸ���Ϊ4��)\n");
    scanf("%d",&n);
    while (++i<=n)
        m*=i;
    while (m>0)
    {
        printf("\t%lld\n",m);
        if(m%10==0) sum++;
        m/=10;
    }
    printf("\n���\t%lld\n",sum);
}

void m15_5_1(){
    int n=0,i=0,sum=0,yu=0;
    size_t m=1;
    printf("15-5-1 �Ӽ��̻�ȡһ������n���ܹ����������n!β����0�ĸ�����\n");
    printf("(�׳� ���磺12��Ϊ479001600.�ó��Ľ����β��0�ĸ���Ϊ2��)\n");
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
    printf("\n���\t%lld\n",sum);
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
