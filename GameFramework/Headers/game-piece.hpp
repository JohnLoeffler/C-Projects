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
* \file game-piece.hpp
*
* \brief An abstract class from which different game pieces can be derived
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
#ifndef GAMEPIECE_HPP
#define GAMEPIECE_HPP

/**
*  An abstract class from which other game pieces can be derived
*
*  The GamePiece class is the base class for all game pieces in the
*   GameFramework package. Everything from chess pieces to playing cards are
*   derived from this class. As such, the 'Compare' method must be defined for
*   each derived type
*/
class GamePiece{
  int                 Value;
  int                 ID;
public:
  /**  Constructor  */
                      GamePiece(){}
  /**  Destructor   */
  virtual             ~GamePiece(){}

  /* Setters and Getters */
  /**
  * Gets the value of the GamePiece
  * \return An int of the GamePiece's value
  */
  int                 GetValue()          {return this->Value;}
  /**
  * Gets the ID of the GamePiece
  * \return An int of the GamePiece's ID
  */
  int                 GetID()             {return this->ID;}
  /**
  * Sets the value of the GamePiece
  * \param An int representing the value to assign to the GamePiece
  */
  void                SetValue(int value) {this->Value = value;}
  /**
  * Sets the ID of the GamePiece
  * \param An int representing the ID to assign to the GamePiece
  */
  void                SetID(int id)       {this->ID = id;}

  /**
  * \brief      Compares this piece to another GamePiece
  * \param      A const pointer to a GamePiece
  * \return     An int representing the result of the comparison
  * \exception  Exception should be thrown if incompatible GamePiece is passed
  */
  virtual int         Compare(const GamePiece*) =0;
};

#endif // GAMEPIECE_HPP
