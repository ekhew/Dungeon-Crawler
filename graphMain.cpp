/*
Title: Play the Dungeon Crawler!
Author: Edwin Khew
Description: Dungeon crawler test file.
Date Created: 8/30/2021
*/

#include <iostream>
#include "Room.hpp"
#include "Graph.hpp"
#include "Game.hpp"

using namespace std;

int main()
{
    Game<string> myGame;

    myGame.displayGame();
    myGame.startGame();
}