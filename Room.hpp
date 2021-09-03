/*
Title: Undirected Graph (Adjacency List) Vertex
Author: Edwin Khew
Description: Undirected graph (adjacency list) vertex class declaration.
Date Created: 7/11/2021
*/

#ifndef ROOM_H_
#define ROOM_H_

template <class ItemType>
class Room
{
public:
    /*
        default constructor
    */
    Room();

    /*
        parameterized constructor
    */
    Room(ItemType room_name);

    /*
        sets the item in the vertex to the specified item
        @param item, item to be set in the vertex
    */
    void setRoomName(ItemType room_name);

    /*
        returns the item of the calling vertex
        @return 'item_'
    */
    ItemType getRoomName() const;

    /*
        sets the item in the vertex to the specified item
        @param item, item to be set in the vertex
    */
    void setHasKey(bool has_key);

    /*
        returns the item of the calling vertex
        @return 'item_'
    */
    bool getHasKey() const;

     /*
        sets the item in the vertex to the specified item
        @param item, item to be set in the vertex
    */
    void setIsEnd(bool is_end);

    /*
        returns the item of the calling vertex
        @return 'item_'
    */
    bool getIsEnd() const;

    /*
        operator overload of '<'
        @param v, vertex to compare with the calling vertex
        @return true if the parameter vertex is less than the calling vertex, and false otherwise
    */
    bool operator < (const Room& v) const;

    /*
        operator overload of '=='
        @param v, vertex to compare with the calling vertex
        @return true if the parameter vertex is equal to the calling vertex, and false otherwise
    */
    bool operator == (const Room& v) const;
private:
    ItemType room_name_; //name of the room
    bool has_key_; //'true' if the room contains a key, and false otherwise
    bool is_end_; //'true' if the room is the end/exit, and false otherwise
};

#include "Room.cpp"
#endif
