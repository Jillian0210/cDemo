#include <stdio.h>
#include <stdlib.h>


void arrayDemo1();

void arrayDemo2();

void arrayDemo3();

void info(int arr[]);

void sizeofDemo();

int main() {

//    arrayDemo1();

//    arrayDemo2();

//    sizeofDemo();

    arrayDemo3();

    return 0;
}

void sizeofDemo() {
    int arr[] = {1, 2, 3};
    //开辟的数组空间大小 =数据类型*长度。——》4*3=12
    printf("%d \n", sizeof(arr));

    int *p = NULL;
    //开辟指针大小，64位系统的8个字节
    printf("%d \n", sizeof(p));

}

void arrayDemo3() {


    //& 运算， +1   运算步长    根据的是 数据类型决定！
    //数组类型的长度  =  数据类型 * 元素个数
    //+1   40   +1 40


    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("a = %d\n", sizeof(arr));//数组总大小 ——》数据类型 * 元素个数
    printf("b = %d\n", sizeof(arr[0]));//数组首元素大小 ——》首元素的数据类型
    printf("sz =a / b = %d\n", sizeof(arr) / sizeof(arr[0]));//数组元素个数
    printf("\n");
    //都一样
    printf("arr = %p\n", arr);//数组首元素地址
    printf("&arr = %p\n", &arr);//数组首元素地址
    printf("&arr[0] = %p\n", &arr[0]);//数组首元素地址
    printf("\n");
    printf("************************ +1 *******************************\n");//分割线
    printf("arr + 1 = %p  \n", arr + 1);//下一个int的地址
    printf("&arr + 1 = %p  \n", &arr + 1);//跳过数组后的地址
    printf("&arr[0] + 1 = %p  \n", &arr[0] + 1);//下一个int的地址
    printf("\n");
    printf("************************步长*******************************\n");//分割线
    printf("arr 步长%d\n", (int) (arr) - (int) (arr + 1));
    printf("&arr 步长%d\n", (int) (&arr) - (int) (&arr + 1));//跳过整个数组后紧挨着的地址

    //总结：
    // int aar[];
    //1、aar数组名，打印aar地址，&aar地址，&aar[0]都是元素的首地址
    //2、aar 地址是元素首地址，步长为元素长度
    //3、&aar[0]  对第一个元素取地址，步长元素类型长度
    //4、&aar 对aar取地址，这个地址指向的数组，所以步长位数组长度


    //此时该地址减去首元素地址等于数组大小
    printf("\n\n");
    printf("************************ 函数 *******************************\n");//分割线
    info(arr);

}


//int arr[]  等价于  int* arr  长度固定 8
//传递是指针
// 把数组的首地址，做成一个指针，然后扔指针到函数，也就是没有数组概念
void info(int arr[]) {
    printf("a = %d\n", sizeof(arr));//数组降维成指针后的指针大小，在64位系统下指针都为8字节
    printf("b = %d\n", sizeof(arr[0]));//数组首元素的大小  arr[0]----> int *p=aar;p=p+1;
    printf("sz =a / b  = %d\n", sizeof(arr) / sizeof(arr[0]));//大小为8/4=2;
    printf("arr = %p\n", arr);//数组首元素地址
    printf("arr + 1 = %p  \n", arr + 1);//下一个元素的地址
    printf("&arr + 1 = %p  \n", &arr + 1);//下一个元素的地址
    printf("arr 步长%d\n", (int) (arr + 1) - (int) (arr));//4 就是元素类型int
    printf("&arr 步长%d\n", (int) (&arr + 1) - (int) (&arr)); //8 就是指针类型  arr就是一个指针了
}

void arrayDemo2() {
    //[行数][列数]
    int arr1[3][4];
    //创建二维数组行数可以不写,如果不写行数，需要初始化，至少要写个大括号
//    int arr2[][5];
    int arr2[][5] = {};


    //二维数组赋值
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr1[i][j] = i * 4 + j;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", arr1[i][j]);
        }
    }

    //二维数组在内存空间布局上，也是线性连续且递增的；二维数组本质上也是一位数组
}

void arrayDemo1() {
    // 一维数组
    //c和java不同的是，java定义长度为多少，就只能使用多少个，否则数组越界
    //c可以直接”越界“，要理解，c中的数组本质就是指针，指向首地址，[n] 运算符号就是首地址往后移动多少个单位
    //也就是说c里面的数据是我们自己控制的。
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[1] = {1, 2};
    int aar10[6] = {1, 2, 3};

    //下面几个在内存上的区别：
    //（1）aar3和aar4的区别：
    //arr3最后有\n 也就是用00来表示字符串结束，aar4没有，所以两个的大小不一样。
    //指定长度如果刚好和初始化元素一样，不会有结束标识位；如果指定长度大于初始化的元素个数，那么剩余的补0
    //（2）aar3和p的区别：
    //aar3是把常量区的”abcdef“拷贝到栈区
    //p存储的是常量区“abcedf”的地址,所以在循环的时候最好使用指针来接收字符串常量。
    char arr3[] = "abcdef";
    char arr4[6] = "abcdef";
    char *p = "abcdef";

    //连续空间管理
    char *arr7 = malloc(5);//分配5个连续空间
    arr7[0] = 100;//第一个空间赋值




}

void memoryDemo() {
    char a = 4;
    //有跨类型的时候，char补足为四个
    int b = 5;

    int e = 6;
    char *p = &a;
    char *p1 = &b;

    char c = p - p1;
    printf("%d\n", c);
//    int d=p-p1;
//    printf("%d\n",d);

}

void stringDemo() {
    char *str1 = "I love China";
    char str2[] = "I love China";
    //61fde8,61fddb 两个地址不一样，说明不是同一个常量
    printf("%x,%x", &str1, &str2);
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
