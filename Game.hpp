/*
Title: Game Class
Author: Edwin Khew
Description: Game class declaration.
Date Created: 8/30/2021
*/

#ifndef GAME_H_
#define GAME_H_

template <class ItemType>
class Game
{
public:
	/*
		default constructor; randomly generates a dungeon map, places keys randomly, and randomly selects the 'start' and 'end' rooms
	*/
    Game();
    
    /*
    	displays all the details of the current game dungeon (all paths, key locations, start/end room locations)
    */
    void displayGame() const;
    
    /*
    	starts the game (story intro., show start room and its adjacent rooms, prompts user for their next move)
    */
    void startGame();
    
    /*
    	progresses the game (moves player to the next room, shows adjacent rooms, shows key count, prompts for next move, ends game when neccessary)
    	@param next_room_param, the next room the player wants to visit
    */
    void continueGame(std::string next_room_param);
    
    /*
    	ends the game (shows ending text)
    */
    void endGame();
private:
    Room<ItemType>* curr_room_ptr_; //pointer to the room the player is currently inside of
    int key_count_ = 0; //number of keys the player has found so far
};

#include "Game.cpp"
#endif