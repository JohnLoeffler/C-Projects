#include "pch.h"
#include <SFML/Graphics.hpp>
int  GameFramework::GameFramework::GameLoop(){

  return 0;
}

bool GameFramework::GameFramework::Init(){
  this->Window = new sf::RenderWindow(sf::VideoMode(800,600),"SFML GameFramework's Game Window");
  return true;
}

bool GameFramework::GameFramework::Play(){
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
  return true;
}

bool GameFramework::GameFramework::Exit(){

  return true;
}