/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) test file.
Date Created: 7/11/2021
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