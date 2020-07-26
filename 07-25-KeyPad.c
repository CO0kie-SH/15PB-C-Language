/*  IDE     :   VSCode.1.47.1
    Time    :   20200725-00:00
    By      :   Hongwei.Mao
    Coding  :   GB2312
    Ver     :   V1.0*/
//����Ŀ��Դ��ַ https://github.com/mhw666/15PB-C-Language ���ļ���Դ��ַ��
//https://github.com/mhw666/15PB-C-Language/blob/master/07-25-KeyPad.c
//----------------------�����----------------------
#define MAXLEN 15
const char *Welcome="��ӭʹ��CO0kieؼ�����뱾~�汾V1.0";
const char _MENU[][11]={"1.�鿴����","2.�޸�����","3.ɾ������","4.��������","5.��������","6.�˳�"};
//--------------------������ļ�--------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------���ýṹ��-------------------
typedef struct _PASSWORDINFO {
	int id;
	char used[MAXLEN];
	char pass[MAXLEN];
    struct _PASSWORDINFO *NEXT;
}PWDINFO;
//��ʼ��ȫ�ֱ���
PWDINFO *g_pPWD = NULL;
FILE    *g_fp   = NULL;
size_t  PWDLEN  = 0;
unsigned int gLen=0;
//----------���뺯��----------
void initMENU();
//init()���ڳ�ʼ���������-----
int init(int mode);
//initPWD()���ڳ�ʼ������-----
int initPWD(int mode);
//saveINFO()���ڱ������뱾----
int saveINFO();
//readINFO()���ڶ�ȡ���뱾----
int readINFO();
//showPWD()������ʾ����-------
int showPWD(int id,int isPWD);
int readINFO();
//addPWD()�����������룬����ID-
int addsPWD(const char* used,const char* pass);
//updtPWD()�����޸����룬����ID
int updtPWD(int id,const char* pass);
//delPWD()�����޸����룬����ID
int delsPWD(int id);
//----------�������----------
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
                /* �������� */
            }else if (input[0]=='5')
            {
                /* code */
            }
        }
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
    PWDLEN = sizeof(PWDINFO)-sizeof(PWDINFO*);
    if(mode==0){
        printf("���ڳ�ʼ�������Ժ����\n");
        //���ñ���
        strcat(buff , Welcome);
        system(buff);
    }
    //��ʼ�ж����뱾�治����
    if(g_fp = fopen("my.bin" , "r+")){
        initMENU();
        if (readINFO && mode==1){
            // show
            if(showPWD(0,1)){
                char used[]="�û���2",pass[]="����2";
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
                printf("ʾ����������ɹ����س������������У�\n");
                system("pause");
                initMENU();
            }
        }
    }else{
        //�ļ������ڣ��������ļ�
        g_fp = NULL;
        printf("�ļ������ڣ��Ƿ񴴽���y/n\n");
        scanf("%s" , buff);
        if(buff[0] == 'y'){
            printf(">>>�����ļ�\n");
            initPWD(0);
            init(1);
        }else if (buff[0]=='n'){
            printf("�˳�����\n");
            return 0;
        }
    }
    return 1;
}
//------------��ʼ���˵���------------
void initMENU(){
    system("cls");
    printf("#%030s\n","#");
    for (short i = 0; i < 6; i++)
    {
        printf("#\t%-22s#\n",_MENU[i]);
    }
    printf("#%030s\n","#");
}
//------------��ʼ�����뱾------------
int initPWD(int mode){
    PWDINFO*tmp;
    if(g_pPWD==NULL) 
        g_pPWD=(PWDINFO*)malloc(sizeof(PWDINFO));
    if(g_fp==NULL){
        //��ʼ������
        tmp = (PWDINFO*)calloc(1,sizeof(PWDINFO));
        if (mode==0){
            tmp -> id = 1;
            strcpy(tmp->used,"��������;");
            strcpy(tmp->pass,"����������");
            printf("%d\t%s\n",tmp->id,tmp->used);
            g_pPWD -> NEXT = tmp;
            saveINFO();
        }
    }else{  //��ȫ���ļ�ָ������ʱ����⴫���С
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
                // printf(">[%d]������[%s]\n",t->id,t->used);
            }
            printf(">>��ɶ�ȡ����%d��\n",i);
        }
    }
    return 1;
}
//------------�����ļ�------------
int saveINFO(){
    g_fp=fopen("my.bin","w+");
    printf(">>>�����ļ���FILE:0x%X,gLen=%d\n",g_fp,gLen);
    fwrite(&gLen,4,1,g_fp);
    //��ʼ������
    PWDINFO *t=g_pPWD;gLen=0;
    //ѭ�����������ļ�
    while (t->NEXT)
    {
        t=t->NEXT;
        fwrite(t,PWDLEN,1,g_fp);
        gLen++;
    }
    //�ض�������
    fseek(g_fp,0,SEEK_SET);
    fwrite(&gLen,4,1,g_fp);
    fclose(g_fp); g_fp = NULL;
    printf(">>>�����ļ���FILE:0x%X,gLen=%d\n",g_fp,gLen);
    return 1;
}
//------------��ȡ�ļ�------------
int readINFO(){
    int err=1,len=-1;
    if (g_fp == NULL) g_fp = fopen("my.bin" , "r+");
    if (g_fp == NULL) {
        printf("���ļ�ʧ��,0x%X\n",g_fp);
        err=0;
    }else{
        fread(&len,4,1,g_fp);
        if (len == -1){
            printf(">>>ERROR_��ȡ�ļ�ʧ�ܡ�\n");
            err=0;
        }else if (len > 0){
            printf(">>>��ȡ��int=%d\n",len);
            err=initPWD(len);
        }
    }
    fclose(g_fp); g_fp = NULL;
    return err;
}
//�����������
int showPWD(int id,int isPWD){
    //��û�г�ʼ����CALL�����
    if(g_pPWD==NULL) return 0;
    PWDINFO* tmp=g_pPWD;
    printf("#\t%-5s\t%-10s\t%-8s\t#\n","ID","��;","����");
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
//����add������������
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
    printf(">>>�ɹ���������[%s]\n",t->used);
    tmp->NEXT=t;
    return id;
}
//����updt�����޸�����
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
        printf(">>>�ɹ��޸�����[%d]\n",tmp->id);
    else{
        printf(">>>ʧ���޸�����\n");
    }
    return err;
}
//����dels����ɾ������
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
        printf(">>>�ɹ�ɾ������[%d]\n",id);
    else{
        printf(">>>ʧ��ɾ������\n");
    }
    return err;
}