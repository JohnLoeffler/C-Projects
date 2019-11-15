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
#ifndef GAMEPLAYER_HPP
#define GAMEPLAYER_HPP
#include <vector>
#pragma once

class GamePiece;
class GameAction;

/**
* Defines the abstract GamePlayer class all AI and human-controlled players derive from
*
* Sets down the basic markers for the GamePlayer-type objects in the game framework.
* The only this that is certain is that the player will have game pieces of some
* kind and that they should have a baseline ID to identify them. Must implement
* virtual function 'Perform', which can be regulated by the GameBoard depending on 
* implementation to control the flow of the game.
*/
namespace GameFramework{
  class GamePlayer{
  /* @brief An int tracker to assign unique ID numbers to newly created GamePlayers */
    static int NextID;
  
  protected:
    std::vector<GamePiece*>    GamePiecesHeld;
    int                        PlayerID, NumberOfGamePieces;
    int*                       SuperTestValue;

  public:

    /**
    * @fn ~GamePlayer()
    * @brief Destructor
    */
    virtual ~GamePlayer(){ if(this->SuperTestValue != nullptr) ++(*this->SuperTestValue); }

        /* Setters */
    /**
    * @fn void SetGamePieces(GamePiece**)
    * @brief Sets the GamePiece pointer array for the GamePlayers
    * @param An array of GamePiece pointers
    */
    void    SetGamePieces(std::vector<GamePiece*> pieces){ this->GamePiecesHeld = pieces; this->SetNumberOfGamePieces(this->GetGamePieces().size());}
    /**
    * @fn void SetID(int)
    * @brief Sets the ID of the GamePlayer
    * @param An int of the ID to assign to the GamePlayer
    */
    void    SetPlayerID(int playerID)          { this->PlayerID = playerID; }
    /**
    * @fn void SetNumGamePieces(int)
    * @brief Sets the number of GamePieces in the GamePiece pointer array
    * @param An int of the number of pieces
    */
    void    SetNumberOfGamePieces(int number)  { this->NumberOfGamePieces = number; }
    /**
    * @fn void SetSuperTestValue(int*)
    * @brief Prepares to external variable for the object to manipulate
    * @param An int of any integer
    */
    void    SetSuperTestValue(int* val)        { this->SuperTestValue = val;};

        /* Getters */
    /**
    * @fn GamePiece** GetGamePieces()
    * @brief Gets the GamePiece pointer array for the GamePlayers
    * @return An array of pointers to the GamePlayer's GamePieces
    */
    std::vector<GamePiece*>    GetGamePieces() { return this->GamePiecesHeld; }
    /**
    * @fn int GetID()
    * @brief Gets the ID of the GamePlayer
    * @return An int of the GamePlayer's ID
    */
    int     GetPlayerID()                      { return this->PlayerID; }
    /**
    * @fn int GetNumGamePieces()
    * @brief Gets the number of GamePieces in the GamePiece pointer array
    * @return An int of the number of pieces
    */
    int     GetNumberOfGamePieces()            { return this->NumberOfGamePieces; }  
    /**
    * @fn int GetSuperTestValue()
    * @brief Gets the Super class's Test value
    * @return A pointer to the test value 
    */
    int*    GetSuperTestValue()                { return this->SuperTestValue; }
    /* Functional Methods */
    /**
    * @fn void Perform()
    * @brief Triggers a implementation specific Action or series of Action in the
    *   GamePlayer
    */
    virtual bool Perform(GameAction *action)   { return true; }

  private:
    void    Init()      { GamePlayer::NextID = 1; }
    int     GetNextID() { return NextID; }
  };

  /**
  * @brief A wrapper class for a group of GamePlayers to make grouping and managing them easier
  */
  class GamePlayers{
  protected:
    std::vector<GamePlayer*>   VectorOfPlayers; // The vector for the wrapper class that hold pointers to the game's GamePlayers
    int*                       SuperTestWrapperValue;  // A pointer to an int value that was allocated outside the scope of this class.

  public:
    // Constructors And Destructors //
    /**
    * @fn GamePlayers(int*)
    * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
    * @param int* A pointer to an int variable that can be persistently changed by the class destructor
    */
    GamePlayers(int* value)    { this->SuperTestWrapperValue = value; }

    /**
    * @fn GamePlayers()
    * @brief Default constructor for the wrapper class
    */
    GamePlayers()              { this->SuperTestWrapperValue = nullptr; }

    /**
* @fn ~Players()
* @brief Virtual destructor for the wrapper class
*/
    virtual ~GamePlayers()     { if(this->SuperTestWrapperValue != nullptr) ++(*this->SuperTestWrapperValue); }

    /* Setters */
    /**
    * @fn SetGamePlayers(std::vector<GamePlayer*>)
    * @brief Groups a vector of GamePlayers into a single encapsulated object
    * @return A vector of pointers to a group of GamePlayers
    */
    void    SetGamePlayers(std::vector<GamePlayer*> players){this->VectorOfPlayers = players;}

    /* Getters */
    /**
    * @fn vector<GamePlayer*> GetGamePlayers()
    * @brief Gets the encapsulated vector of the GamePlayers
    * @return A vector of pointers to a group of GamePlayers
    */
    std::vector<GamePlayer*>   GetGamePlayers(){ return this->VectorOfPlayers; }
    /**
    * @fn unsigned GetNumberOfPlayers()
    * @brief Gets the number of Players in the vector
    * @return An unsigned int of the number of Players
    */
    size_t  GetNumberOfGamePlayers()           { return this->VectorOfPlayers.size(); }

    int*    GetSuperTestWrapperValue()         { return this->SuperTestWrapperValue; }
    
    /* Functional Methods */
    /**
    * @fn T* RemovePlayer(T*, int)
    * @brief Removes the player at the given index, shifting
    *   any players behind them one index forward, and points the param pointer to
    *   location of Player in memory.
    * @param int The index of the Player in the Players vector
    * @return true, if the player was successfully removed, false otherwise
    */
    bool    RemoveGamePlayer(int index){
  // Validate parameters and object initialization //
      if(index < 0 || (unsigned)index > this->VectorOfPlayers.size()){ return false; }
      if(this->VectorOfPlayers.size() == 0){ return false; }

      // Remove player from vector and validate deletion //
      size_t temp = this->VectorOfPlayers.size();
      this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + index);

      // Report results //
      return (this->VectorOfPlayers.size() == (temp - 1) ? true : false);
    }

    /**
    * @fn T* RemovePlayer(T*, int)
    * @brief Removes the player at the given index, shifting
    *   any players behind them one index forward, and points the param pointer to
    *   location of Player in memory.
    * @param T An external pointer that will hold the address of the removed player
    * @param int The index of the Player in the Players vector
    * @return true, if the player was successfully removed, false otherwise
    */
    bool    RemoveGamePlayer(GamePlayer* player, int index){
      
      // Validate parameters and object initialization //
      if(player == nullptr){ return false; }
      if(index < 0 || (unsigned)index > this->VectorOfPlayers.size()){ return false; }
      if(this->VectorOfPlayers.size() == 0){ return false; }

      // Pull player from vector and validate removal //
      size_t temp = this->VectorOfPlayers.size();
      player = this->VectorOfPlayers.at(index);
      this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + index);

      // Report results //
      return (this->VectorOfPlayers.size() == (temp - 1) ? true : false);
    }
    /**
    * @fn void RemovePlayer(const Player*)
    * @brief Alternative to indexing, removes param player from
    *   vector if found, shifting all players behind them
    *   forward by one.
    * @return true, if the player was successfully removed, false otherwise
    */
    bool    RemoveGamePlayer(const GamePlayer* player){
  // Validate parameters and object initialization //
      if(player == nullptr){ return false; }
      if(this->VectorOfPlayers.size() <= 0){ return false; }

      // Locate any instance of player in vector and remove them //
      bool flag = false;
      for(unsigned i = 0; i < this->VectorOfPlayers.size(); i++){
        if(this->VectorOfPlayers.at(i) == player){
          this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + i);

          // Player found and removed from group//
          flag = true;
        }
      }

      // Report results //
      return flag;
    }
    /**
    * @fn bool AddPlayer(Player*)
    * @brief Adds a player to the back of the vector
    * @return True if player was successfully added, false otherwise
    */ 
    bool    AddGamePlayer(GamePlayer* player){
      // Validate parameters and object initialization //
      if(player == nullptr){ return false; }

      // Add pointer to player to the vector, validate operation, and report result //
      size_t temp = this->VectorOfPlayers.size();
      this->VectorOfPlayers.emplace_back(player);
      return (this->VectorOfPlayers.size() == (1 + temp) ? true : false);
    }
  };
}
#endif // GAMEPLAYER_HPP