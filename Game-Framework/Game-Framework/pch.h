#ifndef PCH_HPP
#define PCH_HPP

#pragma once

/* Common Includes */
#include <vector>
#include <exception>
#include <stdio.h>
#include <typeinfo>

/* Class Header includes */
#include "../Headers/game-player.h"
#include "../Headers/game-players.h"
#include "../Headers/game-action.h"
#include "../Headers/game-piece.h"
#include "../Headers/game-pieces.h"
#include "../Headers/game-framework.h"
#include "../Headers/game-framework-exception.h"
#include "../Headers/game-board.h"
#include "../Headers/game-controller.h"
#include "../Headers/game-state.h"
#include "../Headers/game-loop-state.h"
#include "../Headers/game-rule.h"
#include "../Headers/game-rule-set.h"

#include "../../../Logger/Logger/Logger.h"

using namespace GameFramework;
namespace GFWK = GameFramework;

class GamePlayer;
class GamePlayers;
class GamePiece;
class GamePieces;
class GameFrameworkException;
class GameAction;
class GameBoard;
class GameController;
class GameState;
class GameRules;
class GameRuleSet;

#endif //PCH_HPP
