#include<iostream>

using namespace std;
class Dog {
	int a;
public:
	Dog(int num) : a{ num } {

	}
	int numget() {
		return a;
	}
	friend ostream& operator<<(ostream& os, const Dog& s);
};
ostream& operator<<(ostream& os, const Dog& s) {
	os << s.a;
	return os;
	 }

void change(Dog& a, Dog& b) {
	Dog temp = a;
	a = b;
	b = temp;
}

int main()
{
	Dog a{ 1 };
	Dog b{ 2 };
	change(a, b);

	cout << a << b << endl;
}