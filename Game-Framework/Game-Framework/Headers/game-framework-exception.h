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
* @brief A class for GameFramework specific exceptions
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
#ifndef GAMEFRAMEWORKEXCEPTION_HPP
#define GAMEFRAMEWORKEXCEPTION_HPP
#pragma once
#include <exception>

namespace GameFrame{
  class GameFrameworkException :
    public std::exception
  {
    const char* Message;
    const char* File;
    int         LineNumber;

    char* Formatted;
  public:
    GameFrameworkException();
    GameFrameworkException(const char* message);
    GameFrameworkException(const char* message, const char* file = __FILE__, int lineNumber = __LINE__);
    ~GameFrameworkException();
    const char* what();
  };
}
#endif // GAMEFRAMEWORKEXCEPTION_HPP
