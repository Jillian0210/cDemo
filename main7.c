#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//stat 结构体，获取文件的大小
#include <sys/stat.h>

//64k 每次读取的文件的大小
#define BLOCK_SIZE 1024*64

int main(int agrc, char **argv) {

    //    argv[0]
    printf("file write \n");
    char *path1 = "./../test/input.mp4";
    FILE *pr = fopen(path1, "rb");
//    printf("path1=%s",argv[1]);
    if (pr == NULL) return 0;

    char *path2 = "./../test/output.mp4";
    FILE *pw = fopen(path2, "wb");
//    printf("path2=%s",argv[2]);
    if (pw == NULL) return 0;


    struct stat st = {0};
    stat(path1, &st);
    //获取文件的大小
    int size = st.st_size;
    printf("file size %d\n", size);
    if (size > BLOCK_SIZE) {
        //如果文件的太大，分为多次进行读写
        size = BLOCK_SIZE;
    }
    //malloc 内存空间不会设置为0
    //calloc 内存会设置为0
    char *buf = calloc(1, size);
    unsigned int index = 0;
    while (!feof(pr)) {
        int res = fread(buf, 1, size, pr);
        fwrite(buf, 1, res, pw);
        index++;
    }
    printf("file read count=%d\n",index);

    free(buf);
    fclose(pw);
    fclose(pr);
    pw=NULL;
    pr=NULL;

    return 0;
}
