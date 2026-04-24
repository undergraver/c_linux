#include "int_vec.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	GenericVector<int> v(3);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		v.add(val);
	}
	v.display();

	GenericVector<double> d(800);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		double val;
		cin >> val;
		d.add(val);
	}
	d.display();

	return 0;
}
