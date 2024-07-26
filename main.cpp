#include <iostream>
#include <list>
#include "player.h"
#include "mage.h"
#include "warrior.h"
#include <vector>

using namespace N;
using namespace std;

Player* createPlayer(int playerNumber) {
    cout << "Player " << playerNumber << ", choose your name: ";
    string playerName;
    cin >> playerName;

    cout << "Choose your class\n";
    cout << "1 - Mage\n";
    cout << "2 - Warrior\n";
    string playerClass;
    cin >> playerClass;

    cout << "Choose your race\n";
    cout << "1 - Elf\n";
    cout << "- - - Anything you want - - -\n";
    string playerRace;
    cin >> playerRace;

    Player* player;
    if (playerClass == "1") {
        player = new Mage(playerName, playerRace);
        player->AcquireSkill("Basic Attack", 0, "Mana");
        player->AcquireSkill("Light Attack", 15, "Mana");
        player->AcquireSkill("Fire Ball", 60, "Mana");
    } else if (playerClass == "2") {
        player = new Warrior(playerName, playerRace);
        player->AcquireSkill("Sword Strike", 30, "Stamina");
        player->AcquireSkill("Shield Block", 0, "Stamina");
        player->AcquireSkill("Battle Cry", 45, "Stamina");
    } else {
        cout << "Invalid class choice" << endl;
        exit(1);
    }
    return player;
}

void playerTurn(Player* player, Player* opponent) {
    cout << player->getName() << "'s turn. Choose a skill to use:\n";
    int index = 1;
    vector<string> skillNames;
    for (const auto& skill : player->getSkills()) {
        cout << index << " - " << skill.first << " (Damage: " << skill.second.first << ", Resource: " << skill.second.second << ")\n";
        skillNames.push_back(skill.first);
        index++;
    }

    int chosenIndex;
    cin >> chosenIndex;

    if (chosenIndex > 0 && chosenIndex <= skillNames.size()) {
        string chosenSkill = skillNames[chosenIndex - 1];
        if (Mage* magePlayer = dynamic_cast<Mage*>(player)) {
            magePlayer->UseSkill(chosenSkill, *opponent);
        } else if (Warrior* warriorPlayer = dynamic_cast<Warrior*>(player)) {
            warriorPlayer->UseSkill(chosenSkill, *opponent);
        }
    } else {
        cout << "Invalid skill choice.\n";
    }
}

int main()
{

    Player* player1 = createPlayer(1);
    Player* player2 = createPlayer(2);

    while (player1->getAlive() && player2->getAlive()) {
        playerTurn(player1, player2);
        if (!player2->getAlive()) {
            cout << player2->getName() << " has been defeated! " << player1->getName() << " wins!\n";
            break;
        }
        playerTurn(player2, player1);
        if (!player1->getAlive()) {
            cout << player1->getName() << " has been defeated! " << player2->getName() << " wins!\n";
            break;
        }
    }

    delete player1;
    delete player2;

    return 0;
}
