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
    //���ٵ�����ռ��С =��������*���ȡ�������4*3=12
    printf("%d \n", sizeof(arr));

    int *p = NULL;
    //����ָ���С��64λϵͳ��8���ֽ�
    printf("%d \n", sizeof(p));

}

void arrayDemo3() {


    //& ���㣬 +1   ���㲽��    ���ݵ��� �������;�����
    //�������͵ĳ���  =  �������� * Ԫ�ظ���
    //+1   40   +1 40


    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("a = %d\n", sizeof(arr));//�����ܴ�С �������������� * Ԫ�ظ���
    printf("b = %d\n", sizeof(arr[0]));//������Ԫ�ش�С ��������Ԫ�ص���������
    printf("sz =a / b = %d\n", sizeof(arr) / sizeof(arr[0]));//����Ԫ�ظ���
    printf("\n");
    //��һ��
    printf("arr = %p\n", arr);//������Ԫ�ص�ַ
    printf("&arr = %p\n", &arr);//������Ԫ�ص�ַ
    printf("&arr[0] = %p\n", &arr[0]);//������Ԫ�ص�ַ
    printf("\n");
    printf("************************ +1 *******************************\n");//�ָ���
    printf("arr + 1 = %p  \n", arr + 1);//��һ��int�ĵ�ַ
    printf("&arr + 1 = %p  \n", &arr + 1);//���������ĵ�ַ
    printf("&arr[0] + 1 = %p  \n", &arr[0] + 1);//��һ��int�ĵ�ַ
    printf("\n");
    printf("************************����*******************************\n");//�ָ���
    printf("arr ����%d\n", (int) (arr) - (int) (arr + 1));
    printf("&arr ����%d\n", (int) (&arr) - (int) (&arr + 1));//�����������������ŵĵ�ַ

    //�ܽ᣺
    // int aar[];
    //1��aar����������ӡaar��ַ��&aar��ַ��&aar[0]����Ԫ�ص��׵�ַ
    //2��aar ��ַ��Ԫ���׵�ַ������ΪԪ�س���
    //3��&aar[0]  �Ե�һ��Ԫ��ȡ��ַ������Ԫ�����ͳ���
    //4��&aar ��aarȡ��ַ�������ַָ������飬���Բ���λ���鳤��


    //��ʱ�õ�ַ��ȥ��Ԫ�ص�ַ���������С
    printf("\n\n");
    printf("************************ ���� *******************************\n");//�ָ���
    info(arr);

}


//int arr[]  �ȼ���  int* arr  ���ȹ̶� 8
//������ָ��
// ��������׵�ַ������һ��ָ�룬Ȼ����ָ�뵽������Ҳ����û���������
void info(int arr[]) {
    printf("a = %d\n", sizeof(arr));//���齵ά��ָ����ָ���С����64λϵͳ��ָ�붼Ϊ8�ֽ�
    printf("b = %d\n", sizeof(arr[0]));//������Ԫ�صĴ�С  arr[0]----> int *p=aar;p=p+1;
    printf("sz =a / b  = %d\n", sizeof(arr) / sizeof(arr[0]));//��СΪ8/4=2;
    printf("arr = %p\n", arr);//������Ԫ�ص�ַ
    printf("arr + 1 = %p  \n", arr + 1);//��һ��Ԫ�صĵ�ַ
    printf("&arr + 1 = %p  \n", &arr + 1);//��һ��Ԫ�صĵ�ַ
    printf("arr ����%d\n", (int) (arr + 1) - (int) (arr));//4 ����Ԫ������int
    printf("&arr ����%d\n", (int) (&arr + 1) - (int) (&arr)); //8 ����ָ������  arr����һ��ָ����
}

void arrayDemo2() {
    //[����][����]
    int arr1[3][4];
    //������ά�����������Բ�д,�����д��������Ҫ��ʼ��������Ҫд��������
//    int arr2[][5];
    int arr2[][5] = {};


    //��ά���鸳ֵ
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

    //��ά�������ڴ�ռ䲼���ϣ�Ҳ�����������ҵ����ģ���ά���鱾����Ҳ��һλ����
}

void arrayDemo1() {
    // һά����
    //c��java��ͬ���ǣ�java���峤��Ϊ���٣���ֻ��ʹ�ö��ٸ�����������Խ��
    //c����ֱ�ӡ�Խ�硰��Ҫ��⣬c�е����鱾�ʾ���ָ�룬ָ���׵�ַ��[n] ������ž����׵�ַ�����ƶ����ٸ���λ
    //Ҳ����˵c����������������Լ����Ƶġ�
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[1] = {1, 2};
    int aar10[6] = {1, 2, 3};

    //���漸�����ڴ��ϵ�����
    //��1��aar3��aar4������
    //arr3�����\n Ҳ������00����ʾ�ַ���������aar4û�У����������Ĵ�С��һ����
    //ָ����������պúͳ�ʼ��Ԫ��һ���������н�����ʶλ�����ָ�����ȴ��ڳ�ʼ����Ԫ�ظ�������ôʣ��Ĳ�0
    //��2��aar3��p������
    //aar3�ǰѳ������ġ�abcdef��������ջ��
    //p�洢���ǳ�������abcedf���ĵ�ַ,������ѭ����ʱ�����ʹ��ָ���������ַ���������
    char arr3[] = "abcdef";
    char arr4[6] = "abcdef";
    char *p = "abcdef";

    //�����ռ����
    char *arr7 = malloc(5);//����5�������ռ�
    arr7[0] = 100;//��һ���ռ丳ֵ




}

void memoryDemo() {
    char a = 4;
    //�п����͵�ʱ��char����Ϊ�ĸ�
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
    //61fde8,61fddb ������ַ��һ����˵������ͬһ������
    printf("%x,%x", &str1, &str2);
}

void operateDemo() {
    int a = 15;
    int b = 255;
    int c = 315;

    int *p = &a;

    //6422036, 6422032,6422028
    printf("%d, %d,%d\n", &a, &b, &c);

    //ջ�����ķ����ǴӴ�С
    p = p - 1;
    //6422032
    printf("%d\n", p);

    //255
    printf("%d\n", *p);
    //��ȡ��p��ֵ����ӡ������֮������p=p+1;ע��p��ָ�룬ָ��ļӼ�������ǶԵ�ַ���в�����
    //255
    printf("%d\n", *p++);
    //15
    printf("%d\n", *p);

    //255
    //255
    //�ȼ���p=p-1;Ȼ��ȡ��p��ֵ����ӡ������
    printf("%d\n", *--p);
    printf("%d\n", *p);


    printf("-------------------\n");
    //����ָ����мӼ���ֻ��������ǵĵ�ַ���ĸ���
    int *p1 = &a;
    int *p2 = &c;
    int p3 = p1 - p2;
    printf("p1-p2=%d(��int)\n", p3);

    char *p5 = &a;
    char *p6 = &c;
    int p7 = p5 - p6;
    printf("p5-p6=%d(��char)\n", p7);


    //������������ָ�����ʹ�С��һ������ô����ʱ�Ѵ��ǿת��С��
    int *p8 = &a;
    char *p9 = &c;
    int p10 = (char *) p8 - p9;
    printf("p8-p9=%d(��char)\n", p10);
}
