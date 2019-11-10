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
*   <li>Twitter.com/ThisDotJohn</li>
* </ul>
*/
#include "../Headers/pch.h"

/* 'Player' Class Definitions */

GameFramework::GamePlayer::GamePlayer() {
  this->GamePieces = nullptr;
  this->PieceID = INT_MIN;
  this->NumberOfGamePieces = INT_MIN;
  this->SuperTestValue = nullptr;
}

GameFramework::GamePlayer::GamePlayer(int* value) {
  this->GamePieces = nullptr;
  this->PieceID = INT_MIN;
  this->NumberOfGamePieces = INT_MIN;
  this->SuperTestValue = value;
}

GameFramework::GamePlayer::~GamePlayer() { if(this->SuperTestValue != nullptr) ++(*this->SuperTestValue); }

/* 
* 'GamePlayers' Wrapper Class Definitions 
*/

// Parameterized Constructor //
GameFramework::GamePlayers::GamePlayers(int* value) { this->SuperTestWrapperValue = value; }

// Setters //
inline void GameFramework::GamePlayers::SetGamePlayers(std::vector<GameFramework::GamePlayer*> players) { this->VectorOfPlayers = players; }

// Getters //
inline std::vector<GameFramework::GamePlayer*> GameFramework::GamePlayers::GetGamePlayers() { return this->VectorOfPlayers; }

inline unsigned GameFramework::GamePlayers::GetNumberOfGamePlayers() { return this->VectorOfPlayers.size(); }

// Functional Methods //
bool GameFramework::GamePlayers::RemoveGamePlayer(int index){
  // Validate parameters and object initialization //
  if(index < 0 || (unsigned)index > this->VectorOfPlayers.size())    { return false; }
  if(this->VectorOfPlayers.size() == 0)                              { return false; }

  // Remove player from vector and validate deletion //
  size_t temp = this->VectorOfPlayers.size();
  this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + index);

  // Report results //
  return (this->VectorOfPlayers.size() == (temp - 1) ? true : false);
}

bool GameFramework::GamePlayers::RemoveGamePlayer(GameFramework::GamePlayer* player, int index){
  // Validate parameters and object initialization //
  if(player == nullptr)                                              { return false; }
  if(index < 0 || (unsigned)index > this->VectorOfPlayers.size())    { return false; }
  if(this->VectorOfPlayers.size() == 0)                              { return false; }
  
  // Pull player from vector and validate removal //
  size_t temp = this->VectorOfPlayers.size();
  player = this->VectorOfPlayers.at(index);
  this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + index);

  // Report results //
  return (this->VectorOfPlayers.size() == (temp-1) ? true:false);
}

bool GameFramework::GamePlayers::RemoveGamePlayer(const GameFramework::GamePlayer* player){
  // Validate parameters and object initialization //
  if(player == nullptr)                                              { return false; }
  if(this->VectorOfPlayers.size() <= 0)                              { return false; }

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

bool GameFramework::GamePlayers::AddGamePlayer(GamePlayer* player){
  // Validate parameters and object initialization //
  if(player == nullptr)                                              {return false;}
  
  // Add pointer to player to the vector, validate operation, and report result //
  size_t temp = this->VectorOfPlayers.size();
  this->VectorOfPlayers.emplace_back(player);
  return (this->VectorOfPlayers.size() == (1+temp) ? true:false);
}