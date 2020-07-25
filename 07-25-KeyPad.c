/*  IDE     :   VSCode.1.47.1
    Time    :   20200725-00:00
    By      :   Hongwei.Mao
    Coding  :   GB2312
    Ver     :   V1.0*/
//����Ŀ��Դ��ַ https://github.com/mhw666/15PB-C-Language
//���ļ���Դ��ַ 
//----------------------�����----------------------
#define MAXLEN 15
const char *Welcome="��ӭʹ��CO0kieؼ�����뱾~�汾V1.0";
const char _MENU[][10]={"1.","2.","3."};
//--------------------������ļ�--------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//------------------���ýṹ��-------------------
typedef struct _PASSWORDINFO {
	int id;
	char used[MAXLEN];
	char pass[MAXLEN];
    struct _PASSWORDINFO *NEXT;
}PWDINFO;
//��ʼ��ȫ�ֱ���
PWDINFO *g_pPWD=NULL;
FILE    *g_fp = NULL;
unsigned int gLen=0;
//----------���뺯��----------
//init()���ڳ�ʼ���������-----
int init(int mode);
//initPWD()���ڳ�ʼ������-----
int initPWD();
//saveINFO()���ڱ������뱾----
int saveINFO();
//----------�������----------
int main()
{
    if(init(0)){
        printf("");
    }
    printf("���򼴽��˳���\n");
    //�ͷ�ָ�롢�ṹ��
    if(g_pPWD!=NULL){
        free(g_pPWD);
    }
    system("pause");
    return 0;
}
//---------����init()---------
int init(int mode){
    //��ʼ������
    char buff[50]={"title "};
    if(mode==0){
        printf("���ڳ�ʼ�������Ժ����\n");
        //���ñ���
        strcat(buff , Welcome);
        system(buff);
    }
    //��ʼ�ж����뱾�治����
    if(g_fp = fopen("my.bin" , "r+")){
        printf("���ļ�%x" , g_fp);
        fclose(g_fp); g_fp = NULL;
    }else{
        //�ļ������ڣ��������ļ�
        g_fp = NULL;
        printf("�ļ������ڣ��Ƿ񴴽���y/n\n");
        scanf("%s" , buff);
        if(buff[0] == 'y'){
            printf(">>>�����ļ�\n");
            initPWD();
        }else if (buff[0]=='n'){
            printf("�˳�����\n");
            return 0;
        }
    }
    return 1;
}
//------------��ʼ�����뱾------------
int initPWD(){
    if(g_pPWD==NULL) 
        g_pPWD=(PWDINFO*)malloc(sizeof(PWDINFO));
    if(g_fp==NULL){
        //��ʼ������
        PWDINFO*tmp = (PWDINFO*)calloc(1,sizeof(PWDINFO));
        tmp -> id = 1;
        strcpy(tmp->used,"��������;");
        strcpy(tmp->pass,"����������");
        tmp -> NEXT = NULL;
        printf("%d\t%s\n",tmp->id,tmp->used);
        g_pPWD -> NEXT = tmp;
        saveINFO();
    }
    return 1;
}
//------------�����ļ�------------
int saveINFO(){
    g_fp=fopen("my.bin","w+");
    printf(">>>�����ļ���FILE:0x%X\n",g_fp);
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