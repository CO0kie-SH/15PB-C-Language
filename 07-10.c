#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void m10_4_1(){
    int a,b,c;
    printf("10_4_1\t�ȱ������ε������߳��ȶ����\n���������߳���\n");
    scanf("%d %d %d",&a,&b,&c);
    if (!(a&&b&&c)) {                   //�жϱ߳�Ϊ0
        printf("�߳���Ϊ0��");return;
    }
    if (a+b<=c || a+c<=b || b+c<=a) {   //���̱ߣ�������
        printf("�޷����������Ρ�");return;
    }
    if (a==b && b==c){                  //����
        printf("�ȱ������Ρ�");
    }else if(a==b || b==c){             //���������ϵȱ�
        printf("���������Ρ�");
    }else{
        printf("���ȱ������Ρ�");
    }
    return;
}

void m10_4_2(){
    char a;
    printf("\n10-4-2\t����һ���ַ��������\n");
    scanf("%s",&a);
    //printf("%c %d\n����\t",a,a);
    if (a>'z' || a<'0'){                //���㷶Χ
        printf("�����ڷ�Χ�ڡ�");return;
    }
    if (a>'Z')                          //[a-z]��'Z'
        printf("Сд��ĸ��");
    else if (a>'9')                     //[A-Z]��'9'
        printf("��д��ĸ��");
    else if (a>='0')                    //[0-9]��'0'
        printf("���֡�");
    return;
}

void m10_4_3(){
    int year,isY=0;
    printf("\n10-4-3 ����һ����ݣ��ж����ǲ������ꡣ\n");
    scanf("%d",&year);
    //400����Ϊ��
    if (year % 400 ==0)                 //400����Ϊ��
        isY=1;
    else if(year % 4 ==0)               //4������
        isY=year % 100==0? 0:1;         //100�ı�������
    printf("%d��%s���ꡣ\n",year, isY ? "��":"����");
    return;
}

void m10_4_4(){
    int x,y,z,max=0;
    printf("\n10-4-4 ��дһ������Ҫ���ܴӼ���������3�������ҽ��������е�������������Ļ�ϡ�\n");
    scanf("%d %d %d",&x,&y,&z);
    //��ʼ����
    max= x>y ? x:y;
    max= z>max ? z:max;
    printf("�����Ϊ%d\n",max);
    return;
}

void m10_4_5(){
    int x,y,z,max=0;
    printf("\n10-4-5 ���ʵ���������1��100֮���ܳ�9��2������\n");
    for (int i = 1; i <= 100; i++)
    {
        if(i%9==2) printf("%2d ",i);    //ѭ�����
    }
    printf("\n",max);
    return;
}

void m10_4_6(){
    int x,y,z;
    printf("10-4-6�������������������������� ����������С�����������������Ҫʹ��ѭ�������飩\n");
    scanf("%d %d %d",&x,&y,&z);
    printf("���߼����㷨:\n");           //���߼����㷨
    if(x<y){                            //ǰ2�Ƚ�
        if(x>z)
            printf("%d %d %d",z,x,y);   //5 8 2
        else if(z>y){
            printf("%d %d %d",x,y,z);   //2 5 8
        }else{
            printf("%d %d %d",x,z,y);   //2 8 5
        }
    }else{                              //y��С
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
    char numStr[11]={0};                //��������������
    size_t num=0;                       //����10λ������
    int i=0,z=0;                        //i����ѭ�������z��������
    printf("\n10-5-1 дһ����Ҫ���û��ڼ���������һ������������ÿλ����ת��ΪӢ�ġ�������������10λ��\n");
    if (n==0){                          //��main�����������ʱ��������
        scanf("%lld",&num);
    }else{
        num=n;
    }
    printf("%lld\n",num);               //��ʽ��long long
    for (int i = 0; i < 10; i++)
    {
        z=num%10;                       //ȡ��
        num=num/10;                     //ÿ�γ���10����ֵ���Լ�
        numStr[10-i]=z;                 //�����������
    }
    while(!numStr[++i]);                //����λ0�ų�
    while(i<11)                         //ѭ���������λ�����ַ���ģ�������
        printf("%s ",indexs[numStr[i++]]);
    printf("\n");
    return;
}

void m10_6_1(){
    //10-6-1 �Ĵ���
    char c = 0;/*
    //2 ���հ�������
    scanf("%c",c); //%c��ʾ����һ���ַ�����˼Ŷ������ô�����ʼ�ȥ��~~
    //3 ���ݰ�������������Ӧ
    switch (c){
        case 'w':
            char * pOper1 = "������";
            printf(pOper1);
            break;
        case 's':
            char * pOper2 = "������";
            printf(pOper2);
            break;
        case 'a':
            char * pOper3 = "������";
            printf(pOper3);
            break;
        case 'd':
            char * pOper4 = "������";
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
