#ifndef TICTACTOEGAME_HPP
#define TICTACTOEGAME_HPP
#pragma once

#include "../pch.h"

class TicTacToeGame : public GameFramework::GameFramework{
protected:
  TicTacToeAssetManager* AssetManager;
public:
  TicTacToeGame();

  /**
  * @fn ~TicTacToeGame()
  * @brief Destructor
  */
  virtual      ~TicTacToeGame();
  /**
  * @fn GameLoop()
  * @brief The inner loop that drives the gameplay
  * @return An int with an error code if error occurs, or '0' if loop quits successfully
  */
  virtual int  GameLoop();
  /**
  * @fn Init()
  * @brief Sets up the gameboard, controller, players, and pieces
  * @return True if Init() was successful, false otherwise
  */
  virtual bool Init();
  /**
  * @fn Play()
  * @brief Begins gameplay
  * @return True if Play() encountered no errors, false otherwise
  */
  virtual int Play();
  /**
  * @fn Exit()
  * @brief Exits the game menu and shuts down the program
  * @return True if Exit() encountered no errors, false otherwise
  */
  virtual bool Exit();

  /**
  * @fn LoadAssets(GameAssetManager*, const char*)
  * @brief Loads the assets used for the game
  * @param A pointer to the GameAssetManager
  * @param A string of the path where the file manifest is located
  */
  virtual int LoadAssets(const char*);

};

#endif // TICTACTOEGAME_HPP
