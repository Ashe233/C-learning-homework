#include<iostream>
using namespace std;
int main() {
	double height, weight, age;                  //�����������õ��ı���
	cout << "��������� ���� ����"<<endl;
	cin >> height >> weight >> age;              //�������
	cout <<"���ߵ�ƽ��ֵΪ"<< (height + weight + age) / 3.0;   //����ƽ��ֵ�����
	return 0;
}