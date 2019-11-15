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
    static int   NextID;

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
      this->Value = *value;
      IncrementID();
      this->PieceID = this->NextID;
      this->SuperTestValue = value;
    }
    /** 
    * @fn GamePiece() 
    * @brief Default Constructor
    */
    GamePiece(){ 
      Init();
      GamePiece::IncrementID();
      this->PieceID = this->NextID;
      this->Value = 1; 
      this->SuperTestValue = nullptr; 
    }
    /** 
    * @fn ~GamePiece() 
    * @brief Destructor  
    */
    virtual ~GamePiece()       { ++(*this->SuperTestValue); }

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
    /**
    * @fn void SetID(int)
    * @brief Sets the ID of the GamePiece
    * @param An int representing the ID to assign to the GamePiece
    */
    void    SetPieceID(int id) { this->PieceID = id; }


    // Functional Methods //
    /**
    * @fn int Compare(const GamePiece*)
    * @brief      Compares this piece to another GamePiece
    * @param      A const pointer to a GamePiece
    * @return     An int representing the result of the comparison
    * @exception  GameFrameworkException should be thrown if incompatible GamePiece is passed
    */
    int     Compare(GamePiece* rhs) throw(GameFrameworkException) {
      if( typeid(this) == typeid(rhs)){
        return(this->GetValue() - rhs->GetValue());
      } else{
        throw GameFrameworkException("GameFrameworkException thrown when attempting to compare incompatible GamePiece classes!", __FILE__, __LINE__);
      }
    }

    /** @fn IncrementID() @brief Increments to the next usable GamePieceID for assignment */
    void    IncrementID(){++NextID;}
  
    int*    GetSuperTestValue(){return this->SuperTestValue;}
    private:
    void    Init(){GamePiece::NextID = 0;}
    static  int GetNextID() { return NextID; }
  };
}

/**
* @brief A wrapper class for a collections of GamePieces to make grouping and managing them easier
*/
namespace GameFramework{
  class GamePieces{
  protected:
    /* Data Members */
    int*    SuperTestWrapperValue;
    std::vector<GamePiece*> Pieces;
    
  public:
    /******************************
    * Constructors and Destructor *
    ******************************/

    /**
    * @fn GamePieces(int*)
    * @brief Parameterized Constructor
    */
    GamePieces(int* value)     { this->SuperTestWrapperValue = value; }
    /**
    * @fn GamePieces()
    * @brief Default Constructor
    */
    GamePieces()               { this->SuperTestWrapperValue = nullptr; }
    /**
    * @fn ~GamePieces()
    * @brief Destructor
    */
    virtual   ~GamePieces()    { ++(*this->SuperTestWrapperValue); }

    /*********************
    *      Getters      *
    *********************/

    /**
    * @fn GetGamePieces()
    * @brief Gets the vector of GamePieces from the container.
    * @return A vector of GamePiece pointers
    */
    std::vector<GamePiece*>    GetGamePieces(){ return this->Pieces;  }
    /**
    * @fn GetNumberOfGamePieces()
    * @brief Gets the number of GamePieces in the container
    * @return A size_t of the size of the containers vector of GamePiece pointers
    */
    size_t GetNumberOfGamePieces()         { return this->Pieces.size(); }

    /*********************
    * Functional Methods *
    *********************/
    
    /**
    * @fn AddGamePiece(GamePiece*)
    * @brief Adds a GamePiece pointer to the container
    * @param A pointer to the game piece to add to the container
    * @return True if the addition to the vector was successful, false otherwise
    */
    bool AddGamePiece(GamePiece* piece){
      // Validate parameter and object initialization //
      if(piece == nullptr){ return false; }

      // Add piece, verify operation, and report results //
      size_t temp = this->Pieces.size();
      Pieces.emplace_back(piece);
      return (this->Pieces.size() == (temp + 1) ? true : false);
    }
    
    /**
    * @fn RemoveGamePiece(GamePiece*, int)
    * @brief Adds a GamePiece pointer to the container
    * @param A GamePiece pointer that returns the GamePiece pointer to the calling function rather than destroying it
    * @param An int for the GamePiece's index in the containers vector
    * @return True if the removal of the GamePiece was successful, false otherwise
    */
    bool RemoveGamePiece(GamePiece* piece, int index){
      // Validate parameters and object instantiation //
      if(index < 0 || (unsigned)index >= this->Pieces.size()){ return false; }

      // Assign pointer from vector to external reference variable //
      piece = this->Pieces.at(index);

      // Remove piece at Index, verify operation, and report results //
      size_t temp = this->Pieces.size();
      this->Pieces.erase(this->Pieces.begin() + index);
      return (this->Pieces.size() == (temp - 1) ? true : false);
    }
    
    /**
    * @fn RemoveGamePiece(int)
    * @brief removes a GamePiece pointer from the container based on its index in the underlying vector
    * @param An int for the index of the GamePiece to remove
    * @return True if the removal of the GamePiece was successful, false otherwise
    */
    bool RemoveGamePiece(int index){
      // Validate parameter and object initialization //
      if(index < 0 || (unsigned)index >= this->Pieces.size()){ return false; }
      if(this->Pieces.size() == 0){ return false; }

      // Remove piece at Index, verify operation, and report results //
      size_t temp = this->Pieces.size();
      this->Pieces.erase(this->Pieces.begin() + index);
      return (this->Pieces.size() == (temp - 1) ? true : false);
    }

    /**
    * @fn RemoveGamePiece(const GamePiece*)
    * @brief Removes any instance of a GamePiece pointer from the container
    * @param A const GamePiece pointer to remove from the container
    * @return True if the GamePiece was found and all instances removed from the containers vector
    */
    bool RemoveGamePiece(const GamePiece* piece){
      // Validate parameter and object initialization //
      if(piece == nullptr){ return false; }
      if(this->Pieces.size() == 0){ return false; }

      // Search for piece in vector, remove all instances of it, verify operations, and report results //
      unsigned count = 0;
      unsigned temp = this->Pieces.size();
      for(unsigned i = 0; i < this->Pieces.size(); i++){
        if(this->Pieces.at(i) == piece){
          count++;
          this->Pieces.erase(this->Pieces.begin() + i);
          i--;
        }
      }
      return (this->Pieces.size() == (temp - count) ? true : false);
    }
  };
}
#endif // GAMEPIECE_HPP