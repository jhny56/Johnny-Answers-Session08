#ifndef MAGE_H
#define MAGE_H

#include "player.h"

namespace N {

    class Mage : public Player {
    private:
        int Mana = 100;
        std::string Class = "Mage";

    public:
        // Default constructor
        Mage();

        // Parameterized constructor
        Mage(const std::string& name, const std::string& race);

        //this is a copy constructor
        // in order to pass the Mage object, it need to have a copy constructor, but in order
        // to have copy constructor, we need to have an object, so this is a dilema, we solve this
        // by using pass by reference & , we used const to say that this copy constructor, 
        // cannot change anything in the original object
        // check vid 13 time 16 min, she talks about copy objects and dynamic memory (pointer)
        Mage(const Mage& original);

        // Destructor
        ~Mage();

        // Decrease mana method
        void DecreaseMana(int value);

        // Override GetInfo method
        void GetInfo() const override;

        // Override TakeDamage method
        void TakeDamage(int damage) override;

        // Use a skill
        void UseSkill(const std::string& skill, Player& target) override;
    };

}

#endif // MAGE_H


