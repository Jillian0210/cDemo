#include <stdio.h>
#include <stdlib.h>


//指针的定义
void test1() {

    //一般情况从右边向左边集合

    int p1;
    //返回整型的数组
    int *p2;
    //整型数据组成的数组
    int p3[3];

    //指针数组。注意p是数组
    // p4[] 是个数组，
    // *p4[]说明数组的元素是指针类型，
    // int *p4[] 数组元素的指针指向的类型是整型
    int *p4[4];

    //数组指针，注意p是指针
    //(*p44)是个指针
    //（*p44）[] 指针指向的是数组
    // int（*p44）[] 数组的类型是int
    int (*p44)[4];

    //*p5  是个指针
    //**p5 说明指针指向的元素的类型是指针类型
    //int **p5 说明二级指针指向的元素的类型是整型
    int **p5;

    //p6() 说明p是一个函数，函数的入参是整型变量
    //int p6() 说明返回值也是整型
    int p6(int);

    //*p 是个指针
    //(*p)(int) 指针指向的是一个函数，且函数的参数是int类型
    //int（*p）(int)  函数返回的类型是整型
    int (*p7)(int);

    //p8(int) 是一个函数 函数的入参是int类型
    //（*p8（int））说明返回值是指针，
    //（*p8（int））[] 返回值的指针指向的是数组
    //  int (*p8(int))[] 返回值的指针指向的数组的内容是整型数据
    int (*p8(int))[3];


    //指针的类型：就是把指针名字去掉的类型
    //指针指向数据的类型：把指针名字和名字左边的声明*去掉
    //指针指向的类型决定我们的步长
    int *ptr;//指针的类型是int *  指向类型的名字是 int
    char *ptr1;//指针的类型是char *  指向类型的名字是 char
    int **ptr3;//指针的类型是int **  指向类型的名字是 int*
    int(*ptr4)[3];//指针的类型是int(*)[3]  指向类型的名字是 int*()


    //pInt:0x0
    //pInt:0x4
    int *pInt;
    printf("pInt:%p\n", pInt);
    pInt++;
    printf("pInt:%p\n", pInt);


    //pChar:0x0
    //pChar:0x1
    double *pChar;
    printf("pChar:%p\n",pChar);
    pChar++;
    printf("pChar:%p\n",pChar);


    //指针的都是8个字节
    int **p11;
    printf("p11:%p\n",sizeof(*p11));
    int **p22;
    printf("p22:%p\n",sizeof(*p22));


    //左值 右值

    //野指针： 没有初始化的指针  指向的内容是个垃圾数，它的地址是随机的 每次打印的都不一样
    int *p33;
    printf("p33:%p\n",p33);
    //悬空指针：

    //null指针

}


int main() {
    test1();
    return 0;
}
