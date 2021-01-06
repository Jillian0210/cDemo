#include <stdio.h>
#include <stdlib.h>

//int * 不可以换成int[] ,因为在c中int[] 是常量，不能进行赋值。所以，c中，数组不能作为函数的返回值
int *test1() {
    int a[3] = {1, 2, 3};
    return a;
}


/**
 *
 * @return
 */
int main() {

    //写法错误：原因是int[]是常量，不可以作为函数的返回值
//    int[] fun(int);

//写法错误：原因是：数组的元素除了类型一样外，每个元素所占用的内存空间也必须相同；
// fun1 是一个具有5个元素的数组，这个数组的元素都是函数，
// 虽然函数的类型一样，但是无法保持函数所占用的空间相同。
//    int fun1[5](void);

//c--->.o---->.exe 文件
    printf("file write ——————————————————————————\n");
    //写文件 w一定是小写的  以二进值的方式则加 wb
    FILE *p = fopen("./test/write.txt", "w");
    if (p) {
        printf("需要写入的文件存在\n");
        fputc('a', p);
        fputc("bbbb", p);
        //文件存在
        fclose(p);
        //p 悬在指针 内存被销毁了
        //所以一定要改为NULL
        p = NULL;

    } else {
        //文件不存在
        printf("需要写的文件不存在\n");
    }


    printf("file read —————————————————————————\n");
    FILE *p1 = fopen("./test/read.txt", "r");
    if (p1) {
        printf("需要读出的文件存在\n");
        while (1) {
            char c = fgetc(p1);
            if (c == EOF) {
                //文件的结尾 EOF
                printf("read complete\n");
                break;
            }
            printf("char %c\n", c);
        }

    } else {
        printf("读取的文件不存在\n");
    }
    //注意关闭文件，释放指针
    fclose(p1);
    p1 = NULL;


    printf("file copy ——————————————————————————\n");
    FILE *sourceP = fopen("./test/source.txt", "r");
    FILE *targetP = fopen("./test/target.txt", "w");
    if (sourceP == NULL || targetP == NULL) {
        return -1;
    }
    while (1) {
        char c = fgetc(sourceP);
        if (c == EOF) {
            printf("copy complete\n");
            break;
        }
        fputc(c, targetP);
    }
    //注意一定要关闭文件，释放指针
    fclose(sourceP);
    fclose(targetP);
    sourceP = NULL;
    targetP = NULL;


    //读取需要换行的文件,使用缓冲区去读
    printf("file buffer————————————————————————");
    FILE *huanhangP = fopen("./test/huanhang.txt", "w");
    if (huanhangP) {
        char buffer[100] = {0};
//        while (1) {
//            //从文件中读取一行，放在buffer缓冲区中，
//            fgets(buffer, sizeof(buffer), huanhangP);
//
//            if (feof(huanhangP)) {//用于判断文件是否到达了末尾
//                break;
//            }
//
//            int a = 0;
//            char b = 0;
//            int c = 0;
            //格式化读取
//            fscanf(buffer,"%d %c %d",&a,&b,&c);
//            printf("a %d b %c c %d",a,b,c);
//        }
        fclose(huanhangP);
        huanhangP=NULL;
    }



    return 0;
}
