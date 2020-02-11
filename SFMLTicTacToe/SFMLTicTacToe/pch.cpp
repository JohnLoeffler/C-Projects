// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"
#include <algorithm>

/* Relevant Global Variables */
std::string CWD = fs::current_path().generic_string();
std::string ASSET_PATH = CWD + "\\assets\\";

std::replace(CWD.begin(), CWD.end(), '/'.'\\');
// In general, ignore this file, but keep it around if you are using pre-compiled headers.
