#include <iostream>
#include <list>

int main() {
    std::list<int> l = {1, 2, 3};

    l.push_back(4);   // add at end
    l.push_front(0);  // add at beginning

    for (int x : l) {
        std::cout << x << " ";
    }
}

