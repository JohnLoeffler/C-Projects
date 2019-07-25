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
* \file player.hpp
*
* \brief An abstract class from which different player types can be derived
*
* \ingroup GameFramework
*
* \author John Loeffler
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
  GamePiece*        GamePieces;
  int               ID;
public:
                    Player()  {this->GamePieces = nullptr; this->ID = INT_MIN;}
  virtual           ~Player();

  inline void       SetGamePieces(GamePiece* pieces){this->GamePieces = pieces;}
  inline void       SetID(int id)                   {this->ID = id;}
  inline GamePiece* GetGamePieces()                 {return this->GamePieces;}
  inline int        GetID()                         {return this->ID;}

  virtual void      Action() =0;
};
#endif // PLAYER_HPP
