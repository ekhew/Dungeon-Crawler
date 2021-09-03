/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) class implementation.
Date Created: 7/11/2021
*/

#include <vector>

Graph<std::string> myGraph; //create a new graph

template <typename ItemType>
Game<ItemType>::Game()
{
	//create rooms
    myGraph.addRoom("Room A");
    myGraph.addRoom("Room B");
    myGraph.addRoom("Room C");
    myGraph.addRoom("Room D");
    myGraph.addRoom("Room E");
    myGraph.addRoom("Room F");
    myGraph.addRoom("Room G");
    myGraph.addRoom("Room H");

	//create random paths
	for(int i = 0; i < 10; i++)
	{
		myGraph.addRandomPath();
	}

    //place keys in random rooms
    myGraph.setRandomKeys();

    //set random room as the start
    curr_room_ptr_ = myGraph.getRandomRoomPtr();

    //set random room as the end
    myGraph.setRandomEnd();
}

template <typename ItemType>
void Game<ItemType>::displayGame() const
{
	std::cout << "Paths: " << std::endl;
	myGraph.display();
	std::cout << std::endl << "Keys Inside: " << std::endl;
	myGraph.displayKeys();
	std::cout << std::endl << "Start Room: " << curr_room_ptr_->getRoomName();
	std::cout << std::endl << "End Room: ";
	myGraph.displayEnd();
	std::cout << std::endl << std::endl;
}

template <typename ItemType>
void Game<ItemType>::startGame()
{
	std::cout << "Oh no! You stole the treasure and now the dungeon is collapsing on itself! Quick, find the three keys and make your escape through the exit." << std::endl << std::endl;

	std::cout << "You are starting in room " << curr_room_ptr_->getRoomName() << "." << std::endl << std::endl;

	std::cout << "Where to next? Connected rooms are:" << std::endl;
	myGraph.printAdjVertices(curr_room_ptr_->getRoomName());
	std::cout << std::endl;
}
