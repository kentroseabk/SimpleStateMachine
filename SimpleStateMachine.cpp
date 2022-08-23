// SimpleStateMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Enemy.h"

using namespace std;

int main()
{
    Enemy enemy;
    enemy.SetPlayerSpotted(true);

    int input;

    bool done = false;
    string instructions = "1. Attack, 2. Wait, 3. Quit";

    do
    {
        cout << instructions << endl;
        enemy.GetCurrentState()->Print(&enemy);

        cin >> input;

        switch (input)
        {
        case 1:
            cout << "1. Attack" << endl;
            enemy.TakeDamage(25.0f);
            break;
        case 2:
            cout << "2. Wait" << endl;
            break;
        case 3:
            cout << "3. Quit" << endl;
            done = true;
        }

        enemy.SwitchState();

        if (!enemy.IsAlive())
        {
            done = true;
        }
    } while (!done);
}
