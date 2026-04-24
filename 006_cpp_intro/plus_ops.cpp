#include "int_vec.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	GenericVector<int> v(3),w(2);
	cout << "Size v=";
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		v.add(val);
	}
	v.display();
	cout << "Size w=";
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		w.add(val);
	}
	w.display();

	GenericVector<int> a = v + w;
	a.display();


	a+=w;
	a.display();


	return 0;
}
