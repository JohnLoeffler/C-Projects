#ifndef PCH_H
#define PCH_H

#include "Headers/player.hpp"
#include "Headers/game-board.hpp"
#include "Headers/game-piece.hpp"
#include "Headers/game-state.hpp"
#include "Headers/game-controller.hpp"
#include "Headers/game-framework-exception.hpp"
#include "../../14.16.27023/include/limits.h"

namespace GameFrame {
  using namespace std;
  class Player;
  class Players;
  class GamePiece;
  class GamePieces;
  class GameBoard;
  class GameState;
  class GameController;
}

#endif //PCH_H
