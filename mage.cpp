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

}
