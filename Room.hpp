/*
Title: Room Class
Author: Edwin Khew
Description: Room class declaration.
Date Created: 8/30/2021
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
        @param room_name, name of the room to be created
    */
    Room(ItemType room_name);

    /*
		sets the name of the calling room
		@param room_name, name of the room to be set
    */
    void setRoomName(ItemType room_name);

    /*
        returns the name of the calling room
        @return 'room_name_'
    */
    ItemType getRoomName() const;

    /*
        places or removes a key from the calling room
        @param has_key, 'true' to place a key in room, and 'false' to remove key from room
    */
    void setHasKey(bool has_key);

    /*
        returns whether or not the calling room contains a key
        @return 'has_key_'
    */
    bool getHasKey() const;

     /*
        sets the status of a room as the 'end' room
        @param is_end, 'true' sets the room as the 'end' room, and 'false' sets it back to a regular room
    */
    void setIsEnd(bool is_end);

    /*
        returns whether or not a room is the 'end' room
        @return 'is_end_'
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
    bool has_key_; //'true' if the room contains a key, and 'false' otherwise
    bool is_end_; //'true' if the room is the end/exit, and 'false' otherwise
};

#include "Room.cpp"
#endif