/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) class declaration.
Date Created: 7/11/2021
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <list>
#include <vector>

template <class ItemType>
class Graph
{
public:
    /*
        default constructor
    */
    Graph();

    /*
        adds a new vertex into the graph
        @param item, the new vertex to add into the graph
    */
    void addRoom(ItemType room_name);

    /*
        removes a vertex from the graph
        @param item, vertex to remove from the graph
    */
    void removeRoom(ItemType room_name);

    /*
        adds an edge connecting two specified vertices
        @param item1, first vertex
        @param item2, second vertex
    */
    void addPath(ItemType room1, ItemType room2);

    /*
        removes an edge connecting two specified vertices
        @param item1, first vertex
        @param item2, second vertex
    */
    void removePath(ItemType room1, ItemType room2);

    /*
        checks if the graph is currently empty
        @return true if the graph is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        checks if two specified vertices are adjacent
        @param item1, first vertex
        @param item2, second vertex
        @return true if the vertices are adjacent, and false otherwise
    */
    bool checkAdj(ItemType item1, ItemType item2) const;

    /*
        prints every adjacent vertex of the specified vertex
        @param item, the vertex to print every adjacent vertex of
    */
    void printAdjVertices(ItemType item) const;

    /*
        traverses the graph using BFS and prints every vertex
        @param start, the vertex to start the traversal from
    */
    void BFS(ItemType start) const;

    /*
        traverses the graph using DFS and prints every vertex; iterative approach
        @param start, the vertex to start the traversal from
    */
    void iterativeDFS(ItemType start) const;

    /*
        prints out every adjacency list that makes up the graph
    */
    void display() const;

    void getRandomRoom();
    void setRandomKeys();
    void addRandomPath();
private:
    std::map<Room<ItemType>, std::list<Room<ItemType>>> graph_; //map of vertex - adjacency lists pairs
    std::vector<Room<ItemType>*> ptr_vector_; //vector of pointers to rooms
};

#include "Graph.cpp"
#endif
