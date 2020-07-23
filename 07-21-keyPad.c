/*  IDE     :   VSCode
    Coding  :   GB2312
    TimeDate:   20200721-2200
    By      :   Hongwei.Mao
    Ver     :   V0.1*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//定义数据集合的结构体
typedef struct PASSWORD_INFO
{
    int id;
    char *user;
    char *pass;
    char *name;
    char *info;
}PWDINFO;

int main()
{
    char cha='A';
    //定长 结构体指针数组 动态分配 尝试
    PWDINFO *s1[2]={};
    PWDINFO *s2=(PWDINFO *)malloc(1 * sizeof(PWDINFO *));
    printf("%d\t%d\t%d\n",sizeof(PWDINFO *),sizeof(s1),sizeof(s2));
    printf("地址=%x\n",&s1[0]->user);
    s1[0]=(PWDINFO *)malloc(1 * sizeof(PWDINFO *));
    printf("地址=%x\n",&s1[0]->user);
    printf("%d\t%d\n",sizeof(s1),sizeof(s2));
    s2->id=1;
    printf("id=%d\n",s2->id);
    s2->user=(char*)"mhw";
    printf("user地址=%x\tuser=%s\n",s2->user,s2->user);
    s2->name=(char*)"15pb";
    printf("name地址=%x\tname=%s\n",s2->name,s2->name);
    s2->info=(char *)malloc(100);

    //int指针分配 尝试
    int ia=1,*pa=&ia;
    printf("%x,%d\n",pa,ia);
    ia=2;
    printf("%x,%d\n",pa,ia);
    pa=(int *)malloc(1 * sizeof(int *));
    *pa=ia;
    printf("%x,%d\n",pa,ia);

    //int数组指针分配尝试
    int **pb;
    pb=(int**)malloc(1 * sizeof(int *));
    printf("单int %d；int地址占位%d 数组占位%d\n",sizeof(int),sizeof(int*),sizeof(pb));
    for (int i = 0; i < 2; i++)
    {
        printf("pb[%d]=%d\n",i,pb[i]);
    }
    //
    char *input,buff[50]={0};
    printf("input%d\n",sizeof(input));
    scanf("%s",buff);
    input=buff;
    printf("input %x,%x\n",input,buff);
    printf("input %d %s\n",sizeof(input),input);
    //
    PWDINFO **s3=(PWDINFO**)calloc(2,sizeof(PWDINFO *));
    printf("%d %d %d\n",sizeof(PWDINFO**),sizeof(PWDINFO*),sizeof(PWDINFO));
    printf("%d\n",sizeof(s3));
    for (int i = 0; i < 2; i++)
    {
        s3[i]=(PWDINFO*)malloc(sizeof(PWDINFO));
        printf("s3[%d] %x s3[].size=%d\n",i,s3[i],sizeof(s3[i]));
        printf("s3[%d] %x id.size=%d\n",i,s3[i]->id,sizeof(s3[i]->id));
        printf("s3[%d] %x user.size=%d\n",i,s3[i]->user,sizeof(s3[i]->user));
        s3[i]->id=i;
        printf("s3[%d] %x id.size=%d ==%d\n",i,s3[i]->id,sizeof(s3[i]->id),s3[i]->id);
        printf("s3[%d] %x user.size=%d ==%d\n",i,s3[i]->user,sizeof(s3[i]->user),s3[i]->user);
    }

    
    
    printf("\n");system("pause");
    return 0;
}
