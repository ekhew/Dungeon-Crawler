/*
Title: Dungeon Class
Author: Edwin Khew
Description: Dungeon class declaration.
Date Created: 8/30/2021
*/

#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <map>
#include <list>
#include <vector>

template <class ItemType>
class Dungeon
{
public:
    /*
        default constructor
    */
    Dungeon();

    /*
        adds a new room to the dungeon
        @param room_name, name of the new room to be added
    */
    void addRoom(ItemType room_name);

    /*
        removes a room from the dungeon
        @param room_name, name of the room to be removed
    */
    void removeRoom(ItemType room_name);

    /*
        adds a path connecting two rooms
        @param room1, first room
        @param room2, second room
    */
    void addPath(ItemType room1, ItemType room2);

    /*
        removes a path connecting two rooms
        @param room1, first room
        @param room2, second room
    */
    void removePath(ItemType room1, ItemType room2);

    /*
        checks if the dungeon is currently empty (no rooms)
        @return true if the dungeon is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        checks if two specified rooms are adjacent
        @param room1, first room
        @param room2, second room
        @return 'true' if the rooms are adjacent, and 'false' otherwise
    */
    bool checkAdj(ItemType room1, ItemType room2) const;

    /*
        prints every adjacent room of the specified room
        @param room_name, name of the room to print every adjacent room of
    */
    void printAdjVertices(ItemType room_name) const;

    /*
        traverses the dungeon using BFS and prints every room
        @param start, the room to start the traversal from
    */
    void BFS(ItemType start) const;

    /*
        traverses the dungeon using DFS and prints every room; iterative approach
        @param start, the room to start the traversal from
    */
    void iterativeDFS(ItemType start) const;

    /*
        prints out every adjacency list that makes up the graph/dungeon
    */
    void display() const;

	/*
		returns a pointer to a random room
		@return pointer to random room
	*/
    Room<ItemType>* getRandomRoomPtr();
    
    /*
    	returns the pointer to a specified room
    	@param room_name, name of the room to get the pointer to 
    	@return pointer to the specified room
    */
    Room<ItemType>* getRoomPtr(std::string room_name);
    
    /*
    	sets keys into three random rooms
    */
    void setRandomKeys();
    
    /*
    	sets a random room as the 'end' room
    */
    void setRandomEnd();
    
    /*
    	adds a path that connects two random rooms
    */
    void addRandomPath();
    
    /*
    	displays the rooms that contain the keys
    */
    void displayKeys();
    
    /*
    	displays the room that is the 'end' room
    */
    void displayEnd();
private:
    std::map<Room<ItemType>, std::list<Room<ItemType>>> graph_; //map of vertex - adjacency lists pairs
    std::vector<Room<ItemType>*> ptr_vector_; //vector of pointers to rooms
};

#include "Dungeon.cpp"
#endif