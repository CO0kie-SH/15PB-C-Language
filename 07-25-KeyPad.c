/*  IDE     :   VSCode.1.47.1
    Time    :   20200725-00:00
    By      :   Hongwei.Mao
    Coding  :   GB2312
    Ver     :   V1.0*/
//本项目开源地址 https://github.com/mhw666/15PB-C-Language 本文件开源地址：
//https://github.com/mhw666/15PB-C-Language/blob/master/07-25-KeyPad.c
//----------------------定义宏----------------------
#define MAXLEN 15
const char *Welcome="欢迎使用CO0kie丶的密码本~版本V1.0";
const char _MENU[][11]={"1.查看密码","2.修改密码","3.删除密码","4.新增密码","5.导出密码","6.退出"};
//--------------------导入库文件--------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------设置结构体-------------------
typedef struct _PASSWORDINFO {
	int id;
	char used[MAXLEN];
	char pass[MAXLEN];
    struct _PASSWORDINFO *NEXT;
}PWDINFO;
//初始化全局变量
PWDINFO *g_pPWD = NULL;
FILE    *g_fp   = NULL;
size_t  PWDLEN  = 0;
unsigned int gLen=0;
//----------载入函数----------
void initMENU();
//init()用于初始化各类参数-----
int init(int mode);
//initPWD()用于初始化链表-----
int initPWD(int mode);
//saveINFO()用于保存密码本----
int saveINFO();
//readINFO()用于读取密码本----
int readINFO();
//showPWD()用于显示密码-------
int showPWD(int id,int isPWD);
int readINFO();
//addPWD()用于增加密码，返回ID-
int addsPWD(const char* used,const char* pass);
//updtPWD()用于修改密码，返回ID
int updtPWD(int id,const char* pass);
//delPWD()用于修改密码，返回ID
int delsPWD(int id);
//----------程序入口----------
int main()
{
    char input[50]={0};
    if(init(0)){
        while (input[49]=='\0')
        {
            scanf("%s",input);
            if(input[1]!='\0' || input[0]<'1' || input[0]>'6')
                continue;
            printf("[%c]\n",input[0]);
            if(input[0]=='6'){
                input[49]='6';
            }else if (input[0]>'0' && input[0]<'4')
            {
                
            }else if (input[0]=='4')
            {
                /* 新增密码 */
            }else if (input[0]=='5')
            {
                /* code */
            }
        }
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
    PWDLEN = sizeof(PWDINFO)-sizeof(PWDINFO*);
    if(mode==0){
        printf("正在初始化程序，稍后见。\n");
        //设置标题
        strcat(buff , Welcome);
        system(buff);
    }
    //开始判断密码本存不存在
    if(g_fp = fopen("my.bin" , "r+")){
        initMENU();
        if (readINFO && mode==1){
            // show
            if(showPWD(0,1)){
                char used[]="用户名2",pass[]="密码2";
                addsPWD(used,pass);
                used[6]='3';
                pass[4]='3';
                addsPWD(used,pass);
                showPWD(0,1);
                pass[4]='m';
                updtPWD(1,pass);
                showPWD(0,1);
                delsPWD(2);
                showPWD(0,1);
                printf("示范例子输出成功，回车后程序继续运行！\n");
                system("pause");
                initMENU();
            }
        }
    }else{
        //文件不存在，创建新文件
        g_fp = NULL;
        printf("文件不存在，是否创建？y/n\n");
        scanf("%s" , buff);
        if(buff[0] == 'y'){
            printf(">>>创建文件\n");
            initPWD(0);
            init(1);
        }else if (buff[0]=='n'){
            printf("退出程序！\n");
            return 0;
        }
    }
    return 1;
}
//------------初始化菜单项------------
void initMENU(){
    system("cls");
    printf("#%030s\n","#");
    for (short i = 0; i < 6; i++)
    {
        printf("#\t%-22s#\n",_MENU[i]);
    }
    printf("#%030s\n","#");
}
//------------初始化密码本------------
int initPWD(int mode){
    PWDINFO*tmp;
    if(g_pPWD==NULL) 
        g_pPWD=(PWDINFO*)malloc(sizeof(PWDINFO));
    if(g_fp==NULL){
        //初始化数据
        tmp = (PWDINFO*)calloc(1,sizeof(PWDINFO));
        if (mode==0){
            tmp -> id = 1;
            strcpy(tmp->used,"这里是用途");
            strcpy(tmp->pass,"这里是密码");
            printf("%d\t%s\n",tmp->id,tmp->used);
            g_pPWD -> NEXT = tmp;
            saveINFO();
        }
    }else{  //当全局文件指被创建时，检测传入大小
        if (mode > 0){
            int i=0,id=0;
            tmp = g_pPWD;
            fseek(g_fp,4,SEEK_SET);
            for (; i < mode; i++)
            {
                PWDINFO* t = (PWDINFO*)calloc(1, sizeof(PWDINFO));
                fread(t,PWDLEN,1,g_fp);
                tmp->NEXT = t;
                tmp = tmp->NEXT;
                // printf(">[%d]被用来[%s]\n",t->id,t->used);
            }
            printf(">>完成读取，共%d个\n",i);
        }
    }
    return 1;
}
//------------保存文件------------
int saveINFO(){
    g_fp=fopen("my.bin","w+");
    printf(">>>保存文件，FILE:0x%X,gLen=%d\n",g_fp,gLen);
    fwrite(&gLen,4,1,g_fp);
    //初始化变量
    PWDINFO *t=g_pPWD;gLen=0;
    //循环链表、插入文件
    while (t->NEXT)
    {
        t=t->NEXT;
        fwrite(t,PWDLEN,1,g_fp);
        gLen++;
    }
    //重定向总数
    fseek(g_fp,0,SEEK_SET);
    fwrite(&gLen,4,1,g_fp);
    fclose(g_fp); g_fp = NULL;
    printf(">>>保存文件，FILE:0x%X,gLen=%d\n",g_fp,gLen);
    return 1;
}
//------------读取文件------------
int readINFO(){
    int err=1,len=-1;
    if (g_fp == NULL) g_fp = fopen("my.bin" , "r+");
    if (g_fp == NULL) {
        printf("打开文件失败,0x%X\n",g_fp);
        err=0;
    }else{
        fread(&len,4,1,g_fp);
        if (len == -1){
            printf(">>>ERROR_读取文件失败。\n");
            err=0;
        }else if (len > 0){
            printf(">>>读取后int=%d\n",len);
            err=initPWD(len);
        }
    }
    fclose(g_fp); g_fp = NULL;
    return err;
}
//用于输出密码
int showPWD(int id,int isPWD){
    //都没有初始化，CALL个鬼鬼
    if(g_pPWD==NULL) return 0;
    PWDINFO* tmp=g_pPWD;
    printf("#\t%-5s\t%-10s\t%-8s\t#\n","ID","用途","密码");
    while (tmp->NEXT)
    {
        tmp=tmp->NEXT;
        if(id==0 || id==tmp->id){
                printf("#\t %d\t%-5s \t%-8s\t#\n",tmp->id,tmp->used,isPWD?tmp->pass:"");
        }
    }
    printf("\n");
    return 1;
}
//函数add用于增加密码
int addsPWD(const char* used,const char* pass){
    int id=0,i=0;
    PWDINFO*tmp=g_pPWD,*t;
    while (tmp->NEXT)
    {
        tmp=tmp->NEXT;
        i++;
        // printf("i=[%d]\n",i);
    }
    id=++i;
    t=(PWDINFO*)calloc(1, sizeof(PWDINFO));
    t->id=id;
    strcpy(t->used,used);
    strcpy(t->pass,pass);
    printf(">>>成功插入数据[%s]\n",t->used);
    tmp->NEXT=t;
    return id;
}
//函数updt用于修改密码
int updtPWD(int id,const char* pass){
    int err=1;
    PWDINFO*tmp=g_pPWD,*t;
    while (tmp->NEXT)
    {
        tmp=tmp->NEXT;
        if(tmp->id==id){
            strcpy(tmp->pass,pass);
            break;
        }
    }
    err=saveINFO();
    if(err)
        printf(">>>成功修改数据[%d]\n",tmp->id);
    else{
        printf(">>>失败修改数据\n");
    }
    return err;
}
//函数dels用于删除密码
int delsPWD(int id){
    int err=1;
    PWDINFO*tmp=g_pPWD,*t;
    while (tmp->NEXT)
    {
        if(tmp->NEXT->id==id){
            PWDINFO*t2=tmp->NEXT;
            tmp->NEXT=t2->NEXT;
            free(t2);
        }
        tmp=tmp->NEXT;
        if(tmp->id>id){
            tmp->id--;
        }
    }
    err=saveINFO();
    if(err)
        printf(">>>成功删除数据[%d]\n",id);
    else{
        printf(">>>失败删除数据\n");
    }
    return err;
}