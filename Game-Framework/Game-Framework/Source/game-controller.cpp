#include "../Headers/pch.h"
#include "../Headers/game-controller.h"
#include "../Headers/player.h"
#include "../Headers/game-piece.h"

GameFrame::GameController::GameController(int * value){
  this->SuperTestValue = value; 
  this->Board          = nullptr; 
  this->Rules          = nullptr; 
}

GameFrame::GameController::GameController(){ 
  this->SuperTestValue = nullptr; 
  this->Board          = nullptr;
  this->Rules          = nullptr;
}

GameFrame::GameController::~GameController(){
  if(this->SuperTestValue != nullptr){
    (*this->SuperTestValue)++;
  }
}
