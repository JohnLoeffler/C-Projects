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
#include "../../TicTacToe-SFML/TicTacToe-SFML/Headers/tic-tac-toe-game.h"
#include "../../TicTacToe-SFML/TicTacToe-SFML/Headers/tic-tac-toe-file-manager.h"

/* Namespace Declarations */
using namespace std::string_literals;
using namespace sf;

/* Macro definitions for filenames, XY coordinates for positions on gameboard */
#define XL 125
#define XM 315
#define XR 515
#define YU 25
#define YM 215
#define YD 415

#include "../../SFML-GameFramework/SFML-GameFramework/Headers/game-framework-functions.h"
#define EXEPATH GameFramework::GameFrameworkFunctions::GetExeDir()
#define CWDPATH GameFramework::GameFrameworkFunctions::GetWorkingDir()

#endif //PCH_H
