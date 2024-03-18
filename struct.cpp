#include <iostream>

struct person {
    int id = 0;
    std::string name = "None";
    std::string location = "None";
};


int main () {
    person p;
    p.name = "Person's name";
    p.location = "Somewhere";
    p.id = 1;

    std::cout << "Name: " << p.name << std::endl;
    return 0;
}