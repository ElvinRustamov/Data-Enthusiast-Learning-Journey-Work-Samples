// Const with Classes

#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() const{
        return name;
    }

    void set_name(std::string name_val) {
        name = name_val;
    }

    // Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
    :Player("None", 0, 0) {}

Player::Player(std::string name_val)
        :Player{name_val, 0, 0} {}

Player::Player(std::string name_val, int health_val, int xp_val)
        :name{name_val}, health{health_val}, xp{xp_val} {}

int main () {
    const Player villain {"Villain", 100, 55};
    Player hero {"Hero", 100, 15};

//    villain.set_name("New Name"); Error: passing 'const Player' as 'this' argument discards qualifiers
//    villain.get_name(); Error
    std::cout << hero.get_name() << std::endl;
    std::cout << villain.get_name() << std::endl;


    return 0;
}