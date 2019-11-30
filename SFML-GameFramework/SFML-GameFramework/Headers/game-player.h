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
#pragma once
#include <vector>

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
  class GamePiece;
  class GameAction;

  class GamePlayer{
  /* @brief An int tracker to assign unique ID numbers to newly created GamePlayers */
  protected:
    std::vector<GamePiece*>    GamePiecesHeld;
    int                        PlayerID;
    int                        SuperTestValue;
  public:
    /** 
    * @fn GamePlayer() 
    * @brief Default Constructor 
    */
    GamePlayer()                           { Init();}
    
    /**
    * @fn GamePlayer()
    * @brief Default Constructor
    */
    GamePlayer(int& value)                 { Init(); this->SuperTestValue = value;}

    /**
    * @fn ~GamePlayer()
    * @brief Destructor
    */
    virtual ~GamePlayer()                  { if(this->SuperTestValue != -1) ++this->SuperTestValue; }

        /* Setters */
    /**
    * @fn void SetGamePieces(GamePiece**)
    * @brief Sets the GamePiece pointer array for the GamePlayers
    * @param An array of GamePiece pointers
    */
    void    SetGamePieces(std::vector<GamePiece*> pieces){ this->GamePiecesHeld = pieces; }
    /**
    * @fn GetPlayerID(int)
    * @brief Sets the ID of the GamePlayer
    * @param An int to set as the GamePlayer's ID
    */
    void    SetPlayerID(int id)            { this->PlayerID = id; }

        /* Getters */
    /**
    * @fn GamePiece** GetGamePieces()
    * @brief Gets the GamePiece pointer array for the GamePlayers
    * @return An array of pointers to the GamePlayer's GamePieces
    */
    std::vector<GamePiece*> GetGamePieces(){ return this->GamePiecesHeld; }
    /**
    * @fn int GetPlayerID()
    * @brief Gets the ID of the GamePlayer
    * @return An int of the GamePlayer's ID
    */
    int     GetPlayerID()                  { return this->PlayerID; }
    /**
    * @fn int GetNumGamePieces()
    * @brief Gets the number of GamePieces in the GamePiece pointer array
    * @return An int of the number of pieces
    */
    int     GetNumberOfGamePieces()        { return this->GamePiecesHeld.size(); }  
    /**
    * @fn int GetSuperTestValue()
    * @brief Gets the Super class's Test value
    * @return A pointer to the test value 
    */
    int&    GetSuperTestValue()            { return this->SuperTestValue; }
    
    /* Functional Methods */
    /**
    * @fn void Perform()
    * @brief Triggers a implementation specific Action or series of Action in the
    *   GamePlayer
    */
    virtual bool Perform(GameAction *act)  { return true; }

  private:
    void    Init()                         { this->PlayerID = -1; this->SuperTestValue = -1;}
  };
}
#endif // GAMEPLAYER_HPP