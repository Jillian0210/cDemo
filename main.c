#include <stdio.h>
#include <stdlib.h>

void operateDemo();

void stringDemo();

void memoryDemo();

int main() {


//    operateDemo();

    //��ͨ��������������:���ڴ�����ȡ���ݵ�ʱ��ȷ������ٸ�������int������ȡ�ĸ��ֽڵĳ���
    //ָ��������������ã�ָ��ĳ���ʱ�̶�8���ֽڣ�������ָ�����������ʱ����Ҫ�ƶ��Ĳ�����

    //NULL ��ָ�룬Ұָ��

    //ָ�볣���ͳ���ָ��

    //�ַ���
//    stringDemo();

      memoryDemo();

    return 0;
}

void memoryDemo(){
    char a=4;
    //�п����͵�ʱ��char����Ϊ�ĸ�
    int b=5;

    int e=6;
    char *p=&a;
    char *p1=&b;

    char c=p-p1;
    printf("%d\n",c);
//    int d=p-p1;
//    printf("%d\n",d);

}

void stringDemo() {
    char *str1 = "I love China";
    char str2[] = "I love China";
    //61fde8,61fddb ������ַ��һ����˵������ͬһ������
    printf("%x,%x",&str1,&str2);
}

void operateDemo() {
    int a = 15;
    int b = 255;
    int c = 315;

    int *p = &a;

    //6422036, 6422032,6422028
    printf("%d, %d,%d\n", &a, &b, &c);

    //ջ�����ķ����ǴӴ�С
    p = p - 1;
    //6422032
    printf("%d\n", p);

    //255
    printf("%d\n", *p);
    //��ȡ��p��ֵ����ӡ������֮������p=p+1;ע��p��ָ�룬ָ��ļӼ�������ǶԵ�ַ���в�����
    //255
    printf("%d\n", *p++);
    //15
    printf("%d\n", *p);

    //255
    //255
    //�ȼ���p=p-1;Ȼ��ȡ��p��ֵ����ӡ������
    printf("%d\n", *--p);
    printf("%d\n", *p);


    printf("-------------------\n");
    //����ָ����мӼ���ֻ��������ǵĵ�ַ���ĸ���
    int *p1 = &a;
    int *p2 = &c;
    int p3 = p1 - p2;
    printf("p1-p2=%d(��int)\n", p3);

    char *p5 = &a;
    char *p6 = &c;
    int p7 = p5 - p6;
    printf("p5-p6=%d(��char)\n", p7);


    //������������ָ�����ʹ�С��һ������ô����ʱ�Ѵ��ǿת��С��
    int *p8 = &a;
    char *p9 = &c;
    int p10 = (char *) p8 - p9;
    printf("p8-p9=%d(��char)\n", p10);
}
