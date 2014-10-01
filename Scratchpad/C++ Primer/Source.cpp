#include <iostream>
#include <string>
using namespace std;


string swap(string&);
string swap(const string&);


class Car {
public: 
	int test;
	Car() : test(5) {};
	Car(int Wheels) : test(Wheels) {
		numberOfWheels = Wheels;
	};
	static void foo(int a) {};
	void foo2() {};

private:
	int numberOfWheels;
};

class House {};


void a(Car c) {
	// Car c is passed by value
}

void b(Car *c) {
	// Car c is passed by reference
}

void c(const Car& c) {
	// Unchangeable const reference
}


int main() {
	int val = 5;
	int sum = 0;
	while (val <= 10)
		sum += val, val++;
}