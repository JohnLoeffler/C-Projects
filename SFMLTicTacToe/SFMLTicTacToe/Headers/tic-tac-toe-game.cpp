#include "pch.h"
#include <fstream>
#include <sstream>
#include <string>

TicTacToeGame::TicTacToeGame(){
  this->Init();
  this->LoadAssets("Manifest.csv");
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
  // TODO Load Assets Into Asset Manager

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
  std::vector<const char*> paths, names;
  try{
    std::ifstream fin(path);
    std::string line;
    while(fin >> line){
      if(GameFramework::GameAssetType::IsAssetType(line)){

      }
    }
  } catch(std::exception e){

  }
  return filesLoaded;
}
