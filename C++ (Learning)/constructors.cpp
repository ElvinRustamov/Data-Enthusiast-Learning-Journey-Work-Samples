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
//    Player() {
//        std::cout << "No args constructor called" << std::endl;
//    }
//
//    Player(std::string name) {
//        std::cout << "String arg constructor called" << std::endl;
//    }
//
//    Player(std::string name, int health, int xp) {
//        std::cout << "Three args constructor called" << std::endl;
//    }


//    Player();
//    Player(std::string name_val);
//    Player(std::string name_val, int health, int xp_val);

    // Constructor with default values
    Player(std::string name_val="None", int healt=0, int xp_val=0);

    // Destructor
    ~Player() {
        std::cout << "Desctructor called for " << name << std::endl;
    }
};

//Player::Player()
// : Player {"None", 0, 0} {
// std::cout << "No-args constructor" << std::endl;
//}
//
//Player::Player(std::string name_val)
// : Player {name_val, 0, 0} {
//    std::cout << "One args constructor" << std::endl;
//}

Player::Player(std::string name_val, int health, int xp_val)
 : name{name_val}, health{health}, xp{xp_val} {
}

int main () {
//    Player x;
//    x.set_name("X");

//    Player y;
//    y.set_name("Y");

//    Player *enemy = new Player("enemy", 1000, 300);
//    enemy ->set_name("Enemy");
//    delete enemy;

    Player empty;
    Player elvin {"Elvin"};
    Player villain ("Villain", 100, 55);
    Player here {"Hero", 55};


    return 0;
}

