#include<iostream>
#include<string>
using namespace std;
/*
区别在于对于不同的访问权限和成员可见性的影响。

公有继承：

派生类继承的基类成员在派生类中的访问权限保持不变，即公有成员仍然是公有的，保护成员仍然是保护的。
公有继承能够继承基类的公有成员和保护成员，但不继承基类的私有成员。
通过公有继承，派生类对象可以访问基类的公有成员和保护成员，但无法直接访问基类的私有成员。

保护继承：

派生类继承的基类成员在派生类中的访问权限被降低为保护权限，即公有成员变为保护成员，私有成员仍然是私有的。
保护继承能够继承基类的公有成员和保护成员，但不继承基类的私有成员。
通过保护继承，派生类对象无法直接访问基类的公有成员，只能通过派生类的成员函数来访问。

私有继承：

派生类继承的基类成员在派生类中的访问权限被降低为私有权限，即公有成员和保护成员均变为私有成员。
私有继承能够继承基类的公有成员和保护成员，但不继承基类的私有成员。
通过私有继承，派生类对象无法直接访问基类的公有成员和保护成员，只能通过派生类的成员函数来访问。

公有继承保持了基类成员的原有访问权限，保护继承将基类公有成员变为保护成员，私有继承将基类公有成员和保护成员都变为私有成员。
公有继承用于实现"是一个"关系，保护继承用于实现"属于"关系，私有继承用于实现"实现了"关系。
无论使用哪种继承方式，基类的私有成员都不会被继承。
在派生类中，可以通过派生类的成员函数来访问继承的成员，但具体的访问权限受到继承方式的影响。
*/
int main() {

	class Vehicle {
	private:
		float speed;
	protected:
		int CarryHowManyPeople;
		string whatisthiscar;
	public:
		Vehicle(float sp, int peo, string car) {
			speed = sp;
			CarryHowManyPeople = peo;
			whatisthiscar = car;
		}
		void show() {
			cout << "for your veh:\n" << "it is a:" << this->whatisthiscar << endl << "it can carry" << this->CarryHowManyPeople << "people\n";
		}
	};

	class truck :public Vehicle {
	public:
		truck(float speed1, int carry, string vehclass) :Vehicle(speed1, carry, vehclass) {}
		bool carrygoods(int num) {
			return true;
		}
	};

	class car :protected Vehicle {
	public:
		car(float speed1, int carry, string vehclass) :Vehicle(speed1, carry, vehclass) {
		}
		bool carrypeople(int num) {
			return true;
		}
		void showcar() {
			cout << "for your veh:\n" << "it is a:" << this->whatisthiscar << endl << "it can carry" << this->CarryHowManyPeople << "people\n";
		}
	};

	class pickup :private car, private truck {
	public:
		pickup(float speed1, int carry, string vehclass) :car(speed1, carry, vehclass), truck(speed1, carry, vehclass) {}
		bool carrypeoplepk(int num) {
			return true;
		}
		bool carrygoodspk(int num) {
			return true;
		}
	};
	float sp = 100;
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
			if (aveh.carrygoods(1)) cout << "it can carry goods.\n";
		}
		else if (carclass == "car") {
			car aveh(sp, carry, carclass);
			//aveh.show();此时不可访问。
			aveh.showcar();
			if (aveh.carrypeople(1)) cout << "it can only carry people.\n";
		}
		else if (carclass == "pickup") {
			pickup aveh(sp, carry, carclass);
			pickup* avehptr = &aveh;
			car* v = (car*)(avehptr);
			//v->show();此时不可访问
			//if (aveh.carrygoods(1)) cout << "it can carry goods.\n";不可访问
			//if (aveh.carrygoods(1)) cout << "it can carry people.\n";不可访问
			v->showcar();
			if (aveh.carrygoodspk(1)) cout << "it can carry goods.\n";
			if (aveh.carrypeoplepk(1)) cout << "it can carry people.\n";


		}
		else {
			cout << "Wrong.Reinput pls.";
			continue;
		}

	}
	return 0;
}