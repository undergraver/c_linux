#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ages;

    ages["Alice"] = 30;
    ages["Bob"] = 25;

    std::string s = "Ana";
    s += "001";
    ages[s] = 300;
    ages.insert(std::pair{"007",7});

    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << "\n";
    }

    for (auto it = ages.begin(); it != ages.end(); it++ )
    {
	    std::cout << "Name " << it->first << " has " << it->second <<  " years\n";
    }


    std::string searchFor("Bob");
    const auto& it = ages.find(searchFor);
    if (it != ages.end())
    {
	std::cout << "Found to be " << it->second << " years old\n";
    }
    else
    {
	std::cout << searchFor << " not found\n" ;
    }

    searchFor+="1";

    const auto &it2 = ages.find(searchFor);
    if (it2 != ages.end())
    {
	std::cout << "Found to be " << it2->second << " years old\n";
    }
    else
    {
	std::cout << searchFor << " not found\n" ;
    }

    return 0;
}
