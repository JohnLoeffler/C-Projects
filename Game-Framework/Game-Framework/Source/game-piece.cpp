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

#include "../Headers/pch.h"
#include "../Headers/game-piece.h"

template<class GamePiece>
unsigned GameFrame::GamePieces<GamePiece>::AddGamePiece(GamePiece* piece){
  for(int i = 0; i < Pieces.size(); i++){
    if(Pieces.at(i) == piece){
      return Pieces.size();
    }
  }
  this->Pieces.push_back(piece);
  return this->Pieces.size();
}

template <class GamePiece>
GamePiece* GameFrame::GamePieces<GamePiece>::RemoveGamePiece(int index){
  if(index < 0 || index >= this->Pieces.size()){
    char buf[256];
    sprintf_s(buf, 256, "Index passed to RemoveGamePiece is out of bounds| Index: %d Size: %d", index, this->Pieces.size());
    throw new GameFrameworkException(buf);
  }
  GamePiece* piece = this->Pieces.at(index);
  this->Pieces.erase(index);
  return piece;
}

template <class GamePiece>
void GameFrame::GamePieces<GamePiece>::RemoveGamePiece(GamePiece* piece){
  if (piece == nullptr) {
    char buf[256];
    sprintf_s(buf, 256,"GamePiece* passed to RemoveGamePiece is a nullptr.");
    throw new GameFrameworkException(buf);
  }
  for(int i = 0; i < Pieces.size(); i++){
    if(Pieces.at(i) == piece){
      Pieces.erase(i);
    }
  }
}