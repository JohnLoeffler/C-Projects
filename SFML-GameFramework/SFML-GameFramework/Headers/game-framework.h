#ifndef GAMEFRAMEWORK_HPP
#define GAMEFRAMEWORK_HPP
#include "../pch.h"
#include "SFML/Graphics.hpp"

namespace GameFramework{
  class GameBoard;
  class GameController;
  enum  GameLoopState;
  class GameState;

  class GameFramework{
  protected:
    sf::RenderWindow*  Window;
    GameBoard*         Board;
    GameController*    Controller;
    sf::Clock          OuterGameClock;
    GameLoopState      CurrentState, NextDesiredState;
    GameState*         ActiveState;
    GameAssetManager*  AssetManager;


  public:
    /**
    * @fn GameFramework
    * @brief Default Constructor
    */
    GameFramework(){}
    /**
    * @fn ~GameFramework
    * @brief Destructor
    */
    virtual ~GameFramework(){}

    /**
    * @fn GameLoop()
    * @brief The Main loop for the game
    * @return A diagnostic int code for the closure of the GameLoop.
    */
    virtual int GameLoop() = 0;

    /**
    * @fn Init()
    * @brief Initializes the GameFramework
    */
    virtual bool Init() = 0;
    /**
    * @fn Play()
    * @brief Begins playing the game 
    */
    virtual int Play() = 0;
    ///**
    //* @fn Load()
    //* @brief Loads a previously saved GameState
    //*/
    //virtual bool Load(GameFile*) = 0;
    ///**
    //* @fn Save()
    //* @brief Saves the current game to a GameState
    //*/
    //virtual GameFile* Save() = 0;
    /**
    * @fn Exit()
    * @brief Exits the current game
    */
    virtual bool Exit() = 0;

    /**
    * @fn LoadAssets(const char*)
    * @brief Loads the assets used for the game
    * @param the path to the manifest holding the asset filenames to be loaded
    */
    virtual int LoadAssets(const char*) = 0;
  };
}

#endif // GAMEFRAMEWORK_HPP
