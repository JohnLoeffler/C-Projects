#include "pch.h"
#include "../../../Libraries/SFML/include/SFML/Graphics.hpp"
#include "../../SFML-GameFramework/SFML-GameFramework/Headers/game-framework-functions.h"
/* Prototype Declarations */
int  ProcessInput(Keyboard::Key, int&);
bool Draw(RenderWindow*, std::vector<Drawable>);
bool LoadFiles(Texture*, char[], const char*);

int main()
{
  int choice = -1, menuPosition = 0;
  RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Tic Tac Toe SFML");
  window->setFramerateLimit(60);
  window->setMouseCursorVisible(false);
  while(window->isOpen()){
    
    Event event;
    while(window->pollEvent(event)){
      switch(event.type){
        case Event::Closed:
          window->close();
          break;
        case Event::KeyPressed:
          choice = ProcessInput(event.key.code, menuPosition);
          break;
        default:
          break;
      }
    }
    window->clear(Color::White);
    std::vector<Drawable> drawables;

    Texture *menuTexture, *cursorTexture, *gameboardTexture, *echsTexture, *ohTexture, 
      *horizontalStrokeTexture, *verticalStrokeTexture, *oneNineDiagonalStrokeTexture, 
      *threeSevenDiagonalStrokeTexture;
    Sprite *menuSprite, *cursorSprite, *gameboardSprite, *echsSprite, *ohSprite,
      *horizontalStrokeSprite, *verticalStrokeSprite, *oneNineDiagonalStrokeSprite,
      *threeSevenDiagonalStrokeSprite;

    char path[MAX_PATH];
    char* decalsDir, *menuArtDir, *filesNotLoaded;
    strcpy(path, GameFramework::GameFrameworkFunctions::GetWorkingDir());
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



bool Draw(RenderWindow* window, std::vector<Drawable> drawables){

  return true;
}

bool LoadFiles(Texture* texture, char path[], const char* filename){
  char fileLocation[MAX_PATH];
  strcpy(fileLocation, path);
  strcpy(fileLocation, filename);
  return texture->loadFromFile(fileLocation);
}

//bool LoadSprites(Texture* menu, Texture* cursor, Texture* gameboard, Texture* echs, Texture* ohs, Texture* hztl, Texture* vert, Texture* diagOneNine, Texture* diagThreeSeven,
//  Sprite* menuSp, Sprite* cursorSp, Sprite* gameboardSp, Sprite* echsSp, Sprite* ohsSp, Sprite* hztlSp, Sprite* vertSp, Sprite* diagOneNineSp, Sprite* diagThreeSevenSp){
//
//
//}

int ProcessInput(Keyboard::Key keyPressed, int& position){
  switch(keyPressed){
    //  Manage keystrokes and update the game menu accordingly
    case Keyboard::Up:
      switch(position){
        case 1:
          position = 0;
          break;
        default:
          break;
      }
      break;
    case Keyboard::Down:
      switch(position){
        case 0:
          position = 1;
          break;
        default:
          break;
      }
      break;
    case Keyboard::Escape:
      return 0;
    case Keyboard::Enter:
      return 1;
    default:
      break;
  }
  return -1;
}