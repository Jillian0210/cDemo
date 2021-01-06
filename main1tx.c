#include <stdio.h>
#include <stdlib.h>


void test07();

void test08();

void test09();

void test10();

void test11();

void test12();

void test13();

void test14();

void mystrcat();

void test15();

void test16();

void test17();

int main() {

//    test07();
//    test08();
//    test09();
//    test10();
//    test11();
//    test12();
//    test13();
//    test14();
//    test15();
//    test16();
    test17();
    return 0;
}

/**
 * 结构体
 * 关于结构体内存的对齐
 * 对齐的原因是：
 * 1、平台差异原因：不是所有的硬件平台都能访问任意地址的任意数据
 * 2、提交效率原因：由于只能在特定的地址读取数据，
 * 所以进行对齐后处理器只需要访问一次，没有对齐需要访问两次，并还需要进行提出和组合；
 * 对齐的原则：
 * 1、第一个成员变量从0开始（从头开始）
 * 2、其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。对齐数 为编译器默认的一个对齐数与该成员大小中的较小值。
 * （换一种说法就是每个成员变量的首地址是自身大小的整数倍）
 * 3、结构体的总大小是最大对齐数的整数倍
 * 4、如果嵌套结构体，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
 * 结构体的整体大小就是所有最大对齐数（包含嵌套结构体的对齐数）的整数倍。
 *
 */
void test16() {
    struct Woman {
        //地址是8个字节，
        char *name;//8
        int int1;//4
    } woman;
    struct Person {//定义Person类
        //假设计算机是64位的操作系统，那么一行为8个字节
        char char2;//1
        int int1;//4
        int int2;//4
        char char1;//1
        struct Woman woman1;
        short short1;//2
        char char3;//1

    } person1, person2;//声明person1,person2 对象


    //        int int1;//4
    //        char char1;//1
    //        char char2;//1
    //        short short1;//2
    //        long long1;//8
    //        int int2;//4
    //最大的是8个字节
    //1111 1  1 11
    //1111 1111
    //1111 ****
    //结果是24

    //        int int1;//4
    //        char char1;//1
    //        char char2;//1
    //        short short1;//2
    //        int int2;//4
    //最大的是4个字节
    //1111
    //1 1 11 //注意这里的char2 为什么没有偏移。而下面例子的short1偏移了， 因为char2是一个字节1，首地址可以是1，但是short1是2个字节，它的首地址不可以是1，可以是2，4，6，8
    //1111
    //结果为12

//    char char2;//1
//    int int1;//4
//    char char1;//1
//    short short1;//2
//    int int2;//4
//最大是4个字节
//结果为16
//1***
//1111
//1*11
//1111


//     char char2;//1
//        int int1;//4
//        int int2;//4
//        char char1;//1
//        long long1;//8
//        char char3;//1
//最大字节为8
//结果为32
//1*** 1111
//1111 1***
//11111111
//1*******


//    char char2;//1
//    int int1;//4
//    int int2;//4
//    char char1;//1
//    struct Woman woman1;
//    short short1;//2
//    char char3;//1
//最大的字节是8
//1*** 1111
//1111 1***
//11111111
//1111****
//11 1*****
//最终结果为40

    printf("person1 %d\n", sizeof(person1));



    printf("woman %d\n", sizeof(woman));


}

void test15() {
    //字符串 本身是一个一维数组；
    //字符串数组 就是二维数组
    //—————————————————————！！！！！指针常量，重点是它是一个常量，常量只能改变其内容———————————————————
    char aar[4][6] = {"abc", "efga", "hhhhs", "ijghff"};

    printf("%s\n", aar[0]);
//    aar[0]="ssss";//该写法是编译不通过的，就是说aar[0]的指向不可以改变
    strcpy(aar[0], "111");//该写法是编译通过的，就是说aar[0]的内容是可以改变的
    //得到 aar[0]是指针常量，指向的内容是常量，内容可以改变

    //————————————————————！！！！！常量 指针，重点是它是一个指针，指针的特点是可以换一个指向————————————————————
    char *aar1[6] = {"abc", "efga", "hhhhs", "ijghff"};
    printf("%s\n", aar1[0]);
    aar1[0] = "ssss";//表示把"ssss"的地址赋值给aar1[0],所以说aar[0]的指向是可以改变的
    printf("%s\n", aar1[0]);
//    strcpy(aar1[0],"111");//编译出错，表示内容不可以修改
    //得到aar1[0]是指针常量
}

/**
 * 利用指针进行字符串的拼接 ,将s2拼接到s1后面
 */
void mystrcat(char *s1, char *s2) {
    //第一句的意思是：指针指向到s1数组末尾。 当*s1 等于0 的时候跳出，就指向了末尾
    while (*s1)
        s1++;
    //第二句的意思是：把s2的值赋值到s1，当把s2的末尾0，复制到s1后，跳出循环
    while ((*s1++ = *s2++));

}

void test14() {
    char s1[] = "123";
    char s2[] = "abc";
    mystrcat(s1, s2);
    printf("s1=%s", s1);
//可以知道第七个元素是0
    printf("%d", s1[6]);

    //下面的会报错，原因是s11 其实是常量指针，不能对其内容进行修改
//    char *s11="123";
//    char *s22="abc";
//    mystrcat(s11, s22);
//    printf("s11=%s",s11);
}

void test13() {
    printf("数组指针和指针数组\n");
    printf("关于数组指针的理解------》\n");
    //数组指针 也叫做行指针
    // 因为()的优先级最高，所以先看（*p），p由*来修饰，说明p是一个指针；
    // 然后看[n],说明是个数组，并且数组的长度是n；
    // 理解为 p指针指向一个长度为n的int类型数组。
    int aar[2][5] = {
            {1,  2,  3,  4},
            {11, 12, 13, 14, 15}
    };
    //声明并赋值
    int(*p)[5] = aar;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            //*(*(p+i)+j) 和aar[i][j]的值是一样的
            printf("%d,%d,%d     ", *(*(p + i) + j), p[i][j], aar[i][j]);

        }
        printf("\n");
    }


    //指针数组
    //[]的优先级最高，q[n]可以看作是长度为n的数组
    //而数组的类型是int * ，就是说数组的每个元素是int* 类型
    printf("关于指针数组的理解------》\n");
    //声明并赋值
    int *q[2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            q[i] = aar[i];
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d,%d,%d   ", *(*(q + i) + j), q[i][j], aar[i][j]);
        }
        printf("\n");
    }


}

/**
 * 字符串
 */
void test12() {
    //数组存在栈区
    char s1[] = "abc";//'\0'
    printf("sizeof %d\n", sizeof(s1));  //4  因为 字符串默认会有'\0'
    printf("strlen %d\n", strlen(s1));// 3 strlen 可以测量字符串的内容的长度

    char s2[] = "12345";
    strcpy(s2, "123");
    printf("s2 %s\n", s2);// 123
    printf("strcpy sizeof %d\n", sizeof(s2));// 6 整个字符串的长度包括"\0"
    printf("strcpy strlen %d\n", strlen(s2));// 3 遇到'\0'就结束了

}


/**
 * 指针常量和常量指针
 */
void test11() {
    printf("常量指针--------->重点是它是一个指针\n");
    int value = 1;
    //const 常量指针 就是指向的内容是常量，它不能指向变量，指向的内容不能改变，
    // 但是指针自身不是常量，指针自身的值可以改变，从而可以指向另一个常量
    const int *a = 2;
    int const *b = 3;

    printf("定义常量指针a= %d\n", a);

    //常量指针，只能换指向，不能改变指向的内容 ；常量指针是不能复制的
    //下面两种写法是改变指针的内容，编译报错,*a 就是指针指向的内容
//*a=value;

//下面写法是改变指针的指向，写法正确
    a = &value;
    printf("改变a的指向后 a= %d\n", *a);//输出为 1




    printf("指针常量------->重点它是个常量\n");
    int m = 111;
    //指针常量 指针本身是常量，它指向的地址是不可以改变的，但是地址的内容可以通过指针改变，
    //它指向的地址将伴其一生。
    //注意：指针常量必须在定义时付初始值。
    int *const p = &m;
    printf("定义指针常量p= %d\n", *p);
    *p = value;
    printf("改变p的值后p= %d\n", *p);//输出为 1

//下面写法是改变指针的指向，写法错误
//    p=&value;

}

void test10() {
    //s 是指针，在栈区域，"abc"是常量，在常量区
    char *s = "abc";
    fgets(s, 10, stdin);
    printf("str=%s\n", s);

}

void test09() {
    while (1) {
        char str[10];
        //每10个字节输出
        fgets(str, 10, stdin);//stdin 输入设备
        printf("str=%s\n", str);
    }

}

void test08() {
    char str[10];
    //会把空格当作输出
    gets(str);
    printf("str=%s\n", str);

}

void test07() {

    //注意控制输入的字节长度
    char str[10];
    while (1) {
        scanf("%s", str);
        printf("str=%s\n", str);
    }

}