/*  IDE     :   VSCode.1.47.1
    Time    :   20200724-00:00
    By      :   Hongwei.Mao
    Coding  :   GB2312
    Ver     :   V1.0*/

//�����
#define MAXLEN 15
const char *Welcome="��ӭʹ��CO0kieؼ�����뱾~�汾��V1.0";
//������ļ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//���ýṹ��
typedef struct _PASSWORDINFO {
	int id;
	char used[MAXLEN];
	char pass[MAXLEN];
    struct _PASSWORDINFO *NEXT;
}PWDINFO,*pPWD;
//���뺯�� init()���ڳ�ʼ���������
void init();
//�������
int main()
{
    init();
    printf("���򼴽��˳���\n");
    system("pause");
    return 0;
}
//���� init()
void init(){
    char buff[50]={"title "};
    strcat(buff , Welcome);
    system(buff);

}