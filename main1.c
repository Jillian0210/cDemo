#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


//�ṹ������-�ṹ����  PERSON��Person1����������ͬ
typedef struct PERSON {
    //���Զ����޷������� û��"����"
    unsigned int a;
    //��д��Ĭ��signed
    int b;
} Person1;

void test01() {

    printf("\n�����������������������������ṹ�塪��������������������������\n");

    Person1 *person1 = malloc(sizeof(Person1));
    //���ص�ռ�ÿռ��С��Ϊ����������ٵĴ�С������ֻ�����õ��Ŀռ�
    printf("��ӡ�ṹ��person�Ĵ�С��%d\n", sizeof(person1));//���Ϊ8
    person1->a = 44;
    person1->b = 22;

    printf("��ӡ�ṹ��ĳ�Ա����Ϊ��%d\n", person1->a);
    printf("��ӡ�ṹ��ĳ�Ա����Ϊ��%d\n", person1->b);


    //�ɴ˿�֪����Ľ��ۣ� sizeof���ص�ռ�ÿռ��С��Ϊ����������ٵĴ�С������ֻ�����õ��Ŀռ�
    int a = 1000000;
    printf("len:%llu\n", sizeof(a));
    printf("len:%llu\n", sizeof(int));
    printf("len:%llu\n", sizeof a);

    int arr[] = {10, 20, 30, 40, 50};
    printf("�����sizeof ��ȫ�������ݵĴ�С arr size:%llu\n", sizeof(arr));//20 5��int���͵ģ�һ��int����4���ֽ�


    //��������ĳЩ����µȼ���ָ�룬���齫�˻�Ϊָ��,�ں����ڲ����ٷ��������С
    int *pArr = arr;
    printf("array size: %llu\n", sizeof(pArr));
    printf("ָ��Ĵ�С�Ͳ���ϵͳ�йأ����64λ����ϵͳ����ôΪ8���ֽ� arr size:%llu\n", sizeof(pArr));
}

//ָ��
void test02() {
    printf("\n����������������������������ָ�롪��������������������������\n");
    int *p = 99;

    printf("��ӡpָ������ݣ����Ϊ��%d\n", p);//��ӡ���Ϊ 99
    printf("��ӡpָ��ĵ�ַ�����Ϊ��%p\n", p);//%p ��point ��ӡ�õ����ǵ�ַ 0x63
//    printf("%p\n",&p);
//    printf("%d\n",*p);

    int a = 10;
    printf("��ӡa�ĵ�ַ�����Ϊ��%p\n", &a); //��ӡ����a�ĵ�ַ 0x7ffeee28cb34  &��ȡ��ַ����˼

    p = &a; //pָ��a�ĵ�ַ
    printf("��ӡp�ĵ�ַ�����Ϊ��%p\n", p); //��ӡ�ĵ�ַ��a��һ�� 0x7ffeee28cb34
//    printf("%d\n",p);

//ָ��Ĵ�С�Ͳ���ϵͳ�йأ����64λ����ϵͳ����ôΪ8���ֽ�
    printf("��ӡָ��p��size�����Ϊ��%llu\n", sizeof(p));//���Ϊ8



    //void * ������ָ�� ����ָ���������͵�ָ��
    int b = 10;
    void *q = NULL;
    //����ʱ * ��ʾ����ָ�룻
    //�ڱ��ʽ��,*��ʾȡֵ,&��ʾȡ��ַ
    p = &a;
    //��int *����ʾǿתΪָ�����ͣ�*p��ȡp��ֵ
    printf("a��%d\n", *(int *) p);


}

void test03() {
    printf("\n����������������������������ָ���������͵ġ���������������������������\n");
    //ָ���������͵�
    int *p = NULL;
//    strcpy(p, "hhhh");//Process finished with exit code 11   ����������
}

void test04() {
    printf("\n����������������������������ָ�����;�����������������������������������\n");
    //ָ��Ĳ��� :ָ�����;�������
    int a = 0xaabbccdd;
    int *p1 = &a;
    char *p2 = &a;
    //%x��˼��16��������� ��16�������������ַ��
    printf("p1 %x\n", *p1);//aabbccdd
    printf("p2 %x\n", *p2);//ffffffdd

    printf("p1 %d\n", p1);// -290239684
    printf("p2 %d\n", p2);//-290239684

    printf("p1 %d\n", p1 + 1);//-290239680 ������ıȽϲ���4���ֽڣ�һ��int���͵Ĳ�����4��
    printf("p2 %d\n", p2 + 1);//-290239683  ������ıȽϲ���1���ֽڣ�һ��char���͵Ĳ�����1��


}


void test05() {
    printf("\n---------�����ָ��-------\n");
    //c��ʾָ���һ��Ԫ�صĵ�ַ��ֻ�ܶ�������д���������Ϊ����
    int c[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("*c=%d\n", *c);//����=ָ��
    printf("*(c+1)=%d\n", *(c + 1));

    printf("\nc=%d\n", c);
    printf("&c=%d\n", &c);
    printf("&c[0]=%d\n", &c[0]);

    printf("\n");
    int *p = c;
    for (int i = 0; i < 8; ++i) {
        printf("%d ,", p + i);//ȡ���ǵ�ַ����ַ֮��Ĳ�ֵ���ǲ���
    }
    printf("\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ,", *(p + i));//ȡ�ĵ�ַ��Ӧ��ֵ
    }
    printf("\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ,", p[i]);//ȡ����ֵ  ָ��=����
    }
    printf("\n");
};

//����ָ�룬�����еĴ�ŵ�Ԫ����ָ������
void test06() {
    printf("\n---------����ָ��-------\n");
    int a = 10;
    int b = 20;
    int c = 30;

    //����ָ�룬ָ���д�ŵ���a��b��c�ĵ�ַ
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    //��������ָ��aar
    int *aar[3] = {p1, p2, p3};

    //arr[0]==*aar
    printf("%d\n", aar[0]);//ȡ����һ����ַ
    printf("%d\n", *aar);//ȡ����һ����ַ
    //*arr[0]==**aar
    printf("%d\n", *aar[0]);//ȡ����һ��ֵ
    printf("%d\n", **aar);//ȡ����һ��ֵ

}

int main() {
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    return 0;
}





