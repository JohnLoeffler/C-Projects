#include "pch.h"
#include "../../SFML-GameFramework/SFML-GameFramework/Headers/game-framework-exception.h"
#include <fstream>
#include <queue>

TicTacToeGame::TicTacToeGame(){
  if(this->Init()){
    this->Play();
  } else{
  std::cerr << "Init() Failed...";
  std::cin.get();
    LOG(_CRIT, "Game failed to Initialize!");
  }
}

TicTacToeGame::~TicTacToeGame(){
  delete this->Window;
}

int TicTacToeGame::GameLoop(){
  return 0;
}

bool TicTacToeGame::Init(){
  this->Window = new sf::RenderWindow(sf::VideoMode(800, 600), "Tic Tac Toe in SFML using GameFramework");
  try{
    this->AssetManager = new TicTacToeAssetManager(ASSET_PATH.c_str());
  } catch(std::exception ex){
    return false;
  }
  return true;
}

int TicTacToeGame::Play(){
  if(this->Window == nullptr){
    LOG(_CRIT, "Game Window Failed To Open");
    return -1;
  }
  std::queue<sf::Drawable> drawables;

  while(this->Window->isOpen()){
    sf::Event event;
    while(Window->pollEvent(event)){
      switch(event.type){
        case sf::Event::EventType::Closed: 
          Window->close(); 
          break;
        
        
        default: 
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
