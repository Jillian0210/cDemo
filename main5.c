#include <stdio.h>
#include <string.h>
void test1() {
    printf("————————————————————————————————————————————————\n");
    //字符串数组
    char *msg = "hello world";
    printf("%s\n", msg);
    int i = 0;
    while (*msg != '\0') {
        //注意是'\0',不是"\0"
        printf("第%d个为：%c，", i++, *msg++);
    }
    printf("\n");
}

void test2() {
    printf("————————————————————————————————————————————————\n");
    //在c中，没有字符串类型，都是用字符数组来表示的
    //定义字符串方式：
    //方式1：定义字符数组，每个位置依次赋值字符，并且在最后一位手动加'\0',
    //在栈里面
    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("str %s\n", str);
    //方式2：定义字符数组，直接赋值字符串，不需要手动加'\0'
    //该方式 还是在栈区，相当于开辟了6个区域，每个区域放一个字符元素，最后一个元素是'\0'
    char str1[6] = "hello";
    printf("str1 %s\n", str1);
    //方式3：定义字符指针,这时*str2指针变量在栈区域，存放地址，这个地址就是"hello"在常量区的位置
    char *str2 = "hello";
    //可以
    str2 = "aaa";
    printf("str2 %s\n", str2);
    //不可以
//    *str2="bbb";
    printf("str2 %s\n", str2);
}

void test3() {
    printf("————————————————————————————————————————————————\n");
    while (1) {
        char str3[10];
        //会通过空格或者回车进行分隔
        scanf("%s", str3);
        printf("str3=%s\n", str3);
    }
}

void test4() {
    printf("————————————————————————————————————————————————\n");
//不安全
    char str4[10];
    gets(str4);
    printf("str4=%s\n", str4);
}

void test5() {
    printf("————————————————————————————————————————————————\n");
    while (1) {
        char str5[10];
        //每10个字节输出
        fgets(str5, 10, stdin);
        printf("str5=%s\n", str5);
    }

}

/**
 * 常量指针 和指针常量
 */
void test6() {
    //常量指针,指向常量的指针，指针可以修改指向，但是指向的内容是常量（内容不可以修改）
    int a = 10;
    int b = 20;
    int const *p = &a;
    const int *p1 = &a;
    p = &b;
//    *p = b;

    //指针常量，不能修改指向，
    //能修改指向的内容 指针本身是常量，而指针就是地址，所以它指向地址是不变的，但是该地址的内容是可以改变的
    int *const p2;
    *p2 = b;
//    p2 = &b;

//总结一句：constant 修饰谁，谁就是常量，它就不能变。


}

//字符串
void test7() {

    char s1[]="abcdefg";
    //算上'\0'
    printf("sizeof %d\n",sizeof(s1));//8
    //内容的长度
    printf("strlen %lu\n",strlen(s1));//7

    //注意拷贝的时候第二个参数要比第一个参数的长度小
    strcpy(s1,"opq");
    printf("s1=%s\n",s1);//opq

    //sizeof 算得是整个数组的长度
    //本来s1 数组的装的是： abcefg\0
    //strcpy 拷贝后，s1数组变成了： opq\0efg\0
    printf("sizeof %d\n",sizeof(s1));//8
    //strlen 算得是碰到第一个\0之前的长度
    printf("strlen %lu\n",strlen(s1));//3

    printf("%d\n",s1[3]);
    printf("%d\n",s1[7]);

}

/**
 * 字符串
 * @return
 */
int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();

//    test6();
    test7();
    return 0;

}
