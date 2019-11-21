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
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../pch.h"
#include "../../SFML/include/SFML/System.hpp"
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
  public:
    /** 
    * @fn GameState() 
    * @brief Default Constructor 
    */
    GameState();
    /** 
    * @fn ~GameState() 
    * @brief Destructor 
    */
    virtual          ~GameState() = 0;

    virtual void     HandleEvents() = 0;
    virtual void     HandleLogic() = 0;
    virtual void     HandleRendering() = 0;
  };
}
#endif // GAMESTATE_HPP
