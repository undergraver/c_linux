#include "int_vec.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	vector_int v(3);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		v.add(val);
	}
	v.display();
	return 0;
}
