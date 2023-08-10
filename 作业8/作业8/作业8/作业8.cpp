#include<iostream>
#include<string>
using namespace std;
/*
虚基类：
用于解决多重继承中的菱形继承问题。当一个派生类从多个基类继承，而这些基类又有一个共同的基类时，为了避免出现多个实例的问题，可以将这个共同的基类声明为虚基类。虚基类的特点是：

虚基类在派生类中只有一个实例。
虚基类的构造函数由最终派生类负责调用。
虚基类的成员在最终派生类中只有一份拷贝。

虚函数：
虚函数用于实现运行时多态性。通过在基类中声明虚函数，派生类可以重写该函数，从而实现基于对象类型的动态调用。虚函数的特点是：

声明为虚函数的成员函数可以在派生类中被重写。
使用基类指针或引用调用虚函数时，实际调用的是派生类中的函数。
虚函数通过虚函数表实现，每个对象都有一个指向虚函数表的指针。

纯虚函数：
纯虚函数是在基类中声明的没有实际实现的虚函数。纯虚函数的特点是：
纯虚函数在基类中没有具体的实现，只提供一个接口。
派生类必须实现纯虚函数才能成为具体的类。
含有纯虚函数的类被称为抽象类，抽象类不能被实例化。
可以通过将纯虚函数赋值为0来声明纯虚函数，例如：virtual void func() = 0;。

虚函数和纯虚函数只能在类中声明，而虚基类则是在类的继承声明中使用。这些特性在C++中为实现多态性和继承提供了灵活性和可扩展性。
*/
int main() {

	class Vehicle {
	private:
		float speed;
		int CarryHowManyPeople;
	protected:
		string whatisthiscar;
	public:
		Vehicle(float sp, int peo,string car) {
			speed = sp;
			CarryHowManyPeople = peo;
			whatisthiscar = car;
		}
		void show() {
			cout << "for your veh:\n" << "it is a:" << this->whatisthiscar << endl << "it can carry " << this->CarryHowManyPeople << " people\n";
		}
		virtual bool carrygoods()=0;
		virtual bool carrypeople()=0;
	};

	class truck :virtual public Vehicle {
	public:
		truck(float speed1, int carry, string vehclass) :Vehicle(speed1, carry, vehclass) {}
		bool carrygoods() {
			return true;
		}
		bool carrypeople() {
			return false;
		}
	};

	class car :virtual public Vehicle {
	public:
		car(float speed1, int carry, string vehclass) :Vehicle(speed1, carry, vehclass){
		}
		bool carrygoods() {
			return false;
		}
		bool carrypeople() {
			return true;
		}
	};

	class pickup :public car, public truck {
	public:
		pickup(float speed1, int carry, string vehclass) :car(speed1, carry, vehclass), truck(speed1, carry, vehclass) , Vehicle(speed1, carry, vehclass) {}
		bool carrygoods() {
			return true;
		}
		bool carrypeople() {
			return true;
		}
	};
	float sp=100;
	int carry;
	string carclass;
	while (1) {
		cout << "chose a class vehicle to create(car/truck/pickup):\n";
		cin >> carclass;
		cout << "can carry how many people:\n";
		cin >> carry;
		if (carclass == "truck") {
			truck aveh(sp, carry, carclass);
			aveh.show();
			if (aveh.carrygoods()) cout << "it can carry goods.\n";
			else cout << "cant carry goods\n";
			if (aveh.carrypeople()) cout << "it can carry people.\n";
			else cout << "cant carry people\n";
		}
		else if (carclass == "car") {
			car aveh(sp, carry, carclass);
			aveh.show();
			if (aveh.carrygoods()) cout << "it can carry goods.\n";
			else cout << "cant carry goods\n";
			if (aveh.carrypeople()) cout << "it can carry people.\n";
			else cout << "cant carry people\n";
		}
		else if (carclass == "pickup") {
			pickup aveh(sp, carry, carclass);
			pickup* avehptr = &aveh;
			car* v = (car*)(avehptr);
			v->show();
			if (aveh.carrygoods()) cout << "it can carry goods.\n";
			else cout << "cant carry goods\n";
			if (aveh.carrypeople()) cout << "it can carry people.\n";
			else cout << "cant carry people\n";
		}
		else {
			cout << "Wrong.Reinput pls.";
			continue;
		}
		
	}
	return 0;
}
