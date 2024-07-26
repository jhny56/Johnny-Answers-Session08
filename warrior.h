#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"

namespace N {

    class Warrior : public Player {
    private:
        int Stamina = 100;
        std::string Class = "Warrior";

    public:
        // Default constructor
        Warrior();

        // Parameterized constructor
        Warrior(const std::string& name, const std::string& race);

        // Copy constructor
        Warrior(const Warrior& original);

        // Destructor
        ~Warrior();

        // Decrease stamina method
        void DecreaseStamina(int value);

        // Override GetInfo method
        void GetInfo() const override;

        // Override TakeDamage method
        void TakeDamage(int damage) override;

        // Use a skill
        void UseSkill(const std::string& skill, Player& target) override;

    };

}

#endif // WARRIOR_H
