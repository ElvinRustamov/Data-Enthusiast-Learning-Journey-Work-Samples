// Constructors

#include <iostream>
#include <string>
#include <vector>

class Player {
private:
    // Attributes
    std::string name;
    int health;
    int xp;
public:
    void set_name(std::string name_val) {
        name = name_val;
    }

    // Overloaded Constructors
    Player() {
        std::cout << "No args constructor called" << std::endl;
    }

    Player(std::string name) {
        std::cout << "String arg constructor called" << std::endl;
    }

    Player(std::string name, int health, int xp) {
        std::cout << "Three args constructor called" << std::endl;
    }

    // Destructor
    ~Player() {
        std::cout << "Desctructor called for " << name << std::endl;
    }
};

int main () {
//    Player x;
//    x.set_name("X");

//    Player y;
//    y.set_name("Y");

    Player *enemy = new Player("enemy", 1000, 300);
    enemy ->set_name("Enemy");

    delete enemy;

    return 0;
}

