#include <stdio.h>
#include <stdlib.h>

//宏定义
#define add1(x,y) x+y
#define add2(x,y) ((x)+(y))

void test1(){
    //数组指针和指针数组

    int a=0;
    int *p;
    int **p1;

    p=&a;
    *p=10;

    printf("p:%p\n",p);
    p++;//+4个字节
    printf("p:%p\n",p);
    p1++;//+8个字节 p1指针指向的类型是int* 是8个字节
    printf("p:%p\n",p1);

    //指针可以强转 int* 和char* 都是指针，指针的长度都是8个字节
    char **p2=&p;


}
void test2(){
    //aar先和[]结合，因为[]的优先级大于*
    //数组指针  一个数组中的元素都是指针 而指针指向的数据是int类型，所以步长是int的步长
    //指针自身的类型int*  指向的类型是int
    int *arr[4]={1,2,3,4};
    int *arr1=arr;
//    arr++； //这种写法是错误的，因为arr是常量，不能++
    printf("arr:%p\n",arr);
    arr1++;//+4个字节 因为指向的类型是int类型是4个字节
    printf("arr1:%p\n",arr1);


    char charP[6]={'a','b','c','d'};
    //指针数组  自身类型是char(*)[4], 指向的类型是一个数组char[4] 那么步长是数组的长度
    char (*p3)[4]=&charP;
    printf("p3:%p\n",p3);
    p3++;//+4 个字节，数组从长度是4
    printf("p3:%p\n",p3);

}

void test3(){
    //栈区
    int b=0;
    //栈区 系统管理的
    int arr2[3]={10,11,12};
    //放在堆区域 自己释放
    char *c=malloc(100);
    //栈的自下往上，地址升高，栈的入口在下面,
    //所以先入栈的地址高，后入栈的地址低
    //a1=-289350884
    //a2=-289350888
    //a3=-289350892
    //a4=-289350896
    int a1=1;
    int a2=2;
    int a3=3;
    int a4=4;
    printf("a1=%d\n",&a1);
    printf("a2=%d\n",&a2);
    printf("a3=%d\n",&a3);
    printf("a4=%d\n",&a4);

    //堆 从下往上是由低到高的
    char *aar=malloc(4);
    for (int i = 0; i < 4; ++i) {
        printf("aar %p\n",aar+i);
    }
}

void test4(){
    //一个方法调用就是开辟一块栈区，调用结束会出栈
    //对于有些小而频繁的函数就会反复的入栈出栈，影响性能
    //解决的方式是进行宏定义，注意宏定义是在编译的时候进行源码的替换，不具有方法调用的优先问题
    printf("x+y*30=%d\n",add1(1,2)*30);
    printf("((x)+(y))*30=%d\n",add2(1,2)*30);

}

/**
 * 二级指针
 */
void  test5(){

}

int main() {

    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
