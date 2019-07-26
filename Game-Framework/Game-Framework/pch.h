#ifndef PCH_H
#define PCH_H

#include "Headers/player.hpp"
#include "Headers/game-piece.hpp"
#include "Headers/game-framework.h"
#include "Headers/game-framework-exception.h"
#include "Headers/game-board.hpp"
#include "Headers/game-controller.h"
#include "Headers/game-state.h"

namespace GameFrame{
  using namespace std;
  class Player;
  class Players;
  class GamePiece;
  class GamePieces;
  class GameState;
  class GameBoard;
  class GameController;
}

#endif //PCH_H
