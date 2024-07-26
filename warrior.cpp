#include "warrior.h"

namespace N {

    // Default constructor
    Warrior::Warrior() {
        Name = "not set";
        Race = "not set";
    }

    // Parameterized constructor
    Warrior::Warrior(const std::string& name, const std::string& race) : Player(name, race) {}

    // Copy constructor
    Warrior::Warrior(const Warrior& original) : Player(original.Name, original.Race) {}

    // Destructor
    Warrior::~Warrior() {
        std::cout << Name << " has been destroyed" << std::endl;
    }

    // Decrease stamina method
    void Warrior::DecreaseStamina(int value) {
        Stamina -= value;
        if (Stamina < 0) {
            Stamina = 0;
        }
    }

    // Override GetInfo method
    void Warrior::GetInfo() const {
        Player::GetInfo();
        std::cout << "Class : " << Class << std::endl;
        std::cout << "Stamina : " << Stamina << std::endl;
    }

    // Override TakeDamage method
    void Warrior::TakeDamage(int damage) {
        Health -= damage;
        if (Health <= 0) {
            Health = 0;
            Alive = false;
        }
    }

    // Use a skill
    void Warrior::UseSkill(const std::string& skill, Player& target) {
        if (Skills.find(skill) != Skills.end() && Skills[skill].second == "Stamina") {
            int damage = Skills[skill].first;
            if (Stamina >= damage) {
                DecreaseStamina(damage);
                if(damage == 0) damage=20;

                std::cout << Name << " used " << skill << " on " << target.getName() << " for " << damage << " damage, Stamina left: " << Stamina << std::endl;
                target.TakeDamage(damage);
            } else {
                std::cout << "Not enough Stamina to use " << skill << std::endl;
            }
        } else {
            std::cout << "Skill not found or incorrect resource type" << std::endl;
        }
    }

}
