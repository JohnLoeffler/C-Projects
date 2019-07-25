#include "../Headers/game-board.hpp"
#include <bits/stdc++.h>
GameBoard::GameBoard(){
  this->Players = nullptr;
  this->GamePieces = nullptr;
  this->CurrentGameController = nullptr;
  this->CurrentGameState = nullptr;
  this->NumGamePieces = INT_MIN;
  this->NumPlayers = INT_MIN;
}

GameBoard::~GameBoard(){
  (*TestValue)++;
  this->CurrentGameController = nullptr;
  this->CurrentGameState = nullptr;

  if(this->Players != nullptr){
    for(int i = 0; i < this->GetNumberOfPlayers(); i++){
      this->Players[i] = nullptr;
    }
  }

  if(this->GamePieces != nullptr){
    for(int i = 0; i < this->GetNumberOfGamePieces(); i++){
      this->GamePieces[i] = nullptr;
    }
  }
}
