#ifndef PCH_H
#define PCH_H

/* Common Headers */
#include <filesystem>
#include <string>

/* SFML Game Headers */
#include "../../SFML/include/SFML/Graphics.hpp"
#include "../../SFML/include/SFML/Audio.hpp"

/* GameFramework Header */
#include "../Headers/GameFramework.hpp"

/* Tic Tac Toe Headers */
#include "Headers\tic-tac-toe-asset-manager.h"
#include "Headers\tic-tac-toe-game.h"

/* Diagnostic Headers */
#include "../Logger/Logger.h"

/* Namespace Declarations */
namespace fs = std::filesystem;


#endif //PCH_H
