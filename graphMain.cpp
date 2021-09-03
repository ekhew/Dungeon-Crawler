/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) test file.
Date Created: 7/11/2021
*/

#include <iostream>
#include "Room.hpp"
#include "Graph.hpp"

using namespace std;

int main()
{
    Graph<string> myGraph;

    myGraph.addRoom("Room A");
    myGraph.addRoom("Room B");
    myGraph.addRoom("Room C");
    myGraph.addRoom("Room D");
    myGraph.addRoom("Room E");
    myGraph.addRoom("Room F");
    myGraph.addRoom("Room G");
    myGraph.addRoom("Room H");

    myGraph.addRandomPath();
    myGraph.addRandomPath();
    myGraph.addRandomPath();
    myGraph.addRandomPath();
    myGraph.addRandomPath();
    myGraph.addRandomPath();

    //myGraph.removeVertex("Bb");
    //myGraph.removeVertex("Zz"); //vertex does not exists

    //myGraph.removeEdge("Cc", "Dd");
    //myGraph.removeEdge("Aa", "Cc"); //edge does not exist
    //myGraph.removeEdge("Yy", "Zz"); //vertices do not exists

    cout << "Is Empty: " << myGraph.isEmpty() << endl;
    cout << "Check Adjacency: " << myGraph.checkAdj("Aa", "Dd") << endl;
    cout << "Adjacent Vertices: ";
    myGraph.printAdjVertices("Aa");
    cout << endl << "BFS: ";
    myGraph.BFS("Aa");
    cout << endl << "DFS (Iterative): ";
    myGraph.iterativeDFS("Aa");
    cout << endl << "Display: " << endl << endl;

    myGraph.display();

    //myGraph.getRandomRoom();
    myGraph.setRandomKeys();
}
