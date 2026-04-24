#include "int_vec.h"
#include <iostream>

using namespace std;

void redisplay(GenericVector<int> p)
{
	p.display();
}


int main()
{
	int n;
	GenericVector<int> v(3),w(2);
	GenericVector<int> q(v);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		v.add(val);
	}
	v.display();
	w = v;
	cout << "After w was assigned v's value" << endl;
	w.add(465);
	w.display();
	cout << "Before redisplay\n";
	redisplay(v);
	cout << "After redisplay\n";

	return 0;
}
