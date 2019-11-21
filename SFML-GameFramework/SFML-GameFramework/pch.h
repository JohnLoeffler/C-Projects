#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <queue>

/* Logger For Framework */
#include "Headers/logger.h"

/* Header Files For The Game Framework */

#include "Headers/game-state.h"
#include "Headers/game-loop-state.h"
#include "Headers/game-player.h"
#include "Headers/game-players.h"
#include "Headers/game-piece.h"
#include "Headers/game-pieces.h"
#include "Headers/game-action.h"
#include "Headers/game-board.h"
#include "Headers/game-controller.h"
#include "Headers/game-framework.h"
#include "Headers/game-framework-exception.h"
#include "Headers/game-rule.h"
#include "Headers/game-rule-set.h"
#include "Headers/game-file.h"
#include "Headers/game-file-manager.h"
#include "Headers/game-framework-functions.h"

//namespace GFW = GameFramework;
using namespace Statics;

#endif //PCH_H
