/*
Title: Undirected Graph (Adjacency List) Vertex
Author: Edwin Khew
Description: Undirected graph (adjacency list) vertex class implementation.
Date Created: 7/11/2021
*/

template<typename ItemType>
Room<ItemType>::Room() { }

template<typename ItemType>
Room<ItemType>::Room(ItemType room_name):room_name_(room_name), has_key_(false) { }

template<typename ItemType>
void Room<ItemType>::setRoomName(ItemType room_name)
{
    room_name_ = room_name;
}

template<typename ItemType>
ItemType Room<ItemType>::getRoomName() const
{
    return room_name_;
}

template<typename ItemType>
void Room<ItemType>::setHasKey(bool has_key)
{
    has_key_ = has_key;
}

template<typename ItemType>
bool Room<ItemType>::getHasKey() const
{
    return has_key_;
}

template<typename ItemType>
bool Room<ItemType>::operator < (const Room& v) const
{
    if(room_name_ < v.room_name_) //if the item of the calling vertex is less than the comparing vertex's item
    {
        return true;
    }

    return false;
}

template<typename ItemType>
bool Room<ItemType>::operator == (const Room& v) const
{
    if(room_name_ == v.room_name_) //if the item of the calling vertex is equal to the comparing vertex's item
    {
        return true;
    }

    return false;
}
