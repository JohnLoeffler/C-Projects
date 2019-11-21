#include "pch.h"
#include <windows.h>
#include <Shlwapi.h>

const char* GameFramework::GameFrameworkFunctions::GetExeDir(){
  char path[MAX_PATH] = "";
  GetModuleFileNameA(NULL, path, MAX_PATH);
  PathRemoveFileSpecA(path);
  PathAddBackslashA(path);
  return path;
}

const char* GameFramework::GameFrameworkFunctions::GetWorkingDir(){
  char path[MAX_PATH] = "";
  GetCurrentDirectoryA(MAX_PATH, path);
  PathAddBackslashA(path);
  return path;
}

long  GameFramework::GameFrameworkFunctions::LoadTexture(sf::Texture* texture, char* filepath, bool smooth, bool tiled){
  long bytes = 0; 
  if(!texture->loadFromFile(filepath)){
    std::cout<< "Error loading " << filepath <<"!";
  }
  texture->setSmooth(smooth);
  texture->setRepeated(tiled);
}
long  GameFramework::GameFrameworkFunctions::LoadTextureIntoSprite(sf::Texture* texture, sf::Sprite* sprite){
  sprite->setTexture(*texture);
}