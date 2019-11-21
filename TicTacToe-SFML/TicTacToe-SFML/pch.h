#ifndef PCH_H
#define PCH_H
#pragma once

/* Common Includes */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <string.h>
#include <Windows.h>

/* SFML Includes */
#include "../../../Libraries/SFML/include/SFML/Graphics.hpp"
#include "../../../Libraries/SFML/include/SFML/Window.hpp"

/* TicTacToeGame Header Files */
#include "../TicTacToe-SFML/Headers/tic-tac-toe-game.h"
#include "../Headers/game-framework.h"
#include "../../SFML-GameFramework/SFML-GameFramework/Headers/game-framework-functions.h"

/* Namespace Declarations */
using namespace std::string_literals;
using namespace sf;
//using namespace GameFramework;


/* Macro definitions for filenames, XY coordinates for positions on gameboard */
#define X1 125
#define X2 315
#define X3 515
#define Y1 25
#define Y2 215
#define Y3 415

#define EXEPATH GameFramework::GameFrameworkFunctions::GetExeDir()
#define CWDPATH GameFramework::GameFrameworkFunctions::GetWorkingDir()
#define ASSETPATH(AssetDir) EXEPATH + "\\" + AssetDir
#define CWDASSETPATH(AssetDir) CWDPATH + "\\" + AssetDir

#endif //PCH_H
