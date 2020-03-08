#include "pch.h"
#include <fstream>

TicTacToeGame::TicTacToeGame(){
  this->Init();
  this->Play();
}

TicTacToeGame::~TicTacToeGame(){
  delete this->Window;
}

int TicTacToeGame::GameLoop(){
  return 0;
}

bool TicTacToeGame::Init(){
  this->Window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML GameFramework's Game Window");
  return true;
}

int TicTacToeGame::Play(){
  if(this->Window == nullptr){
    LOG(_CRIT, "Game Window Failed To Open");
    return -1;
  }
  while(Window->isOpen()){
    sf::Event event;
    while(Window->pollEvent(event)){
      switch(event.type){
        case sf::Event::EventType::Closed:
          Window->close();
          break;
      }
    
    }
    Window->clear();
    Window->display();
  }
  return 0;
}

bool TicTacToeGame::Exit(){
  return false;
}

int TicTacToeGame::LoadAssets(const char* path){
  int filesLoaded = 0;

  return filesLoaded;
}
