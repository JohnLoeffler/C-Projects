#ifndef PCH_H
#define PCH_H

/* Class Header includes */
#include "player.h"
#include "game-piece.h"
#include "game-framework.h"
#include "game-framework-exception.h"
#include "game-board.h"
#include "game-controller.h"
#include "game-state.h"
#include "game-rule-set.h"

/* Other Common Includes */
#include "../../include/limits.h"

/* Class Declarations */
namespace GameFrame{
  class Player;
  class GamePiece;
  class GameState;
  class GameBoard;
  class GameController;
  class GameRuleSet;
  
  /*  Wrapper classes to make managing pieces and players easier  */
  template <class GamePiece>
  class GamePieces;
  template <class Player>
  class Players;
}
#endif //PCH_H
