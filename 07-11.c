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

int main()
{
    m11_2_2();
    printf("\n");
    system("pause");
    return 0;
}
