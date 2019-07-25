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
* </ul>
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP

class GamePiece;

/**
* Defines the abstract Player class all players derive from
*
* Sets down the basic markers for the Player-type objects in the game framework.
* The only this that is certain is that the player will have game pieces of some
* kind and that they should have a baseline ID to identify them. Must implement
* action, which can be used by the GameBoard depending on implementation.
*/
class Player{
protected:
  GamePiece**       GamePieces;
  int               ID, NumGamePieces;
public:
  /** @fn Player() @brief Default constructor  */
  Player() noexcept;
/** @fn ~Player() @brief Destructor */
  virtual ~Player();
  /**
  * @fn void SetGamePieces(GamePiece**)
  * @brief Sets the GamePiece pointer array for the players
  * @param An array of GamePiece pointers
  */
  inline void SetGamePieces(GamePiece** pieces){ this->GamePieces = pieces; }
  /**
  * @fn void SetID(int)
  * @brief Sets the ID of the Player
  * @param An int of the ID to assign to the player
  */
  inline void SetID(int id) { this->ID = id; }
  /**
  * @fn void SetNumGamePieces(int)
  * @brief Sets the number of GamePieces in the GamePiece pointer array
  * @param An int of the number of pieces
  */
  inline void SetNumberOfGamePieces(int num) { this->NumGamePieces = num; }
  /**
  * @fn GamePiece** GetGamePieces()
  * @brief Gets the GamePiece pointer array for the players
  * @return An array of pointers to the Player's GamePieces
  */
  inline GamePiece**GetGamePieces() { return this->GamePieces; }
  /**
  * @fn int GetID()
  * @brief Gets the ID of the Player
  * @return An int of the Player's ID
  */
  inline int GetID() { return this->ID; }
  /**
  * @fn int GetNumGamePieces()
  * @brief Gets the number of GamePieces in the GamePiece pointer array
  * @return An int of the number of pieces
  */
  inline int GetNumberOfGamePieces() { return this->NumGamePieces; }
  /**
  * @fn void Action()
  * @brief Triggers a implementation specific Action or series of Action in the
  *   player
  */
  virtual void Action() = 0;
protected:
  Player(int* value){ TestValue = value; }///<Used in Unit Tests
  int*              TestValue;///<Used in Unit Tests
};

template <class Player>
class vector;

template <class Player>
class Players{
  vector<Player> Players;
public:
  vector<Player> GetPlayers();
  unsigned GetNumberOfPlayers();
  Player RemovePlayer(int);
  void RemovePlayer(Player);
  bool AddPlayer(Player);


};
#endif // PLAYER_HPP