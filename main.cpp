/*��˳�����ɾ��������Сֵ��Ԫ�أ����ɺ������ر�ɾԪ�ص�ֵ��
�ճ���λ�������һ��Ԫ�������˳���Ϊ������ʾ������Ϣ���˳�����*/
#include <stdio.h>

typedef int ElemType;
#define MaxSize 10           //�������Ա����󳤶�


typedef struct {
    ElemType data[MaxSize];        //˳����Ԫ��
    int length;               //˳���ĵ�ǰ����
} SqList;                     //˳�������Ͷ���

bool Del_Min(SqList &L, int &value) {
    //ɾ��˳����е���СֵԪ�ؽ�㣬��ͨ�������Ͳ���value������ֵ
    if (L.length == 0)
        return false;             //��գ���ֹ��������
    value = L.data[0];
    int pos = 0;              //�ٶ�0��Ԫ�ص�ֵ��С
    for (int i = 1; i < L.length; i++)  //ѭ����Ѱ�Ҿ�����Сֵ��Ԫ��
        if (L.data[i] < value) {
            value = L.data[i];       //��valueʼ�ռ��䵱ǰ������Сֵ��Ԫ��
            pos = i;
        }
    L.data[pos] = L.data[L.length - 1];   //�ճ���λ�������һ��Ԫ���
    L.length--;
    return true;                        //��ʱvalue��Ϊ��Сֵ 
}

int main() {
    SqList L;
    L.length = 0;
    for (int & i : L.data) {
        scanf("%d", &i);
        L.length++;                  //ÿ����һ����˳���ĵ�ǰ���ȼ�1
    }
    int a;
    Del_Min(L, a);
    printf("˳�������СֵΪ:%d\n", a);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}
