#include "pch.h"
#include <iostream>

namespace fs = std::filesystem;

int main()
{
  TicTacToeGame* game = new TicTacToeGame();
  delete game;
}