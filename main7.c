#include <stdio.h>
#include <unistd.h>


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

    printf("copy");




    return 0;
}
