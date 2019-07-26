/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Any source code included in this package written by myself, John Loeffler, is
* free to use as-is for any purpose, commercial and non-commercial alike, so
* long as the license & header documentation containing my contact info and link
* to the original source file on Github remains intact.
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
* @file game-board.hpp
*
* @brief An abstract class from which different games can be derived.
*
* @ingroup GameFramework
*
* @author John Loeffler
* <ul>contact:
*   <li>John.Loeffler@gmail.com</li>
*   <li>JohnLoeffler.com</li>
*   <li>Github.com/JohnLoeffler</li>
*   <li>LinkedIn.com/in/JohnLoeffler</li>
* </ul>
*/
#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#pragma once
/* Forward declare necessary classes */

class Player;
class GamePiece;
class GameState;
class GameController;

/**
*  An abstract GameBoard class from which individual GameBoards will be derived
*
*  The GameBoard class is the class that will actually be controlling the actual
*   game as its being played. It is responsible for setting up the starting
*   state of the game or round, initiating play, finalizing the conclusion of
*   play, and reporting the results of the game to a controller. Virtual methods
*   that need to be implemented are 'Setup', 'BeginPlay', 'Finalize', and
*   'ReportGameState'
*/
namespace GameFrame{
  class GameBoard{
  protected:
    Player**        Players;
    int             NumPlayers;
    GamePiece**     GamePieces;
    int             NumGamePieces;
    GameState*      CurrentGameState;
    GameController* CurrentGameController;
  public:
    /** @fn GameBoard() @brief Default Constructor */
    GameBoard() noexcept;
  /** @fn ~GameBoard() @brief Destructor */
    virtual         ~GameBoard();

    //////////////////////////////////////////////////////////////
    /////////// Begin Getters and Setters  ///////////////////////
    //////////////////////////////////////////////////////////////
    /**
    * @fn Player** GetPlayers()
    * @brief Gets the Player pointer array from the GameBoard
    * @return The Player pointer array for the players playing on the GameBoard
    */
    Player**        GetPlayers() noexcept { return this->Players; }
    /**
    * @fn int GetNumberOfPlayers()
    * @brief Gets the number of Players currently playing on the GameBoard
    * @return An int of the number of players currently playing on the GameBoard
    */
    int             GetNumberOfPlayers() noexcept { return this->NumPlayers; }
    /**
    * @fn GamePiece** GetGamePieces()
    * @brief Gets the GamePiece pointer array from the GameBoard
    * @return The GamePiece pointer array for the pieces used by the GameBoard
    */
    GamePiece**     GetGamePieces() noexcept { return this->GamePieces; }
    /**
    * @fn int GetNumberOfGamePieces()
    * @brief Gets the number of GamePieces currently in play on the GameBoard
    * @return An int of the number of GamePieces in play on the GameBoard
    */
    int             GetNumberOfGamePieces() noexcept { return this->NumGamePieces; }
    /**
    * @fn GameState* GetGameState()
    * @brief Gets the GameState pointer from the GameBoard with details about the
    *   current state of the game
    * @return A pointer to the current GameState of the GameBoard
    */
    GameState*      GetGameState() noexcept { return this->CurrentGameState; }
    /**
    * @fn GameController* GetGameController()
    * @brief Gets the pointer to the current GameController for the GameBoard
    * @return A pointer to the current GameController for the GameBoard
    */
    GameController* GetGameController() noexcept { return this->CurrentGameController; }

    /**
    * @fn void SetPlayers(Player**)
    * @brief Sets the Player pointer array from the GameBoard
    * @param The Player pointer array for the players playing on the GameBoard
    */
    void            SetPlayers(Player** players){ this->Players = players; }
    /**
    * @fn void SetNumberOfPlayers(int)
    * @brief Sets number of Players currently playing on the GameBoard
    * @param An int of the number of Players playing on the GameBoard
    */
    void            SetNumberOfPlayers(int num){ this->NumPlayers = num; }
    /**
    * @fn void SetGamePieces(GamePieces)
    * @brief Sets the GamePiece pointer array from the GameBoard
    * @param The GamePiece pointer array for GamePieces in play on the GameBoard
    */
    void            SetGamePieces(GamePiece** pieces){ this->GamePieces = pieces; }
    /**
    * @fn void SetNumberOfGamePieces(int)
    * @brief Sets the number of GamePieces in play on the board
    * @param An int of the number of GamePieces in play on the board
    */
    void            SetNumberOfGamePieces(int num){ this->NumGamePieces = num; }
    /**
    * @fn void SetGameState(GameState*)
    * @brief Sets the current GameState of the GameBoard (Useful for saved games)
    * @param A pointer to a GameState for the GameBoard
    */
    void            SetGameState(GameState* state){ this->CurrentGameState = state; }
    /**
    * @fn void SetGameController(GameController*)
    * @brief Sets the GameController for the GameBoard
    * @param A pointer to the GameController for the GameBoard
    */
    void            SetGameController(GameController* controller)
    {
      this->CurrentGameController = controller;
    }
  //////////////////////////////////////////////////////////////
  /////////// End Getters and Setters  /////////////////////////
  //////////////////////////////////////////////////////////////

  /* Pure Virtual Methods */
  /**
  * @fn void Setup()
  * @brief GameController calls this to initialize the GameBoard according to
  *   a given GameState or an implementation specific default
  * @exception GFW::GameFrameworkException An exception should be thrown when
  *   GameBoard does not have all the requisite components to build the
  *   GameState (method could setup a default setup if it has no GameState at
  *   time of call).
  */
    virtual void    Setup() = 0;
    /**
    * @fn void BeginPlay()
    * @brief GameController calls this to tell the GameBoard to begin playing the
    *   game. Before this method returns, either the main game loop should be run
    *   or the method that runs the main game loop should be called.
    */
    virtual void    BeginPlay() = 0;
    /**
    * @fn void Finalize()
    * @brief Called by GameBoard after the main game loop ends to record the
    *   outcome of the game or round of the game
    */
    virtual void    Finalize() = 0;
    /**
    * @fn void ReportGameState()
    * @brief Called by GameBoard to notify the GameController about a significant
    *   change in the current GameState;
    */
    virtual void    ReportGameState() = 0;
  protected:
    GameBoard(int* value) noexcept;///<For Unit Tests
    int*            TestValue;///<Used in Unit Tests
  };
}
#endif // GAMEBOARD_HPP
