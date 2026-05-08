#include <iostream>
#include <vector>

int main()
{
    // Create a vector containing integers
    std::vector<int> v = {8, 4, 5, 9};
    std::cout << "Vector has " << v.size() <<  " elements" << std::endl;
 
    // Add two more integers to vector
    v.push_back(6);
    v.push_back(9);
    
    // Overwrite element at position 2
    v[2] = -1;
 
    // Print out the vector
    for (int n : v) // <====> for (int i=0;i<v.size();i++) int n = v[i];
        std::cout << n << ' ';
    std::cout << '\n';
    std::vector<int>::const_iterator it;
    it = v.begin();
    while( it != v.end() )
    {
	std::cout << *it << std::endl;
	it++;
    }

    std::vector<std::vector<int>> vv;

    std::vector<std::vector<int>>::iterator it2;

    auto it3 = vv.begin();
    return 0;
}
