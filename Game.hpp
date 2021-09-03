/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) class declaration.
Date Created: 7/11/2021
*/

#ifndef GAME_H_
#define GAME_H_

template <class ItemType>
class Game
{
public:
    Game();
    void displayGame() const;
private:
    Room<ItemType>* curr_room_; //the room the player is currently in
};

#include "Game.cpp"
#endif
