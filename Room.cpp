/*
Title: Room Class
Author: Edwin Khew
Description: Room class implementation.
Date Created: 8/30/2021
*/

template<typename ItemType>
Room<ItemType>::Room() { }

template<typename ItemType>
Room<ItemType>::Room(ItemType room_name):room_name_(room_name), has_key_(false), is_end_(false) { }

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
void Room<ItemType>::setIsEnd(bool is_end)
{
    is_end_ = is_end;
}

template<typename ItemType>
bool Room<ItemType>::getIsEnd() const
{
    return is_end_;
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