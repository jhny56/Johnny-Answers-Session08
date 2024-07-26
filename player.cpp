#include "player.h"

namespace N {

    // Default constructor
    Player::Player() : Name("not set"), Race("not set") {}

    // Parameterized constructor
    Player::Player(const std::string& name, const std::string& race) : Name(name), Race(race) {}

    // Get information about the player
    void Player::GetInfo() const {
        std::cout << "Name : " << Name << std::endl;
        std::cout << "Race : " << Race << std::endl;
        std::cout << "Health : " << Health << std::endl;
        std::cout << "Alive : " << std::boolalpha << Alive << std::endl;

        std::cout << "Skills : " << std::endl;
        for (const std::string& skill : Skills) {
            std::cout << "   " << skill << std::endl;
        }
    }

    // Acquire a new skill
    void Player::AcquireSkill(const std::string& skill) {
        Skills.push_back(skill);
    }

    // Getter for Name
    std::string Player::getName() const { return Name; }

    // Getter for Race
    std::string Player::getRace() const { return Race; }

    // Getter for Health
    int Player::getHealth() const { return Health; }

    // Getter for Alive
    bool Player::getAlive() const { return Alive; }

    // Getter for Skills
    std::list<std::string> Player::getSkills() const { return Skills; }

    // Friend function to output player information
    std::ostream& operator<<(std::ostream& COUT, const Player& player) {
        player.GetInfo();
        return COUT;
    }

}
