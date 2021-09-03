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
}

template <typename ItemType>
void Game<ItemType>::displayGame() const
{
	std::cout << "Paths: " << std::endl;
	myGraph.display();
	std::cout << std::endl << "Keys Inside: " << std::endl;
	myGraph.displayKeys();
}
