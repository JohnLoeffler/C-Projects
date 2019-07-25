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
* @file game-framework-test.cpp
*
* @brief Runs the the Catch2 Unit Test Cases for the GameFramework package
*
* @defgroup UnitTests Testing @ingroup GameFramework
*
* @author John Loeffler
* <ul>contact:
*   <li>John.Loeffler@gmail.com</li>
*   <li>JohnLoeffler.com</li>
*   <li>Github.com/JohnLoeffler</li>
*   <li>LinkedIn.com/in/JohnLoeffler</li>
* </ul>
*/
#include "../Headers/package.hpp"

class PlayerImp : public Player{
public:
  PlayerImp(){}
  PlayerImp(int *val):Player(val){}
  virtual void Action(){(*TestValue) = -10;}
  virtual ~PlayerImp(){(*TestValue)++;}
};

class GamePieceImp : public GamePiece{
public:
  GamePieceImp(){}
  GamePieceImp(int* val):GamePiece(val){}
  virtual int Compare(const GamePiece* rhs){ (*TestValue) = -10; return 1; }
  virtual ~GamePieceImp(){++(*TestValue);}
};

class GameBoardImp : public GameBoard{
public:
  GameBoardImp(){}
  GameBoardImp(int* val){TestValue = val;}
  ~GameBoardImp(){(*TestValue)++;}
  virtual void Setup(){(*TestValue) = -1;}
  virtual void BeginPlay(){(*TestValue) = -2;}
  virtual void Finalize(){(*TestValue) = -3;}
  virtual void ReportGameState(){(*TestValue) = -4;}
};


TEST_CASE("Testing Player class default behavior","[abstract][!throws]")
{
  int* value = new int(0);
  PlayerImp* player = nullptr;
  SECTION("Testing Player basic methods"){
    SECTION("Player"){

    player = new PlayerImp();
    REQUIRE(player != nullptr);
  }
    SECTION("~Player"){
    player = new PlayerImp(value);
    delete player;

    REQUIRE(*value == 2);
    *value = 0;
    }

    SECTION("Get|Set"){
    player = new PlayerImp();
    GamePiece **pieces = new GamePiece*[5];
    for(int i = 0; i < 5; i++){
      GamePieceImp *p = new GamePieceImp();
      pieces[i] = &(*p);
    }
    player->SetGamePieces(pieces);
    player->SetNumberOfGamePieces(5);
    player->SetID(1);

    REQUIRE(player->GetGamePieces() != nullptr);
    REQUIRE(player->GetNumberOfGamePieces() == 5);
    REQUIRE(player->GetID() == 1);
}
    SECTION("Testing Player Implementation of virtual methods"){
      player= new PlayerImp(value);
      player->Action();
      REQUIRE(*value == -10);
      *value = 0;
    }
  }
}
TEST_CASE("Testing GamePiece class default behavior","[abstract][!throws]")
{
  int* value = new int(0);
  GamePieceImp *piece = nullptr;
  SECTION("Testing GamePiece basic methods"){
    SECTION("GamePiece"){
      piece = new GamePieceImp();
      REQUIRE(piece != nullptr);
    }

    SECTION("~GamePiece"){
      piece = new GamePieceImp(value);
      delete piece;
      REQUIRE(*value == 2);
      *value = 0;
    }

    SECTION("Get|Set"){
      piece = new GamePieceImp();
      piece->SetValue(5);
      piece->SetID(1);
      REQUIRE(piece->GetValue() == 5);
      REQUIRE(piece->GetID() == 1);
    }

    SECTION("Testing GamePiece Implementation of virtual methods"){
      piece = new GamePieceImp(value);
      piece->Compare(nullptr);
      REQUIRE(*value == -10);
      *value = 0;
    }
  }
}

TEST_CASE("Testing GameBoard class default behavior","[abstract][!throws]")
{
  int* value = new int(0);
  GameBoardImp *board = nullptr;
  SECTION("Testing GameBoard basic methods"){
    SECTION("GameBoard"){
      board = new GameBoardImp();
      REQUIRE(board != nullptr);
    }

    SECTION("~GameBoard"){
      board = new GameBoardImp(value);
      delete board;
      REQUIRE(*value == 2);
      *value = 0;
    }

    SECTION("Get|Set"){
      board = new GameBoardImp();
      Player** players = new Player*[5];
      for(int i = 0; i < 5; i++){
        PlayerImp *player = new PlayerImp();
        players[i] = &(*player);
      }
      board->SetPlayers(players);
      board->SetNumberOfPlayers(5);

      GamePiece** pieces = new GamePiece*[5];
      for(int i = 0; i < 5; i++){
        GamePieceImp *piece = new GamePieceImp();
        pieces[i] = &(*piece);
      }

      board->SetGamePieces(pieces);
      board->SetNumberOfGamePieces(5);
//      board->SetGameState(nullptr);
//      board->SetGameController(nullptr);

      REQUIRE(board->GetPlayers() != nullptr);
      REQUIRE(board->GetNumberOfPlayers() == 5);
      REQUIRE(board->GetGamePieces() != nullptr);
      REQUIRE(board->GetNumberOfGamePieces() == 5);
//      REQUIRE(board->GetGameState() == nullptr);
//      REQUIRE(board->GetGameController() == nullptr);
    }
  }
/*
  SECTION("Testing GameBoard Implementation of virtual methods::"){
    SECTION("Setup"){

    }

    SECTION("BeginPlay"){

    }

    SECTION("Finalize"){

    }

    SECTION("ReportGameState"){

    }
  }*/

}

//TEST_CASE("Testing inherited virtual function implementations","[derived]"){
//
//}
/*
TEST_CASE(" Testing Exceptions", "[Exceptions]"){

  SECTION("Testing Standard Exceptions","[StandardExceptions]"){

  }

  SECTION("Testing GameFrameworkExceptions","[GameFrameworkExceptions]"){

  }
}
*/
