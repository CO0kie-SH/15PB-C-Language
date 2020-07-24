/*  IDE     :   VSCode.1.47.1
    Time    :   20200724-00:00
    By      :   Hongwei.Mao
    Coding  :   GB2312
    Ver     :   V1.0*/

//定义宏
#define MAXLEN 15
const char *Welcome="欢迎使用CO0kie丶的密码本~版本号V1.0";
//导入库文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//设置结构体
typedef struct _PASSWORDINFO {
	int id;
	char used[MAXLEN];
	char pass[MAXLEN];
    struct _PASSWORDINFO *NEXT;
}PWDINFO,*pPWD;
//载入函数 init()用于初始化各类参数
void init();
//程序入口
int main()
{
    init();
    printf("程序即将退出！\n");
    system("pause");
    return 0;
}
//函数 init()
void init(){
    char buff[50]={"title "};
    strcat(buff , Welcome);
    system(buff);

}