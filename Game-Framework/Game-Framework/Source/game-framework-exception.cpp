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
* @file ${File}
*
* @brief Implementation of GameFrameworkException
*
* @ingroup ${ProjectName}
*
* @author John Loeffler
* <ul>contact:
*   <li>John.Loeffler@gmail.com</li>
*   <li>JohnLoeffler.com</li>
*   <li>Github.com/JohnLoeffler</li>
*   <li>LinkedIn.com/in/JohnLoeffler</li>
* </ul>
*/
#include "../pch.h"
#include "game-framework-exception.h"
#include <cstdio>

GameFrameworkException::GameFrameworkException(){
  Message = nullptr;
  File = nullptr;
  Formatted = nullptr;
  LineNumber = INT_MIN;
}


GameFrameworkException::GameFrameworkException(const char* message) {
  Message = message;
  File = nullptr;
  LineNumber = INT_MIN;
  Formatted = new char[2048];
  sprintf_s(Formatted, 2048, "GameFrameworkException Thrown: %s", message);
}



GameFrameworkException::GameFrameworkException(const char* message, const char* file, int lineNumber) {
  Message = message;
  File = file;
  LineNumber = lineNumber;
  Formatted = new char[2048];
  sprintf_s(Formatted, 2048, "GameFrameworkException Thrown: |%s|[%d]: %s", File, LineNumber, Message);

}

GameFrameworkException::~GameFrameworkException(){
  if (Message != nullptr)  {delete[] Message;}
  if (File != nullptr)     {delete[] File;}
  if (Formatted != nullptr){delete[] Formatted;}
}

const char* GameFrameworkException::what(){
  return Formatted;
}
