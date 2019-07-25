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
* @brief An abstract class from which different player types can be derived
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
#include "pch.h"
#include "game-board.hpp"

GameBoard::GameBoard() noexcept {
  this->Players = nullptr;
  this->GamePieces = nullptr;
  this->CurrentGameController = nullptr;
  this->CurrentGameState = nullptr;
  this->NumGamePieces = INT_MIN;
  this->NumPlayers = INT_MIN;
  this->TestValue = nullptr;
}

 GameBoard::GameBoard(int* value) noexcept{
   this->TestValue = value;
   this->Players = nullptr;
   this->GamePieces = nullptr;
   this->CurrentGameController = nullptr;
   this->CurrentGameState = nullptr;
   this->NumGamePieces = INT_MIN;
   this->NumPlayers = INT_MIN;
 }

#pragma warning(suppress: 26432)
GameBoard::~GameBoard() {
  (*TestValue)++;
  this->CurrentGameController = nullptr;
  this->CurrentGameState = nullptr;

  if (this->Players != nullptr) {
    for (int i = 0; i < this->NumPlayers; i++) {
      this->Players[i] = nullptr;
    }
  }

  if (this->GamePieces != nullptr) {
    for (int i = 0; i < this->NumGamePieces; i++) {
      this->GamePieces[i] = nullptr;
    }
  }
}
