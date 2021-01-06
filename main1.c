#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


//结构体类型-结构类型  PERSON和Person1（别名）相同
typedef struct PERSON {
    //可以定义无符号类型 没有"负号"
    unsigned int a;
    //不写，默认signed
    int b;
} Person1;

void test01() {

    printf("——————————————结构体——————————————\n");

    Person1 *person1 = malloc(sizeof(Person1));
    //返回的占用空间大小是为这个变量开辟的大小，而不只是它用到的空间
    printf("打印结构体person的大小：%d\n", sizeof(person1));//结果为8
    person1->a = 44;
    person1->b = 22;

    printf("打印结构体的成员变量为：%d\n", person1->a);
    printf("打印结构体的成员变量为：%d\n", person1->b);


    int a = 10;
    printf("len:%lu\n", sizeof(a));
    printf("len:%lu\n", sizeof(int));
    printf("len:%lu\n", sizeof a);

    int arr[] = {10, 20, 30, 40, 50};
    printf("数组的sizeof 是全部的数据的大小 arr size:%d\n", sizeof(arr));//20 5个int类型的，一个int类型4个字节


    //数组名在某些情况下等价于指针，数组将退化为指针,在函数内部不再返回数组大小
    int *pArr = arr;
    printf("array size: %d\n", sizeof(pArr));
    printf("指针的大小和操作系统有关，如果64位操作系统，那么为8个字节 arr size:%d\n", sizeof(pArr));
}

//指针
void test02() {
    printf("——————————————指针——————————————\n");
    int *p = 99;

    printf("打印p指向的内容，结果为：%d\n", p);//打印结果为 99
    printf("打印p指向的地址，结果为：%p\n", p);//%p 是point 打印得到的是地址 0x63
//    printf("%p\n",&p);
//    printf("%d\n",*p);

    int a = 10;
    printf("打印a的地址，结果为：%p\n", &a); //打印的是a的地址 0x7ffeee28cb34  &是取地址的意思

    p = &a; //p指向a的地址
    printf("打印p的地址，结果为：%p\n", p); //打印的地址和a的一样 0x7ffeee28cb34
//    printf("%d\n",p);

//指针的大小和操作系统有关，如果64位操作系统，那么为8个字节
    printf("打印指针p的size，结果为：%d\n", sizeof(p));//结果为8



    //void * 无类型指针 可以指向任意类型的指针
    int b = 10;
    void *q = NULL;
    //声明时 * 表示声明指针；
    //在表达式中，*表示取值；&表示取地址
    p = &a;
    //（int *）表示强转为指针类型，*p，取p的值
    printf("a：%d\n", *(int *) p);


}

void test03() {
    //指针是有类型的
    int *p = NULL;
    strcpy(p, "hhhh");//Process finished with exit code 11   发生错误了
}

void test04() {
    //指针的步长 :指针类型决定步长
    int a = 0xaabbccdd;
    int *p1 = &a;
    char *p2 = &a;
    //%x意思是16进制bai输出du（ 以16进制输出变量地址）
    printf("p1 %x\n", *p1);//aabbccdd
    printf("p2 %x\n", *p2);//ffffffdd

    printf("p1 %d\n", p1);// -290239684
    printf("p2 %d\n", p2);//-290239684

    printf("p1 %d\n", p1 + 1);//-290239680 和上面的比较差了4个字节，一个int类型的步长是4个
    printf("p2 %d\n", p2 + 1);//-290239683  和上面的比较差了1个字节，一个char类型的步长是1个


}


void test05() {
    //
    printf("---------数组和指针-------\n");
    //c表示指向第一个元素的地址；只能读，不能写，可以理解为常量
    int c[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d\n", *c);//数组=指针
    printf("%d\n", *(c + 1));

    printf("c=%d\n", c);
    printf("&c=%d\n", &c);
    printf("&c[0]=%d\n", &c[0]);

    int *p = c;
    for (int i = 0; i < 8; ++i) {
        printf("%d ,", p + i);//取的是地址，地址之间的差值就是步长
    }
    printf("\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ,", *(p + i));//取的地址对应的值
    }
    printf("\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ,", p[i]);//取的是值  指针=数组
    }

};

//数组指针，数组中的存放的元素是指针类型
void test06() {
    printf("---------数组指针-------\n");
    int a = 10;
    int b = 20;
    int c = 30;

    //定义指针，指针中存放的是a，b，c的地址
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    //定义数组指针aar
    int *aar[3] = {p1, p2, p3};

    //arr[0]==*aar
    printf("%d\n", aar[0]);//取出第一个地址
    printf("%d\n", *aar);//取出第一个地址
    //*arr[0]==**aar
    printf("%d\n", *aar[0]);//取出第一个值
    printf("%d\n", **aar);//取出第一个值

}

int main() {
//    test01();
//    test02();
////    test03();
//    test04();
//    test05();
//    test06();
    return 0;
}





