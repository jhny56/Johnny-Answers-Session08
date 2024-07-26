#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <map>

namespace N {

    class Player {
        private:
        protected:
            std::string Name;
            std::string Race;
            int Health = 100;
             std::map<std::string, std::pair<int, std::string>> Skills;
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
           void AcquireSkill(const std::string& skill, int damage, const std::string& resourceType);

            // Use a skill
            virtual void UseSkill(const std::string& skill, Player& target) = 0;

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
            std::map<std::string, std::pair<int, std::string>> getSkills() const;
    };

}

#endif // PLAYER_H
