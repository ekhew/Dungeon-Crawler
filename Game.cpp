/*
Title: Game Class
Author: Edwin Khew
Description: Game class implementation.
Date Created: 8/30/2021
*/

Dungeon<std::string> myDungeon; //create a new graph

template <typename ItemType>
Game<ItemType>::Game()
{
    //create rooms
    myDungeon.addRoom("Room A");
    myDungeon.addRoom("Room B");
    myDungeon.addRoom("Room C");
    myDungeon.addRoom("Room D");
    myDungeon.addRoom("Room E");
    myDungeon.addRoom("Room F");
    myDungeon.addRoom("Room G");
    myDungeon.addRoom("Room H");

    //create random paths
    for(int i = 0; i < 10; i++)
    {
        myDungeon.addRandomPath();
    }

    //place keys in random rooms
    myDungeon.setRandomKeys();

    //set random room as the end
    myDungeon.setRandomEnd();

    //set random room as the start
    curr_room_ptr_ = myDungeon.getRandomRoomPtr();
}

template <typename ItemType>
void Game<ItemType>::displayGame() const
{
    std::cout << "Paths: " << std::endl;
    myDungeon.display();

    std::cout << std::endl << "Keys Inside: " << std::endl;
    myDungeon.displayKeys();

    std::cout << std::endl << "Start Room: " << curr_room_ptr_->getRoomName();

    std::cout << std::endl << "End Room: ";
    myDungeon.displayEnd();

    std::cout << std::endl << "--------------------------------------------------------------------------" << std::endl;
}

template <typename ItemType>
void Game<ItemType>::startGame()
{
    std::string next_room; //stores user input

    //introduction story text
    std::cout << std::endl << "Oh no! You stole the treasure and now the dungeon is collapsing on itself! Quick, find the three keys and make your escape through the exit." << std::endl << std::endl;

    //display starting room to player
    std::cout << "You are starting in room " << curr_room_ptr_->getRoomName() << "." << std::endl << std::endl;

    //display adjacent rooms to player
    std::cout << "Connected rooms are: ";
    myDungeon.printAdjVertices(curr_room_ptr_->getRoomName());

    //prompts the player to enter the name of the next room to visit
    std::cout << std::endl << std::endl << "Enter room name: ";
    std::getline(std::cin, next_room);

    std::cout << std::endl << "--------------------------------------------------------------------------" << std::endl;

    continueGame(next_room);
}

template <typename ItemType>
void Game<ItemType>::continueGame(std::string next_room_param)
{
    std::string next_room; //stores user input

    //move to next room if the room exists and is adjacent to the current room
    if(myDungeon.checkAdj(curr_room_ptr_->getRoomName(), next_room_param))
    {
        curr_room_ptr_ = myDungeon.getRoomPtr(next_room_param);

        //if the new room contains a key, increment 'key_count_' and remove the key from the room object
        if(curr_room_ptr_->getHasKey())
        {
            key_count_++;
            curr_room_ptr_->setHasKey(false);
        }
    }
    else
    {
        std::cout << std::endl << "Oops! Room not found. Try Again." << std::endl;
    }

    //ends the game if the current room is the 'end' room, and the player has all 3 keys
    if(curr_room_ptr_->getIsEnd() && key_count_ == 3)
    {
        endGame();
    }
    else //continues the game otherwise
    {
        std::cout << std::endl << "You are in room " << curr_room_ptr_->getRoomName() << "." << std::endl;

        if(curr_room_ptr_->getIsEnd())
        {
            std::cout << "You discovered the end room! Come back when you have found all 3 keys." << std::endl;
        }

        if(key_count_ == 3)
        {
            std::cout << "Yay! You found all 3 keys. Find the end room and escape!" << std::endl << std::endl;
        }
        else
        {
            std::cout << "You currently have " << key_count_ << " keys." << std::endl << std::endl;
        }

        //display adjacent rooms to player
        std::cout << "Connected rooms are: ";
        myDungeon.printAdjVertices(curr_room_ptr_->getRoomName());

        //prompts the player to enter the name of the next room to visit
        std::cout << std::endl << std::endl << "Enter room name: ";
        std::getline(std::cin, next_room);

        std::cout << std::endl << "--------------------------------------------------------------------------" << std::endl;

        continueGame(next_room);
    }
}

template <typename ItemType>
void Game<ItemType>::endGame()
{
    std::cout << std::endl << "Congratulations! You escaped the dungeon!" << std::endl << std::endl;
}
