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

int main()
{
    char a='A';
    
    printf("%c\n\n",a<'a'?a+32:a);
    m15_4_7();
    system("pause");
    return 0;
}
