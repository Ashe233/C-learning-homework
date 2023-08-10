#include <iostream>
using namespace std;
class Student {                    //定义一个名为student的类
private:                           //这个类包含这些private的内容 都用double存储 便于计算
    double height, weight, age;
public:
    Student(double h,double w,double a) {   //初始化
        height = h;
        weight = w;
        age = a;
    }
    ~Student() {}
    double Average() {               //“对象”计算平均值的“动作”
        double avg = (height + weight + age) / 3.0;
        return avg;
    }
};
int main()
{
    double h, w, a;
    cout << "输入身高 体重 年龄" << endl;
    cin >> h >> w >> a;                              //输入数据
    Student stu(h,w,a);                         //定义stu 并传入刚才输入的数据
    cout << "平均值为：" << stu.Average() << endl;        //输出
    return 0;
}