//随机数递归计算阶乘
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int jnum(int n);
int main()
{
    srand(time(nullptr)); // 用当前时间作为种子
    int min, max;
    cout << "请输入随机数的范围，最小值和最大值：";
    cin >> min >> max;
    //int randomValue = (rand() % (max - min)) + min;//范围[min,max)
    int num = (rand() % (max - min + 1)) + min;//这里选用范围[min,max]
    //randomValue = (rand() % (max - min)) + min + 1;//范围(min,max]
    cout <<"随机数" << num << "的阶乘为" << jnum(num);
}

int jnum(int n) {  //定义一个函数 通过递归来求阶乘
    if (n != 1) return n * jnum(n - 1);//如果N不为1 那么就返回N*N-1 通过参数n-1再次调用这个函数 就可以实现递归
    else if (n == 1) return 1;//如果N=1 直接返回1 这是n递减到1 是计算的起点
}