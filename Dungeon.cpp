/*
Title: Dungeon Class
Author: Edwin Khew
Description: Dungeon class implementation.
Date Created: 8/30/2021
*/

#include <map>
#include <list>
#include <queue> //for BFS
#include <stack> //for DFS
#include <algorithm> //for random_shuffle() method
#include <vector>
#include <random>

template <typename ItemType>
Dungeon<ItemType>::Dungeon() { }

template <typename ItemType>
void Dungeon<ItemType>::addRoom(ItemType room_name)
{
    Room<ItemType>* new_vertex = new Room<ItemType>(room_name); //create a new vertex object with the specified item
    std::list<Room<ItemType>> new_list; //create a new adjacency list that corresponds to the new vertex

    graph_[*new_vertex] = new_list; //insert a new key-value pair, 'pair<new_vertex, new_list>', into the graph
    ptr_vector_.push_back(new_vertex); //add the pointer to the new room into the vector
}

template <typename ItemType>
void Dungeon<ItemType>::removeRoom(ItemType room_name)
{
    if(!isEmpty()) //can only remove vertex if the graph is not empty
    {
        graph_.erase(Room<ItemType>(room_name)); //erase the vertex with the specified item from the map

        typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::iterator i; //iterator used to traverse the graph

        //for every vertex currently in the map, remove any instance of the vertex to be removed from its adjacency list
        for(i = graph_.begin(); i != graph_.end(); i++)
        {
            i->second.remove(Room<ItemType>(room_name));
        }
    }
}

template <typename ItemType>
void Dungeon<ItemType>::addPath(ItemType room1, ItemType room2)
{
    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::iterator i = graph_.find(Room<ItemType>(room1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::iterator j = graph_.find(Room<ItemType>(room2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != graph_.end() && j != graph_.end()) //can only add an edge if graph is not empty and both vertices exist
    {
        //insert each vertex object into the other's adjacency list
        i->second.push_back(j->first);
        j->second.push_back(i->first);
    }
}

template <typename ItemType>
void Dungeon<ItemType>::removePath(ItemType room1, ItemType room2)
{
    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::iterator i = graph_.find(Room<ItemType>(room1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::iterator j = graph_.find(Room<ItemType>(room2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != graph_.end() && j != graph_.end()) //can only remove an edge if graph is not empty and both vertices exist
    {
        //remove each vertex object from the other's adjacency list
        i->second.remove(j->first);
        j->second.remove(i->first);
    }
}

template <typename ItemType>
bool Dungeon<ItemType>::isEmpty() const
{
    return graph_.empty();
}

template <typename ItemType>
bool Dungeon<ItemType>::checkAdj(ItemType room1, ItemType room2) const
{
    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator i = graph_.find(Room<ItemType>(room1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator j = graph_.find(Room<ItemType>(room2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != graph_.end() && j != graph_.end()) //can only check adjacency if graph is not empty and both vertices exist
    {
        for(auto j : i->second) //loop through the adjacency list of the vertex with 'item1'
        {
            if(j.getRoomName() == room2) //if a matching item was found, then the vertices are adjacent
            {
                return true;
            }
        }
    }

    return false;
}

template <typename ItemType>
void Dungeon<ItemType>::printAdjVertices(ItemType room_name) const
{
    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator i = graph_.find(Room<ItemType>(room_name)); //find the vertex key with 'item' and store into the iterator

    if(!isEmpty() && i != graph_.end()) //can only print adjacent vertices if graph is not empty and vertex exist
    {
        for(auto j : i->second) //loop through the adjacency list of the vertex with 'item1'
        {
            std::cout << j.getRoomName() << " ";
        }
    }
    else
    {
        std::cout << "Vertex not found!";
    }
}

template <typename ItemType>
void Dungeon<ItemType>::BFS(ItemType start) const
{
    std::queue<Room<ItemType>> Q; //queue used to keep track of unvisited vertices
    std::map<Room<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator i = graph_.find(Room<ItemType>(start)); //find the starting vertex

    if(i != graph_.end()) //can only begin BFS if the starting vertex exists
    {
        Q.push(i->first); //push the starting vertex into queue
        visited_map[i->first] = true; //mark starting vertex as visited

        while(!Q.empty()) //continue traversing while the queue is not empty
        {
            Room<ItemType> curr_vertex = Q.front(); //vertex at the front of the queue
            std::cout << curr_vertex.getRoomName() << " ";
            Q.pop();

            typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator j = graph_.find(Room<ItemType>(curr_vertex)); //find the current vertex to get its list

            for(auto adj_vertex : j->second) //traverse the current vertex's adjacency list
            {
                typename std::map<Room<ItemType>, bool>::const_iterator k = visited_map.find(Room<ItemType>(adj_vertex)); //check to see if the vertex has already been visited

                if(k == visited_map.end()) //if the adjacent vertex was not found in the 'visited' map, then push to queue and mark as visited
                {
                    Q.push(adj_vertex);
                    visited_map[adj_vertex] = true;
                }
            }
        }
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Dungeon<ItemType>::iterativeDFS(ItemType start) const
{
    std::stack<Room<ItemType>> S; //stack used to keep track of unvisited vertices
    std::map<Room<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

    typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator i = graph_.find(Room<ItemType>(start)); //find the starting vertex

    if(i != graph_.end()) //can only begin DFS if the starting vertex exists
    {
        S.push(i->first); //push the starting vertex into stack
        visited_map[i->first] = true; //mark starting vertex as visited

        while(!S.empty()) //continue traversing while the stack is not empty
        {
            Room<ItemType> curr_vertex = S.top(); //vertex at the top of the stack
            std::cout << curr_vertex.getRoomName() << " ";
            S.pop();

            typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator j = graph_.find(Room<ItemType>(curr_vertex)); //find the current vertex to get its list

            for(auto adj_vertex : j->second) //traverse the current vertex's adjacency list
            {
                typename std::map<Room<ItemType>, bool>::const_iterator k = visited_map.find(Room<ItemType>(adj_vertex)); //check to see if the vertex has already been visited

                if(k == visited_map.end()) //if the adjacent vertex was not found in the 'visited' map, then push to stack and mark as visited
                {
                    S.push(adj_vertex); //Note: the first element of the list is pushed first, so it will be the last element of the list visited in the stack
                    visited_map[adj_vertex] = true;
                }
            }
        }
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Dungeon<ItemType>::display() const
{
    if(!isEmpty()) //can only print if the graph is not empty
    {
        typename std::map<Room<ItemType>, std::list<Room<ItemType>>>::const_iterator i; //iterator used to traverse the graph

        for(i = graph_.begin(); i != graph_.end(); i++)
        {
            std::cout << i->first.getRoomName(); //print the key of the current element

            for(auto j : i->second) //print every element in the adjacency list
            {
                std::cout << " --> " << j.getRoomName();
            }

            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Graph is empty!" << std::endl;
    }
}

template <typename ItemType>
Room<ItemType>* Dungeon<ItemType>::getRandomRoomPtr()
{
    srand(time(0));

    //keep shuffling until the room in the first index is not a room with a key or is the 'end' room
    while(ptr_vector_[0]->getHasKey() || ptr_vector_[0]->getIsEnd())
    {
        std::random_shuffle(ptr_vector_.begin(), ptr_vector_.end());
    }

    return ptr_vector_[0];
}

template <typename ItemType>
Room<ItemType>* Dungeon<ItemType>::getRoomPtr(std::string room_name)
{
    for(int i = 0; i < ptr_vector_.size(); i++)
    {
        if(ptr_vector_[i]->getRoomName() == room_name)
        {
            return ptr_vector_[i];
        }
    }

    return nullptr;
}

template <typename ItemType>
void Dungeon<ItemType>::setRandomKeys()
{
    srand(time(0));
    std::random_shuffle(ptr_vector_.begin(), ptr_vector_.end());

    for(int i = 0; i <= 2; i++)
    {
        ptr_vector_[i]->setHasKey(true);
    }
}

template <typename ItemType>
void Dungeon<ItemType>::setRandomEnd()
{
    srand(time(0));

    //keep shuffling until the room in the first index is not a room with a key
    while(ptr_vector_[0]->getHasKey())
    {
        std::random_shuffle(ptr_vector_.begin(), ptr_vector_.end());
    }

    ptr_vector_[0]->setIsEnd(true);
}

template <typename ItemType>
void Dungeon<ItemType>::addRandomPath()
{
    srand(time(0));

    //keep shuffling until a path that does not already exists is found and can be created
    while(checkAdj(ptr_vector_[0]->getRoomName(), ptr_vector_[1]->getRoomName()))
    {
        std::random_shuffle(ptr_vector_.begin(), ptr_vector_.end());
    }

    addPath(ptr_vector_[0]->getRoomName(), ptr_vector_[1]->getRoomName());
}

template <typename ItemType>
void Dungeon<ItemType>::displayKeys()
{
    //loop through the vector to find the rooms with keys, and print them
    for(int i = 0; i < ptr_vector_.size(); i++)
    {
        if(ptr_vector_[i]->getHasKey())
        {
            std::cout << ptr_vector_[i]->getRoomName() << std::endl;
        }
    }
}

template <typename ItemType>
void Dungeon<ItemType>::displayEnd()
{
    //loop through the vector to find the 'end' room, the print it
    for(int i = 0; i < ptr_vector_.size(); i++)
    {
        if(ptr_vector_[i]->getIsEnd())
        {
            std::cout << ptr_vector_[i]->getRoomName() << std::endl;
        }
    }
}
