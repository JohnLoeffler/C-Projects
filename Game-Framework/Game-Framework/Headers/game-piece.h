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
* @file ${File}
*
* @brief An abstract class from which different game pieces can be derived
*
* @ingroup ${ProjectName}
*
* @author John Loeffler
* <ul>contact:
*   <li>John.Loeffler@gmail.com</li>
*   <li>JohnLoeffler.com</li>
*   <li>Github.com/JohnLoeffler</li>
*   <li>LinkedIn.com/in/JohnLoeffler</li>
* </ul>
*/
#ifndef GAMEPIECE_HPP
#define GAMEPIECE_HPP
#include "../Headers/pch.h"
#include "../Headers/game-framework-exception.h"
#pragma once

/**
*  @brief An abstract class from which other game pieces can be derived. The GamePiece 
*   class is the base class for all game pieces in the GameFramework package. Everything 
*   from chess pieces to playing cards are derived from this class. As such, the 
*   'Compare' method must be defined for each derived type.
*/
namespace GameFramework{
  class GamePiece{
    /* @brief An int tracker to assign unique ID numbers to newly created pieces */
  
  protected:
    int*         SuperTestValue;
    int          Value, PieceID;

  public:
    /**
    * @fn GamePiece(int*)
    * @brief Parameterized contructor to unit test destructor functionality
    * @param int Pointer to an external variable which will record changes made by destructor
    */
    GamePiece(int* value){
      Init();
      this->SuperTestValue = value;
    }
    /** 
    * @fn GamePiece() 
    * @brief Default Constructor
    */
    GamePiece(){ 
      Init();
    }
    /** 
    * @fn ~GamePiece() 
    * @brief Destructor  
    */
    virtual ~GamePiece()       { ++(*this->SuperTestValue); this->SuperTestValue = nullptr;}

    // Getters //
    /**
    * @fn int GetValue()
    * @brief Gets the value of the GamePiece
    * @return An int of the GamePiece's value
    */
    int     GetValue()         { return this->Value; }
    /**
    * @fn int GetPieceID()
    * @brief Returns an identifying ID for the piece
    * @return An int of the GamePiece's ID number
    */
    int     GetPieceID()       { return this->PieceID; }



    // Setters //
    /**
    * @fn void SetValue(int)
    * @brief Sets the value of the GamePiece
    * @param An int representing the value to assign to the GamePiece
    */
    void    SetValue(int value){ this->Value = value; }
    

    // Functional Methods //
    /**
    * @fn int Compare(const GamePiece*)
    * @brief      Compares this piece to another GamePiece
    * @param      A const pointer to a GamePiece
    * @return     An int representing the result of the comparison
    * @exception  GameFrameworkException should be thrown if incompatible GamePiece is passed
    */
    int     Compare(GamePiece* rhs) throw(...) {
      if( typeid(this) == typeid(rhs)){
        return(this->GetValue() - rhs->GetValue());
      } else{
        throw GameFrameworkException("GameFrameworkException thrown when attempting to compare incompatible GamePiece classes!", __FILE__, __LINE__);
      }
    }

        /** 
    * @fn GetSuperTestValue() 
    * @brief Gets the Test pointer 
    */
    int*    GetSuperTestValue(){return this->SuperTestValue;}

    private:
    void    Init(){ this->PieceID = INT_MIN; this->SuperTestValue = nullptr; this->Value = INT_MIN;}
  };
}
#endif // GAMEPIECE_HPP