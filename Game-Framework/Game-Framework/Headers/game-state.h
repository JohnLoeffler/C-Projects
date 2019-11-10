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
 * @file player.hpp
 *
 * @brief An abstract class from which different GameState Data Structures can be derived
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
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../Headers/pch.h"
class GamePlayer;

/**
 * @brief Defines the abstract GameState class for Game data objects
 *
 * While it defaults to just recording a winning player and a score, the GameState can 
 *  be extended to contain all kinds of game data, even making it possible to save a game
 *  and come back to it later
 */
namespace GameFramework{
  class GameState{
    const GamePlayer*   Winner;
    int                 Score;
    int*                SuperTestValue;
  public:
    /** @fn GameState() @brief Default Constructor */
    GameState(){ Winner = nullptr; Score = -1; SuperTestValue = nullptr; }
    /** @fn ~GameState() @brief Destructor */
    virtual ~GameState(){ ++(*SuperTestValue); Winner = nullptr; SuperTestValue = nullptr; }
    /**
    * @fn void SetWinner(const Player*)
    * @brief Sets the winner of the game or round of the game
    * @param An const pointer to the Player who won the game
    */
    void            SetWinner(const GamePlayer* player){ this->Winner = player; }
    /**
    * @fn const Player* GetWinner()
     * @brief Gets the winner of the game or round of the game
     * @return A const pointer to the Player who won the game
    */
    const GamePlayer*GetWinner(){ return this->Winner; }
    /**
    * @fn void SetScore(int)
    * @brief Sets the Winning Score or current high score
    * @param An int of the score
    */
    void            SetScore(int score) { this->Score = score; }
    /**
    * @fn int GetID()
     * @brief Gets the Winning Score or current high score
     * @return An int of the score
    */
    int             GetScore() { return this->Score; }
  };
}
#endif // GAMESTATE_H
