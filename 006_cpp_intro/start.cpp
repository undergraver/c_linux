#include <iostream>

using namespace std;

class Example {
public:
int x;// anyone can access this
Example(int _x,int _y, int _z)
{
	set_values(_x,_y,_z);
	cout << "Example constructor with params" << endl;
}
Example()
{
	x = y = z = 0;
	cout << "Example constructor" << endl;
}
~Example()
{
	cout << "Example destructor" << endl;
}

void set_values(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void show_values()
{
	cout << "x=" << x << ";y=" << y << ";z=" << z << endl;
}

private:
int y;// only class internal functions cand access this - and friend functions / classes
protected:
int z;// derived classes can access this - and friend functions / classes
};


class Derived : public Example
{
public:
	Derived() : Example(1,2,3)
	{
		cout << "Derived constructor" << endl;
	}
	~Derived()
	{
		cout << "Derived destructor" << endl;
	}
};

int main()
{
	cout << "Before scope" << endl;

	cout << "Val=";
	int val;
	cin >> val;
/*
	struct mystruct x;
....
	struct mystruct y;
	y = x; // memcpy style
*/
	if (val != 0)
	{
		Example e;
        	cout << e.x << endl;;
		e.show_values();
	}

	Derived d;
	d.show_values();

	cout << "After scope" << endl;
	return 0;
}
