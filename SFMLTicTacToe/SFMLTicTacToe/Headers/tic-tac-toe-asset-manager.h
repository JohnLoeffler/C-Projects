#ifndef TICTACTOEASSETMANAGER_HPP
#define TICTACTOEASSETMANAGER_HPP
#pragma once
#include "../pch.h"
#include "../../SFML-GameFramework/SFML-GameFramework/Headers/game-asset-manager.h"

class TicTacToeAssetManager : GameFramework::GameAssetManager{
public:
  /** 
  * @fn TicTacToeAssetManager()
  * @brief Default constructor
  */
  TicTacToeAssetManager();
  
  /**
  * @fn TicTacToeAssetManager(const char*)
  * @brief Default constructor
  */
  TicTacToeAssetManager(const char*);

  virtual ~TicTacToeAssetManager();
};


#endif // TICTACTOEASSETMANAGER_HPP