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
#include "../Headers/pch.h"
#include <vector>

/* 'Player' Class Definitions */

GameFrame::Player::Player() {
  this->GamePieces = nullptr;
  this->ID = INT_MIN;
  this->NumberOfGamePieces = INT_MIN;
  this->SuperTestValue = nullptr;
}

GameFrame::Player::Player(int* value) {
  this->GamePieces = nullptr;
  this->ID = INT_MIN;
  this->NumberOfGamePieces = INT_MIN;
  this->SuperTestValue = value;
}

GameFrame::Player::~Player() { if(SuperTestValue != nullptr) (*this->SuperTestValue)++; }

bool GameFrame::Player::Action(){}

/* 
* 'Players' Wrapper Class Definitions 
*/

// Parameterized Ctor //
template <class T>
GameFrame::Players<T>::Players(int* value) { this->SuperTestValue = value; }

// Setters //
template <class T>
inline void GameFrame::Players<T>::SetPlayers(std::vector<T*> players) { this->VectorOfPlayers = players; }

// Getters //
template <class T>
inline std::vector<T*> GameFrame::Players<T>::GetPlayers() { return this->VectorOfPlayers; }

template <class T>
inline unsigned GameFrame::Players<T>::GetNumberOfPlayers() { return this->VectorOfPlayers.size(); }

// Functional Methods //
template <class T>
bool GameFrame::Players<T>::RemovePlayer(T* player, int index){
  // Validate parameters and object initialization //
  if(this->VectorOfPlayers == nullptr)                  { return false; }
  if(index < 0 || index > this->VectorOfPlayers.size()) { return false; }
  
  // Pull player from vector and validate removal //
  size_t temp = this->VectorOfPlayers.size();
  player = this->VectorOfPlayers.at(index);
  this->VectorOfPlayers.erase(index);

  // Report results //
  return (this->VectorOfPlayers.size() == (temp-1) ? true:false);
}

template <class T>
bool GameFrame::Players<T>::RemovePlayer(const T* player){
  // Validate parameters and object initialization //
  if(player == nullptr){ return false; }
  if(this->VectorOfPlayers == nullptr){ return false; }
  if(this->VectorOfPlayers.size() <= 0){ return false; }

  // Locate any instance of player in vector and remove them //
  bool flag = false;
  for(int i = 0; i < this->VectorOfPlayers.size(); i++){
    if(this->VectorOfPlayers.at(i) == player){
      this->VectorOfPlayers.erase(i);
      
      // player found and removed //
      flag = true; 
    }
  }

  // Report results //
  return flag; 
}

template <class T>
bool GameFrame::Players<T>::AddPlayer(T* player){
  // Validate parameters and object initialization //
  if(player == nullptr) return false;
  
  // Add pointer to player to the vector, validate operation, and report result //
  size_t temp = this->VectorOfPlayers.size();
  this->VectorOfPlayers.emplace_back(player);
  return (this->VectorOfPlayers.size() == (1+temp) ? true:false);
}

