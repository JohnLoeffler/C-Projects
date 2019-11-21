#include "pch.h"
#include "../Headers/game-framework-functions.h"

/* Prototype Declarations */
int  ProcessInput(sf::Keyboard::Key, int&);
bool Draw(sf::RenderWindow*, std::vector<Drawable>);
bool LoadFiles(sf::Texture*, char[], const char*);

int main()
{
  int choice = -1, menuPosition = 0;
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Tic Tac Toe SFML");
  window->setFramerateLimit(60);
  window->setMouseCursorVisible(false);
  while(window->isOpen()){
    
    sf::Event event;
    while(window->pollEvent(event)){
      switch(event.type){
        case sf::Event::Closed:
          window->close();
          break;
        case sf::Event::KeyPressed:
          choice = ProcessInput(event.key.code, menuPosition);
          break;
        default:
          break;
      }
    }
    window->clear(sf::Color::White);
    std::vector<Drawable> drawables;

    sf::Texture *menuTexture, *cursorTexture, *gameboardTexture, *echsTexture, *ohTexture, 
      *horizontalStrokeTexture, *verticalStrokeTexture, *oneNineDiagonalStrokeTexture, 
      *threeSevenDiagonalStrokeTexture;
    sf::Sprite *menuSprite, *cursorSprite, *gameboardSprite, *echsSprite, *ohSprite,
      *horizontalStrokeSprite, *verticalStrokeSprite, *oneNineDiagonalStrokeSprite,
      *threeSevenDiagonalStrokeSprite;

    char path[MAX_PATH];
    char* decalsDir, *menuArtDir, *filesNotLoaded;
    strcpy(path, CWDPATH);
    strcpy(path, "\\TicTacToeArtwork\\");
    strcpy(decalsDir, path);
    strcpy(decalsDir, "\\decals\\");
    strcpy(menuArtDir, path);
    strcpy(menuArtDir, "\\Menu-Art\\");

    if(!LoadFiles(menuTexture, menuArtDir, "TicTacToeMenu.png")){ strcpy(filesNotLoaded, "TicTacToeMenu.png");}
    if(!LoadFiles(cursorTexture, menuArtDir, "arrow-cursor.png")){ strcpy(filesNotLoaded, ", arrow-cursor.png"); }
    if(!LoadFiles(gameboardTexture, path, "GameBoard.png")){strcpy(filesNotLoaded, ", GameBoard.png");}
    if(!LoadFiles(echsTexture, decalsDir, "Echs.png")){ strcpy(filesNotLoaded, ", Echs.png"); }
    if(!LoadFiles(ohTexture, decalsDir, "Oh.png")){ strcpy(filesNotLoaded, ", Oh.png"); }
    if(!LoadFiles(horizontalStrokeTexture, decalsDir, "stroke-horizontal.png")){ strcpy(filesNotLoaded, ", stroke-horizontal.png"); }
    if(!LoadFiles(verticalStrokeTexture, decalsDir, "stroke-vertical.png")){ strcpy(filesNotLoaded, ", stroke-vertical.png"); }
    if(!LoadFiles(oneNineDiagonalStrokeTexture, decalsDir, "stroke-1-5-9.png")){ strcpy(filesNotLoaded, ", stroke-1-5-9.png"); }
    if(!LoadFiles(threeSevenDiagonalStrokeTexture, decalsDir, "stroke-3-5-7.png")){ strcpy(filesNotLoaded, ", stroke-3-5-7.png"); }



    char currentFile[MAX_PATH];

    /* Here, I need to load up a queue of Sprites and call a funtion to draw them in the proper sequence */
    if(Draw(window, drawables)){
      window->display();
    }

  }
}



bool Draw(sf::RenderWindow* window, std::vector<Drawable> drawables){

  return true;
}

bool LoadFiles(sf::Texture* texture, char path[], const char* filename){
  char fileLocation[MAX_PATH];
  strcpy(fileLocation, path);
  strcpy(fileLocation, filename);
  return texture->loadFromFile(fileLocation);
}

bool LoadSprites(sf::Texture* menu, sf::Texture* cursor, sf::Texture* gameboard, sf::Texture* echs, sf::Texture* ohs, sf::Texture* hztl, sf::Texture* vert, sf::Texture* diagOneNine, sf::Texture* diagThreeSeven,
  sf::Sprite* menuSp, sf::Sprite* cursorSp, sf::Sprite* gameboardSp, sf::Sprite* echsSp, sf::Sprite* ohsSp, sf::Sprite* hztlSp, sf::Sprite* vertSp, sf::Sprite* diagOneNineSp, sf::Sprite* diagThreeSevenSp){


}

int ProcessInput(sf::Keyboard::Key keyPressed, int& position){
  switch(keyPressed){
    //  Manage keystrokes and update the game menu accordingly
    case sf::Keyboard::Up:
      switch(position){
        case 1:
          position = 0;
          break;
        default:
          break;
      }
      break;
    case sf::Keyboard::Down:
      switch(position){
        case 0:
          position = 1;
          break;
        default:
          break;
      }
      break;
    case sf::Keyboard::Escape:
      return 0;
    case sf::Keyboard::Enter:
      return 1;
    default:
      break;
  }
  return -1;
}