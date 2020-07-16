#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void m10_4_1(){
    int a,b,c;
    printf("10_4_1\t等边三角形的三条边长度都相等\n请输入三边长：\n");
    scanf("%d %d %d",&a,&b,&c);
    if (!(a&&b&&c)) {                   //判断边长为0
        printf("边长不为0。");return;
    }
    if (a+b<=c || a+c<=b || b+c<=a) {   //两短边＞第三边
        printf("无法构成三角形。");return;
    }
    if (a==b && b==c){                  //等腰
        printf("等边三角形。");
    }else if(a==b || b==c){             //等腰基础上等边
        printf("等腰三角形。");
    }else{
        printf("不等边三角形。");
    }
    return;
}

void m10_4_2(){
    char a;
    printf("\n10-4-2\t输入一个字符，输出他\n");
    scanf("%s",&a);
    //printf("%c %d\n属于\t",a,a);
    if (a>'z' || a<'0'){                //计算范围
        printf("不属于范围内。");return;
    }
    if (a>'Z')                          //[a-z]＞'Z'
        printf("小写字母。");
    else if (a>'9')                     //[A-Z]＞'9'
        printf("大写字母。");
    else if (a>='0')                    //[0-9]≥'0'
        printf("数字。");
    return;
}

void m10_4_3(){
    int year,isY=0;
    printf("\n10-4-3 输入一个年份，判断其是不是闰年。\n");
    scanf("%d",&year);
    //400倍数为闰
    if (year % 400 ==0)                 //400倍数为闰
        isY=1;
    else if(year % 4 ==0)               //4倍数中
        isY=year % 100==0? 0:1;         //100的倍数非闰
    printf("%d：%s闰年。\n",year, isY ? "是":"不是");
    return;
}

void m10_4_4(){
    int x,y,z,max=0;
    printf("\n10-4-4 编写一个程序要求能从键盘上输入3个数并且将三个数中的最大数输出到屏幕上。\n");
    scanf("%d %d %d",&x,&y,&z);
    //开始计算
    max= x>y ? x:y;
    max= z>max ? z:max;
    printf("最大数为%d\n",max);
    return;
}

void m10_4_5(){
    int x,y,z,max=0;
    printf("\n10-4-5 编程实现输出所有1～100之间能除9余2的数。\n");
    for (int i = 1; i <= 100; i++)
    {
        if(i%9==2) printf("%2d ",i);    //循环输出
    }
    printf("\n",max);
    return;
}

void m10_4_6(){
    int x,y,z;
    printf("10-4-6定义三个变量，输入三个数， 将三个数由小到大排序输出。（不要使用循环和数组）\n");
    scanf("%d %d %d",&x,&y,&z);
    printf("纯逻辑计算法:\n");           //纯逻辑计算法
    if(x<y){                            //前2比较
        if(x>z)
            printf("%d %d %d",z,x,y);   //5 8 2
        else if(z>y){
            printf("%d %d %d",x,y,z);   //2 5 8
        }else{
            printf("%d %d %d",x,z,y);   //2 8 5
        }
    }else{                              //y较小
        if(y>z)
            printf("%d %d %d",z,y,x);   //8 5 2
        else if(z>x){
            printf("%d %d %d",y,x,z);   //5 2 8
        }else{
            printf("%d %d %d",y,x,z);   //8 2 5
        }
    }
    printf("\n");
    return;
}

void m10_5_1(size_t n){
    char indexs[][6]={"Zero","One","Two","Three","Fore","Five","Six","Seven","Eight","Nine","Ten"};
    char numStr[11]={0};                //倒序整数至数组
    size_t num=0;                       //大于10位的整数
    int i=0,z=0;                        //i用来循环输出，z用作余数
    printf("\n10-5-1 写一程序，要求用户在键盘上输入一个整数，并把每位数字转换为英文。假设此整数最多10位。\n");
    if (n==0){                          //当main传入具体数字时，不输入
        scanf("%lld",&num);
    }else{
        num=n;
    }
    printf("%lld\n",num);               //格式化long long
    for (int i = 0; i < 10; i++)
    {
        z=num%10;                       //取余
        num=num/10;                     //每次除以10，赋值给自己
        numStr[10-i]=z;                 //倒序插入数组
    }
    while(!numStr[++i]);                //将首位0排除
    while(i<11)                         //循环输出数组位，从字符串模板中输出
        printf("%s ",indexs[numStr[i++]]);
    printf("\n");
    return;
}

void m10_6_1(){
    //10-6-1 改错题
    char c = 0;/*
    //2 接收按键操作
    scanf("%c",c); //%c表示的是一个字符的意思哦，忘了么，看笔记去吧~~
    //3 根据按键操作做出反应
    switch (c){
        case 'w':
            char * pOper1 = "向上走";
            printf(pOper1);
            break;
        case 's':
            char * pOper2 = "向上走";
            printf(pOper2);
            break;
        case 'a':
            char * pOper3 = "向上走";
            printf(pOper3);
            break;
        case 'd':
            char * pOper4 = "向上走";
            printf(pOper4);
            break;
        default:
    }*/
    return;
}

int main()
{
    //m10_4_1();
    //m10_4_2();
    //m10_4_3();
    //m10_4_4();
    //m10_4_5();
    //m10_4_6();
    m10_5_1(1234567890ull);
    m10_5_1(12345ull);
    printf("\n");
    system("pause");
    return 0;
}
