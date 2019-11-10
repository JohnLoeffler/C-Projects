/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Any source code included in this package written by myself, John Loeffler, is
* free to use as-is for any purpose, commercial and non-commercial alike, so
* long as the license & header documentation containing my contact info and
* link to the original source file on Github remains intact.
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
* @brief Implementation of GamePiece.h (Empty for now)
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

#include "../Headers/game-piece.h"
#include "../Headers/pch.h"

GameFramework::GamePiece::GamePiece(){
  PieceID = NextID; IncrementID(); Value = 1; SuperTestValue = nullptr;
}

GameFramework::GamePiece::GamePiece(int* value){
  Value = *value; 
  PieceID = NextID; 
  IncrementID(); 
  SuperTestValue = value;
}

GameFramework::GamePiece::~GamePiece(){ ++(*this->SuperTestValue); }

////////////////////////////////////
/* GamePieces Wrapper Definitions */
////////////////////////////////////

GameFramework::GamePieces::GamePieces(){
  this->SuperTestWrapperValue = nullptr;
}

GameFramework::GamePieces::GamePieces(int* value){
  *this->SuperTestWrapperValue = *value;
}

GameFramework::GamePieces::~GamePieces()   { ++(*this->SuperTestWrapperValue); }

bool GameFramework::GamePieces::AddGamePiece(GameFramework::GamePiece* piece){
  // Validate parameter and object initialization //
  if(piece == nullptr)                                      { return false; }

  // Add piece, verify operation, and report results //
  size_t temp = this->Pieces.size();
  Pieces.emplace_back(piece);
  return (this->Pieces.size() == (temp + 1) ? true : false);
}


bool GameFramework::GamePieces::RemoveGamePiece(int index){
  // Validate parameter and object initialization //
  if(index < 0 || (unsigned) index >= this->Pieces.size() ) { return false; }
  if(this->Pieces.size() == 0)                              { return false; }

  // Remove piece at Index, verify operation, and report results //
  size_t temp = this->Pieces.size();
  this->Pieces.erase(this->Pieces.begin()+index);
  return (this->Pieces.size() == (temp-1) ? true:false);
}

bool GameFramework::GamePieces::RemoveGamePiece(const GameFramework::GamePiece* piece) {
  // Validate parameter and object initialization //
  if(piece == nullptr)                                      { return false; }
  if(this->Pieces.size() == 0)                              { return false; }
  
  // Search for piece in vector, remove all instances of it, verify operations, and report results //
  unsigned count = 0, temp = this->Pieces.size();
  
  for(unsigned i = 0; i < this->Pieces.size(); i++){
    if(this->Pieces.at(i) == piece){
      count++;
      this->Pieces.erase(this->Pieces.begin() + i);
      i--;
    }
  }
  return (this->Pieces.size() == (temp - count) ? true : false);
}

bool GameFramework::GamePieces::RemoveGamePiece(GameFramework::GamePiece* piece, int index){
  // Validate parameters and object instantiation //
  if( index < 0 || (unsigned) index >= this->Pieces.size())  { return false; }
  
  // Assign pointer from vector to external reference variable //
  piece = this->Pieces.at(index);

  // Remove piece at Index, verify operation, and report results //
  size_t temp = this->Pieces.size();
  this->Pieces.erase(this->Pieces.begin() + index);
  return (this->Pieces.size() == (temp - 1) ? true : false);
}
