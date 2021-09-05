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
    void startGame();
    void continueGame(std::string next_room);
    void endGame();
private:
    Room<ItemType>* curr_room_ptr_; //the room the player is currently in
    int key_count_ = 0; //number of keys the player has found so far
};

#include "Game.cpp"
#endif