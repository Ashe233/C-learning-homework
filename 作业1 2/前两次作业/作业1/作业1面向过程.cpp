#include<iostream>
using namespace std;
int main() {
	double height, weight, age;                  //定义三个会用到的变量
	cout << "请输入身高 体重 年龄"<<endl;
	cin >> height >> weight >> age;              //输入变量
	cout <<"三者的平均值为"<< (height + weight + age) / 3.0;   //计算平均值并输出
	return 0;
}