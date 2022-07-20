#include <stdio.h>
#include <stdlib.h>

void operateDemo();

void stringDemo();

void memoryDemo();

int main() {


//    operateDemo();

    //普通变量的类型作用:从内存中提取数据的时候，确定提多少个。比如int类型提取四个字节的长度
    //指针变量的类型作用：指针的长度时固定8个字节，类型是指针在做运算的时候需要移动的步长。

    //NULL 空指针，野指针

    //指针常量和常量指针

    //字符串
//    stringDemo();

      memoryDemo();

    return 0;
}

void memoryDemo(){
    char a=4;
    //有跨类型的时候，char补足为四个
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
    //61fde8,61fddb 两个地址不一样，说明不是同一个常量
    printf("%x,%x",&str1,&str2);
}

void operateDemo() {
    int a = 15;
    int b = 255;
    int c = 315;

    int *p = &a;

    //6422036, 6422032,6422028
    printf("%d, %d,%d\n", &a, &b, &c);

    //栈生长的方向是从大到小
    p = p - 1;
    //6422032
    printf("%d\n", p);

    //255
    printf("%d\n", *p);
    //先取出p的值，打印语句结束之后，再做p=p+1;注意p是指针，指针的加减运算就是对地址进行操作。
    //255
    printf("%d\n", *p++);
    //15
    printf("%d\n", *p);

    //255
    //255
    //先计算p=p-1;然后取出p的值，打印出来。
    printf("%d\n", *--p);
    printf("%d\n", *p);


    printf("-------------------\n");
    //两个指针进行加减，只会计算它们的地址差额的个数
    int *p1 = &a;
    int *p2 = &c;
    int p3 = p1 - p2;
    printf("p1-p2=%d(个int)\n", p3);

    char *p5 = &a;
    char *p6 = &c;
    int p7 = p5 - p6;
    printf("p5-p6=%d(个char)\n", p7);


    //如果计算的两个指针类型大小不一样，那么计算时把大的强转成小的
    int *p8 = &a;
    char *p9 = &c;
    int p10 = (char *) p8 - p9;
    printf("p8-p9=%d(个char)\n", p10);
}
