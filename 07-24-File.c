/*  IDE     :   VSCode.1.47.1
    Time    :   20200724-1700
    By      :   Hongwei.Mao
    Coding  :   GB2312
    Ver     :   V0.1*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("%X,%d\n\n",255,"FF");
    char a='A',pwd[]={"ABCDE"},buff[255]={"ABCDE"};
    FILE *fp = NULL;
    fp = fopen("D:\\test.txt", "w+");
    fprintf(fp, "%s,,\n",buff);
    fputs("Thisis testing for fputs...\n", fp);
    fclose(fp);
    fp = fopen("D:\\test.txt", "r");
    fscanf(fp, "%s", buff);
    printf("%s\n",buff);
    fclose(fp);
    system("pause");
    return 0;
}
