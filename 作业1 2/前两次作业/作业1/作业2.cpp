//������ݹ����׳�
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int jnum(int n);
int main()
{
    srand(time(nullptr)); // �õ�ǰʱ����Ϊ����
    int min, max;
    cout << "������������ķ�Χ����Сֵ�����ֵ��";
    cin >> min >> max;
    //int randomValue = (rand() % (max - min)) + min;//��Χ[min,max)
    int num = (rand() % (max - min + 1)) + min;//����ѡ�÷�Χ[min,max]
    //randomValue = (rand() % (max - min)) + min + 1;//��Χ(min,max]
    cout <<"�����" << num << "�Ľ׳�Ϊ" << jnum(num);
}

int jnum(int n) {  //����һ������ ͨ���ݹ�����׳�
    if (n != 1) return n * jnum(n - 1);//���N��Ϊ1 ��ô�ͷ���N*N-1 ͨ������n-1�ٴε���������� �Ϳ���ʵ�ֵݹ�
    else if (n == 1) return 1;//���N=1 ֱ�ӷ���1 ����n�ݼ���1 �Ǽ�������
}