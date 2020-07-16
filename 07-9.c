#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count=10,sum=0;
    int nums[count];
    for (int i = 0; i < count; i++)
    {
        nums[i]=rand();
        sum+=nums[i];
        printf("%d\t",nums[i]);
    }
    printf("\nÆ½¾ùÖµ\t%d\nµ¹Ğò\n",sum/count);
    for (int i = 0, tmp = 0; i < count/2; i++)
    {
        tmp=nums[count-1-i];
        nums[count-1-i]=nums[i];
        nums[i]=tmp;
    }
    for (int i = 0; i < count; i++)
        printf("%d\t",nums[i]);
    printf("\n");
    system("pause");
    return 0;
}
