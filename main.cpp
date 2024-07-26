#include <iostream>
#include <list>
#include "player.h"
#include "mage.h"

using namespace N;
using namespace std;

int main()
{
    cout << "Choose Your Name: ";
    string playerName;
    cin >> playerName;

    cout << "Choose Your Class\n";
    cout << "1 - Mage\n";
    cout << "- - - no other class - - -\n";
    string playerClass;
    cin >> playerClass;

    cout << "Choose Your Race\n";
    cout << "1 - Elf\n";
    cout << "- - - Anything you want - - -\n";
    string playerRace;
    cin >> playerRace;

    Mage player(playerName, playerRace);

    player.AcquireSkill("Basic Attack");
    player.AcquireSkill("Light Attack");
    player.AcquireSkill("Fire Ball");

    player.TakeDamage(10);

    // Use default constructor
    Mage player2;

    player2.AcquireSkill("Basic Attack");
    player2.AcquireSkill("Light Attack");
    player2.AcquireSkill("Fire Ball");

    player2.TakeDamage(10);

    cout << player << player2;

    Mage mage(player); // Copy constructor
    cout << mage;

    // system("pause>0"); // This is specific to Windows and not recommended for cross-platform code
    return 0;
}
