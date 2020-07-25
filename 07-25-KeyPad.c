/*  IDE     :   VSCode.1.47.1
    Time    :   20200725-00:00
    By      :   Hongwei.Mao
    Coding  :   GB2312
    Ver     :   V1.0*/
//本项目开源地址 https://github.com/mhw666/15PB-C-Language
//本文件开源地址 
//----------------------定义宏----------------------
#define MAXLEN 15
const char *Welcome="欢迎使用CO0kie丶的密码本~版本V1.0";
const char _MENU[][10]={"1.","2.","3."};
//--------------------导入库文件--------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//------------------设置结构体-------------------
typedef struct _PASSWORDINFO {
	int id;
	char used[MAXLEN];
	char pass[MAXLEN];
    struct _PASSWORDINFO *NEXT;
}PWDINFO;
//初始化全局变量
PWDINFO *g_pPWD=NULL;
FILE    *g_fp = NULL;
unsigned int gLen=0;
//----------载入函数----------
//init()用于初始化各类参数-----
int init(int mode);
//initPWD()用于初始化链表-----
int initPWD();
//saveINFO()用于保存密码本----
int saveINFO();
//----------程序入口----------
int main()
{
    if(init(0)){
        printf("");
    }
    printf("程序即将退出！\n");
    //释放指针、结构体
    if(g_pPWD!=NULL){
        free(g_pPWD);
    }
    system("pause");
    return 0;
}
//---------函数init()---------
int init(int mode){
    //初始化变量
    char buff[50]={"title "};
    if(mode==0){
        printf("正在初始化程序，稍后见。\n");
        //设置标题
        strcat(buff , Welcome);
        system(buff);
    }
    //开始判断密码本存不存在
    if(g_fp = fopen("my.bin" , "r+")){
        printf("打开文件%x" , g_fp);
        fclose(g_fp); g_fp = NULL;
    }else{
        //文件不存在，创建新文件
        g_fp = NULL;
        printf("文件不存在，是否创建？y/n\n");
        scanf("%s" , buff);
        if(buff[0] == 'y'){
            printf(">>>创建文件\n");
            initPWD();
        }else if (buff[0]=='n'){
            printf("退出程序！\n");
            return 0;
        }
    }
    return 1;
}
//------------初始化密码本------------
int initPWD(){
    if(g_pPWD==NULL) 
        g_pPWD=(PWDINFO*)malloc(sizeof(PWDINFO));
    if(g_fp==NULL){
        //初始化数据
        PWDINFO*tmp = (PWDINFO*)calloc(1,sizeof(PWDINFO));
        tmp -> id = 1;
        strcpy(tmp->used,"这里是用途");
        strcpy(tmp->pass,"这里是密码");
        tmp -> NEXT = NULL;
        printf("%d\t%s\n",tmp->id,tmp->used);
        g_pPWD -> NEXT = tmp;
        saveINFO();
    }
    return 1;
}
//------------保存文件------------
int saveINFO(){
    g_fp=fopen("my.bin","w+");
    printf(">>>保存文件，FILE:0x%X\n",g_fp);
    fwrite(&gLen,4,1,g_fp);
    PWDINFO *t=g_pPWD;int i=0;
    while (t->NEXT)
    {
        t=t->NEXT;
        fwrite(&t,sizeof(PWDINFO),1,g_fp);
        printf("t[%d]\tid=%d\t%s\t%s\n",
            ++i,t->id,t->used,t->pass);
    }
    fclose(g_fp); g_fp = NULL;
    return 1;
}