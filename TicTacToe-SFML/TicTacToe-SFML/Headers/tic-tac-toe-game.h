#ifndef TICTACTOEGAME_HPP
#define TICTACTOEGAME_HPP
#include "../Headers/game-framework.h"
#pragma once

class TicTacToeGame : public GameFramework::GameFramework{
protected:

public:

/**
* @fn TicTacToeGame()
* @brief Default Constructor
*/
TicTacToeGame();

/**
* @fn ~TicTacToeGame()
* @brief Destructor
*/
virtual ~TicTacToeGame();
/**
* @fn GameLoop()
* @brief The inner loop that drives the gameplay
*/
virtual int  GameLoop();
/**
* @fn Init()
* @brief Sets up the gameboard, controller, players, and pieces
*/
virtual bool Init();
/**
* @fn Play()
* @brief Begins gameplay
*/
virtual bool Play();
/**
* @fn Exit()
* @brief Exits the game menu and shuts down the program
*/
virtual bool Exit();

};

#endif
