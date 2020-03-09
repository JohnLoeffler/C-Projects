#include "pch.h"

TicTacToeGame::TicTacToeGame(){
  if(!this->Init()){
    std::cerr << "TicTacToeGame did not initialize properly! Check LoadAssets()!";
    exit(1);
  }
  this->Play();
}

TicTacToeGame::~TicTacToeGame(){
  delete this->Window;
}

int TicTacToeGame::GameLoop(){
  return 0;
}

bool TicTacToeGame::Init(){
  this->Window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML Tic-Tac-Toe Game Window");
  this->AssetManager = new TicTacToeAssetManager("manifest.txt");
  return this->AssetManager->LoadAssets();
}

int TicTacToeGame::Play(){
  if(this->Window == nullptr){
    LOG(_CRIT, "Game Window Failed To Open");
    return -1;
  }
  sf::Clock clock;
  const float FPS = 60.0f;
  bool redraw = true;
  this->Window->setFramerateLimit((unsigned int) FPS);

  while(Window->isOpen()){
    
    sf::Time deltaTime = clock.restart();

    /* Process Input Events */
    sf::Event event;
    while(Window->pollEvent(event)){
      switch(event.type){
        case sf::Event::EventType::Closed:
          Window->close();
          break;
      // TODO Implement other input events, such as screen-clicks and keystrokes
      }
    }
    
    Window->clear();
    
    // TODO Create an update function that runs Game Logic here, updating all actors and the game state and takes a deltaTime float as the parameter
    
    Window->display();
  }
  return 0;
}

bool TicTacToeGame::Exit(){
  return false;
}

int TicTacToeGame::LoadAssets(const char* path){
  return -1;
}
