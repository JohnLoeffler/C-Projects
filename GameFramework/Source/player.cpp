#include "../Headers/player.hpp"
#include <bits/stdc++.h>
Player::Player(){
  this->GamePieces = nullptr;
  this->ID = INT_MIN;
}

Player::~Player(){
  (*TestValue)++;
  if(this->GamePieces != nullptr){
    for(int i = 0; i< this->GetNumberOfGamePieces(); i++){
      this->GamePieces[i] = nullptr;
    }
    this->GamePieces = nullptr;
  }
}
