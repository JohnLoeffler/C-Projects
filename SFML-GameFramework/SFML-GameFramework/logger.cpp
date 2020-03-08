#include "pch.h"

using namespace Statics;

Logger::Logger(){
  OPENINFO_F;
  OPENERROR_F;
  OPENWARNING_F;
  OPENCRITICAL_F;
  OPENDEBUG_F;
}

Logger::~Logger(){}

/* Need to find better way to lock logs during insertion operations */
void Logger::Write(LogLevel Level, const char *fname, int lineno, const char *fxname, const char* Message){
  std::lock_guard<std::mutex> LogGuard(LogMutex);
  if(Message == ""){
    return;
  }
  std::stringstream SS, msg;

  msg << fname << "(" << lineno << "): IN->" << fxname << "| " << Message;

  switch(Level){
    case _INFO_:
      SS << "[ INFO ] : " << msg.str();
      Info.push_back(SS.str());
      break;
    case _ERROR_:
      SS << "[ ERROR ] : " << msg.str();
      Error.push_back(SS.str());
      break;
    case _WARNING_:
      SS << "[ WARNING ] : " << msg.str();
      Warning.push_back(SS.str());
      break;
    case _DEBUG_:
      SS << "[ DEBUG ] : " << msg.str();
      Debug.push_back(SS.str());
      break;
    case _CRITICAL_:
      SS << "[ CRITICAL ] : " << msg.str();
      std::cerr << SS.str() << std::endl;
      Critical.push_back(SS.str());
      break;
    default:
      break;
  }
}

int Logger::OutputLogs() {
  std::stringstream SS;
  if(!Info.empty()){
    for(auto itr = Info.begin(); itr != Info.end(); ++itr){
      SS << *itr << std::endl;
    }
    InfoLog << SS.str();
    SS.clear();
    CLOSEINFO_F;
  }
  if(!Error.empty()){
    for(auto itr = Error.begin(); itr != Error.end(); ++itr){
      SS << *itr << std::endl;
    }
    ErrorLog << SS.str();
    SS.clear();
    CLOSEERROR_F;
  }
  if(!Warning.empty()){
    for(auto itr = Warning.begin(); itr != Warning.end(); ++itr){
      SS << *itr << std::endl;
    }
    WarningLog << SS.str();
    SS.clear();
    CLOSEWARNING_F;
  }
  if(!Critical.empty()){
    for(auto itr = Critical.begin(); itr != Critical.end(); ++itr){
      SS << *itr << std::endl;
    }
    CriticalLog << SS.str();
    SS.clear();
    CLOSECRITICAL_F;
  }
  if(!Debug.empty()){
    for(auto itr = Debug.begin(); itr != Debug.end(); ++itr){
      SS << *itr << std::endl;
      std::cout << *itr << std::endl;
    }
    DebugLog << SS.str();
    SS.clear();
    CLOSEDEBUG_F;
  }
  return 1;
}