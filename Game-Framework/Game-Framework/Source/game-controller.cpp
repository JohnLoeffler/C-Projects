#include "game-controller.h"
#include "pch.h"

// GamePiece Definitions //

GameFramework::GameController::GameController(int * value){
  this->SuperTestValue = value; 
  this->Board          = nullptr; 
  this->Rules          = nullptr; 
}

GameFramework::GameController::GameController(){ 
  this->SuperTestValue = nullptr; 
  this->Board          = nullptr;
  this->Rules          = nullptr;
}

// GamePieces Wrapper Definitions //



