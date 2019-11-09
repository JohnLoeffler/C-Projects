/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Any source code included in this package written by myself, John Loeffler, is
* free to use as-is for any purpose, commercial and non-commercial alike, so
* long as the license & header documentation containing my contact info and link
* to the original source file on Github remains intact.
*
* Any source code included in this package that was written by others maintains
* its own licensing terms that must be followed, and this license in no way
* supersedes that license.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License v 3.0 for more details.
*
* see <https://www.gnu.org/licenses/gpl-3.0.en.html>.
*/
/**
* @file player.hpp
*
* @brief An abstract class from which different player types can be derived
*
* @ingroup game-framework
*
* @author John Loeffler
* <ul>contact:
*   <li>John.Loeffler@gmail.com</li>
*   <li>JohnLoeffler.com</li>
*   <li>Github.com/JohnLoeffler</li>
*   <li>LinkedIn.com/in/JohnLoeffler</li>
*   <li>Twitter.com/ThisDotJohn</li>
* </ul>
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#pragma once

class GamePiece;

/**
* Defines the abstract Player class all players derive from
*
* Sets down the basic markers for the Player-type objects in the game framework.
* The only this that is certain is that the player will have game pieces of some
* kind and that they should have a baseline ID to identify them. Must implement
* action, which can be used by the GameBoard depending on implementation.
*/
namespace GameFrame{
  class Player{
  
  protected:
    GamePiece**       GamePieces;
    int               ID, NumberOfGamePieces;
    int*              SuperTestValue;

    /**
    * @fn Player(int*)
    * @brief Parameterized constructor that allows Unit testing of destructor functionality.
    * @param A pointer to an int representing the address of the external variable to be changed
    */
    Player(int* value);
  
  public:
    /** 
    * @fn Player() 
    * @brief Default constructor  
    */
    Player();
     /** 
    * @fn ~Player() 
    * @brief Destructor 
    */
    virtual ~Player();

    /* Setters */
    /**
    * @fn void SetGamePieces(GamePiece**)
    * @brief Sets the GamePiece pointer array for the players
    * @param An array of GamePiece pointers
    */
    void SetGamePieces(GamePiece** pieces)  { this->GamePieces = pieces; }
    /**
    * @fn void SetID(int)
    * @brief Sets the ID of the Player
    * @param An int of the ID to assign to the player
    */
    void SetID(int id)  { this->ID = id; }
    /**
    * @fn void SetNumGamePieces(int)
    * @brief Sets the number of GamePieces in the GamePiece pointer array
    * @param An int of the number of pieces
    */
    void SetNumberOfGamePieces(int number)  { this->NumberOfGamePieces = number; }
    
    /* Getters */
    /**
    * @fn GamePiece** GetGamePieces()
    * @brief Gets the GamePiece pointer array for the players
    * @return An array of pointers to the Player's GamePieces
    */
    GamePiece** GetGamePieces()  { return this->GamePieces; }
    /**
    * @fn int GetID()
    * @brief Gets the ID of the Player
    * @return An int of the Player's ID
    */
    int GetID()  { return this->ID; }
    /**
    * @fn int GetNumGamePieces()
    * @brief Gets the number of GamePieces in the GamePiece pointer array
    * @return An int of the number of pieces
    */
    int GetNumberOfGamePieces()  { return this->NumberOfGamePieces; }

    /* Functional Methods */
    /**
    * @fn void Action()
    * @brief Triggers a implementation specific Action or series of Action in the
    *   player
    */
    virtual bool Action() = 0;  
  };

  /**
  * @brief Declares a wrapper class for a group of Players to make grouping and managing them easier
  */
  template <class T>
  class Players{
  protected:
    std::vector<T*> VectorOfPlayers; // The vector for the wrapper class that hold pointers to the game's Players
    int*            SuperTestValue;  // A pointer to an int value that was allocated outside the scope of this class.

    /**
    * @fn Players(int*)
    * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
    * @param int* A pointer to an int variable that can be persistently changed by the class destructor
    */
    Players(int* value);

  public:

    /**
    * @fn Players()
    * @brief Default constructor for the wrapper class
    */
    Players() { this->SuperTestValue = nullptr; }
    
    /**
    * @fn ~Players()
    * @brief Virtual destructor for the wrapper class
    */
    virtual ~Players(){ if(this->SuperTestValue != nullptr) (*this->SuperTestValue)++; }
    
    /* Setters */
    
    inline void SetPlayers(std::vector<T*> players);

    /* Getters */
    /**
    * @fn vector<Player*> GetPlayers()
    * @brief Gets the encapsulated vector of the players
    * @return A vector of pointers to a group of Players
    */
    std::vector<T*> GetPlayers();
    /**
    * @fn unsigned GetNumberOfPlayers()
    * @brief Gets the number of Players in the vector
    * @return An unsigned int of the number of Players
    */
    size_t GetNumberOfPlayers();

    /* Functional Methods */
    /**
    * @fn T* RemovePlayer(T*, int)
    * @brief Removes the player at the given index, shifting
    *   any players behind them one index forward, and points the param pointer to 
    *   location of Player in memory.
    * @param T An external pointer that will hold the address of the removed player
    * @param int The index of the Player in the Players vector
    * @return true, if the player was successfully removed, false otherwise
    */
    bool RemovePlayer(T*, int);
    /**
    * @fn void RemovePlayer(const Player*)
    * @brief Alternative to indexing, removes param player from
    *   vector if found, shifting all players behind them
    *   forward by one.
    * @return true, if the player was successfully removed, false otherwise
    */
    bool RemovePlayer(const T*);
    /**
    * @fn bool AddPlayer(Player*)
    * @brief Adds a player to the back of the vector
    * @return True if player was successfully added, false otherwise
    */
    bool AddPlayer(T*);
  };
}
#endif // PLAYER_HPP