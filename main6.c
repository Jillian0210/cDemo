#include <stdio.h>
#include <stdlib.h>

//int * �����Ի���int[] ,��Ϊ��c��int[] �ǳ��������ܽ��и�ֵ�����ԣ�c�У����鲻����Ϊ�����ķ���ֵ
int *test1() {
    int a[3] = {1, 2, 3};
    return a;
}


/**
 *
 * @return
 */
int main() {

    //д������ԭ����int[]�ǳ�������������Ϊ�����ķ���ֵ
//    int[] fun(int);

//д������ԭ���ǣ������Ԫ�س�������һ���⣬ÿ��Ԫ����ռ�õ��ڴ�ռ�Ҳ������ͬ��
// fun1 ��һ������5��Ԫ�ص����飬��������Ԫ�ض��Ǻ�����
// ��Ȼ����������һ���������޷����ֺ�����ռ�õĿռ���ͬ��
//    int fun1[5](void);

//c--->.o---->.exe �ļ�
    printf("file write ����������������������������������������������������\n");
    //д�ļ� wһ����Сд��  �Զ���ֵ�ķ�ʽ��� wb
    FILE *p = fopen("./test/write.txt", "w");
    if (p) {
        printf("��Ҫд����ļ�����\n");
        fputc('a', p);
        fputc("bbbb", p);
        //�ļ�����
        fclose(p);
        //p ����ָ�� �ڴ汻������
        //����һ��Ҫ��ΪNULL
        p = NULL;

    } else {
        //�ļ�������
        printf("��Ҫд���ļ�������\n");
    }


    printf("file read ��������������������������������������������������\n");
    FILE *p1 = fopen("./test/read.txt", "r");
    if (p1) {
        printf("��Ҫ�������ļ�����\n");
        while (1) {
            char c = fgetc(p1);
            if (c == EOF) {
                //�ļ��Ľ�β EOF
                printf("read complete\n");
                break;
            }
            printf("char %c\n", c);
        }

    } else {
        printf("��ȡ���ļ�������\n");
    }
    //ע��ر��ļ����ͷ�ָ��
    fclose(p1);
    p1 = NULL;


    printf("file copy ����������������������������������������������������\n");
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
    //ע��һ��Ҫ�ر��ļ����ͷ�ָ��
    fclose(sourceP);
    fclose(targetP);
    sourceP = NULL;
    targetP = NULL;


    //��ȡ��Ҫ���е��ļ�,ʹ�û�����ȥ��
    printf("file buffer������������������������������������������������");
    FILE *huanhangP = fopen("./test/huanhang.txt", "w");
    if (huanhangP) {
        char buffer[100] = {0};
//        while (1) {
//            //���ļ��ж�ȡһ�У�����buffer�������У�
//            fgets(buffer, sizeof(buffer), huanhangP);
//
//            if (feof(huanhangP)) {//�����ж��ļ��Ƿ񵽴���ĩβ
//                break;
//            }
//
//            int a = 0;
//            char b = 0;
//            int c = 0;
            //��ʽ����ȡ
//            fscanf(buffer,"%d %c %d",&a,&b,&c);
//            printf("a %d b %c c %d",a,b,c);
//        }
        fclose(huanhangP);
        huanhangP=NULL;
    }



    return 0;
}
