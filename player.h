#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <list>

namespace N {

    class Player {
        private:
        protected:
            std::string Name;
            std::string Race;
            int Health = 100;
            std::list<std::string> Skills;
            bool Alive = true;

        public:
            // Default constructor
            Player();

            // Parameterized constructor
            Player(const std::string& name, const std::string& race);

            // Virtual destructor
            virtual ~Player() {}

            // Get information about the player
            virtual void GetInfo() const;

            // Acquire a new skill
            void AcquireSkill(const std::string& skill);

            // Pure virtual function to take damage
            virtual void TakeDamage(int damage) = 0;

            // Friend function for output
            friend std::ostream& operator<<(std::ostream& COUT, const Player& player);

            // Getter for Name
            std::string getName() const;

            // Getter for Race
            std::string getRace() const;

            // Getter for Health
            int getHealth() const;

            // Getter for Alive
            bool getAlive() const;

            // Getter for Skills
            std::list<std::string> getSkills() const;
    };

}

#endif // PLAYER_H
