#include "mage.h"

namespace N {

    // Default constructor
    Mage::Mage() {
        Name = "not set";
        Race = "not set";
    }

    // Parameterized constructor
    Mage::Mage(const std::string& name, const std::string& race) : Player(name, race) {}

    // Copy constructor
    Mage::Mage(const Mage& original) : Player(original.Name, original.Race) {}

    // Destructor
    Mage::~Mage() {
        std::cout << Name << " has been destroyed" << std::endl;
    }

    // Decrease mana method
    void Mage::DecreaseMana(int value) {
        Mana -= value;
        if (Mana < 0) {
            Mana = 0;
        }
    }

    // Override GetInfo method
    void Mage::GetInfo() const {
        Player::GetInfo();
        std::cout << "Class : " << Class << std::endl;
        std::cout << "Mana : " << Mana << std::endl;
    }

    // Override TakeDamage method
    void Mage::TakeDamage(int damage) {
        Health -= damage;
        if (Health <= 0) {
            Health = 0;
            Alive = false;
        }
    }

    // Use a skill
    void Mage::UseSkill(const std::string& skill, Player& target) {
        if (Skills.find(skill) != Skills.end() && Skills[skill].second == "Mana") {
            int damage = Skills[skill].first;
            if (Mana >= damage) {
                DecreaseMana(damage);
                std::cout << Name << " used " << skill << " on " << target.getName() << " for " << damage << " damage, Mana left: " << Mana << std::endl;
                target.TakeDamage(damage);
            } else {
                std::cout << "Not enough Mana to use " << skill << std::endl;
            }
        } else {
            std::cout << "Skill not found or incorrect resource type" << std::endl;
        }
    }

}
