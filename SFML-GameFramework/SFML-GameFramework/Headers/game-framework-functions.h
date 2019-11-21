#ifndef GAMEFRAMEWORKFUNCTIONS_H
#define GAMEFRAMEWORKFUNCTIONS_H
namespace GameFramework{
  class GameFrameworkFunctions{
  public:
    static const char* GetExeDir();
    static const char* GetWorkingDir();
    static long  LoadTexture(sf::Texture*, char*, bool = true, bool = false);
    static long  LoadTextureIntoSprite(sf::Texture*, sf::Sprite*);
  };
}
#endif // GAMEFRAMEWORKFUNCTIONS_H

