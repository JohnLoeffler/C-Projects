/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Any source code included in this package written by myself, John Loeffler, is
 * free to use as-is for any purpose, commercial and non-commercial alike, so
 * long as the license & header documentation containing my contact info and
 * link to the original source file on Github remains intact.
 *
 * Any source code included in this package that was written by others maintains
 * its own licensing terms that must be followed, and this license in no way
 * supersedes that license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License v 3.0 for more details.
 *
 * see <https://www.gnu.org/licenses/gpl-3.0.en.html>.
 */
/**
 * @file game-controller.h
 *
 * @brief An abstract class from which different Game Controller types can be derived
 *
 * @ingroup game-framework
 *
 * @author John Loeffler
 * <ul>contact:
 *   <li>John.Loeffler@gmail.com</li>
 *   <li>JohnLoeffler.com</li>
 *   <li>Github.com/JohnLoeffler</li>
 *   <li>LinkedIn.com/in/JohnLoeffler</li>
 * </ul>
 */
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#pragma once
#include "../Headers/pch.h"

class GamePlayers;
class GamePlayer;
class GameBoard;
class GamePiece;
class GamePieces;
class GameRuleSet;
class GameController;

/**
 * @brief Defines the abstract GameController class so different controllers can be derived
 *
 * Maps out the contours of an abstract GameController class that can be extended to operate like
 *  and Singleton/Subscriber to a GameBoard on which a game is played. The GameBoard has a reference
 *  to the controller, so it is the GameBoard's responsibility to notify the Controller about changes
 *  in GameState, according to implementation.
 * 
 */
namespace GameFramework{
  using namespace GameFramework;
  class GameController{
  protected:
    GamePlayers*  CurrentPlayers;
    GamePieces*   ControllerPieces;
    GameBoard*    Board;
    GameRuleSet*  Rules;

    int*          SuperTestValue;  // External reference variable for unit testing purposes
    /**
    * @fn GameController(int*)
    * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
    * @param int* A pointer to an int variable that can be persistently changed by the class destructor
    */
            GameController(int* value);
  public:
    /**
    * @fn GameController()
    * @brief Default constructor
    */
            GameController();
    /**
    * @fn ~GameController()
    * @brief Virtual destructor
    */
    virtual ~GameController(){}
  };
}
#endif  //  GAMECONTROLLER_H
