#include <stdio.h>
#include <stdlib.h>

void test1(int arr[], int size) {
    //c中，数组没有边界
    for (int i = 0; i < size; ++i) {
        printf("【验证数组没有边界】arr:%d\n", arr[i]);
    }
}

void func(int a, int b) {
    printf("【验证函数名即为地址】%d %d \n", a, b);
}


int func1(int a, int b) {
//    printf("%d+%d=\n",a,b,a+b);
    return a + b;
}

//函数指针作为参数，c中的函数指针相当于java的接口回调
int func2(int a, int b, int (*callback)(int)) {
    int result = a + b;
    callback(result);
}

int call(int a) {
    printf("【函数指针作为参数相当于回调】我是函数指针指向的函数 %d\n", a);
}


//宏定义 申明函数
typedef int FUNC(int, int);

//具体的函数实现
void func4(int a, int b) {
    printf("【宏定义调用函数】%d，%d\n", a, b);
}


int jia(int a, int b) {
    return a + b;
}

int jian(int a, int b) {
    return a - b;
}

int cheng(int a, int b) {
    return a * b;
}

int chu(int a, int b) {
    return a / b;
}

int  changeTojia(int (*p)(int,int)){
    p=jia;
}

int  changeTojia2(int (**p)(int,int)){
    *p=jia;
}
/**
 * 函数
 *
 * @return
 */
int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    test1(arr, 6);

    printf("————————————————————————————————————————————————\n");
    func(10, 20);
    //指向类型为void时，返回值是代码区域 下面三种打印方式是一样的
    //定义函数，那么系统就会为这个函数分配一段存储空间，这段存储空间的首地址就是函数的地址，用函数名来表示
    printf("函数名 即为地址：%p\n", func);
    printf("&函数名 即为地址： %p\n", &func);
    printf("*函数名 即为地址：%p\n", *func);
    //函数返回类型为int时，函数名称还是函数的地址，函数存储空间的首地址
    int result = func1(10, 20);
    printf("函数名为地址和返回值无关：%d\n", func1);
    printf("func1的结果为：%d\n", result);

    printf("————————————————————————————————————————————————\n");
    //函数指针的使用,函数返回值类型 (* 指针变量名) (函数参数列表);
    //（1）函数指针 声明一个指针，（*p） ，前面加函数的返回值，后面添加参数。
    void (*p)(int, int);
    //（2）给该指针复制对应的函数
    p = func;
    //（3）调用该函数指针，并传递参数
    p(10, 20);

    //函数指针为参数
    func2(10, 20, call);


    printf("————————————————————————————————————————————————\n");
    //宏定义 申明函数指针 *p2，并且指向 func4函数
    FUNC *p2 = func4;
    //可以 指针名（参数）方式调用
    p2(10, 20);
    //可以 函数名（参数）方式调用
    func4(10, 20);
    (&func4)(10, 20);
    (*func4)(10, 20);
    //可以 *指针名（参数）方式调用
    (*p2)(10, 20);
    printf("p2 =（*p2）=fun4=（&fun4）=（*fun4）\n ");

    printf("————————————————————————————————————————————————\n");
    //函数指针数组存在的意义，观察者模式，相当于啊a，b参数变化后，每个函数的变化。
    //定义一个
    int (*pn[4])(int a, int b)={jia,jian,cheng,chu};
    int a=30;
    int b=20;
    for (int i = 0; i < 4; ++i) {
        printf("%d\n",pn[i](a,b));
    }


    printf("————————————————————————————————————————————————\n");
    int (*pn1)(int a,int b)=jia;
    printf("1+2=%d\n",pn1(1,2));
    pn1=jian;
    printf("1-2=%d\n",pn1(1,2));

    //改变指针变量直接传递指针参数是无法改变指针变量的
    changeTojia(pn1);
    printf("changeTojia 1+2=3? %d\n",pn1(1,2));
    //改变指针变量需要传递二级指针（指针的地址）作为参数
    changeTojia2(&pn1);
    printf("changeTojia2 1+2=3? %d\n",pn1(1,2));

    printf("————————————————————————————————————————————————\n");
    //字符串数组
    char *msg="hello world";
    printf("%s\n",msg);
    int i=0;
    while (*msg!='\0'){
        //注意是'\0',不是"\0"
        printf("第%d个为：%c，",i++,*msg++);
    }

    printf("\n");
    char charArray[]={'H','e','l','l','o','\0'};
    printf("%d",charArray[5]);

    return 0;
}
