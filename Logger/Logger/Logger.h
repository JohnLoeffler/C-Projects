#ifndef LOGGER_H
#define LOGGER_H
#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <mutex>    
#include <vector>   

#define _INF Statics::Logger::GetLogger()->_INFO_
#define _ERR Statics::Logger::GetLogger()->_ERROR_
#define _WARN Statics::Logger::GetLogger()->_WARNING_
#define _CRIT Statics::Logger::GetLogger()->_CRITICAL_
#define _DBUG Statics::Logger::GetLogger()->_DEBUG_

#define ERROR_F "ErrorLog.txt"
#define INFO_F "InfoLog.txt"
#define WARNING_F "WarningLog.txt"
#define CRITICAL_F "CriticalLog.txt"
#define DEBUG_F "DebugLog.txt"

#define OPENINFO_F InfoLog.open(INFO_F, std::ofstream::out | std::ofstream::app);
#define OPENERROR_F ErrorLog.open(ERROR_F, std::ofstream::out | std::ofstream::app);
#define OPENWARNING_F WarningLog.open(WARNING_F, std::ofstream::out | std::ofstream::app);
#define OPENCRITICAL_F CriticalLog.open(CRITICAL_F, std::ofstream::out | std::ofstream::app);
#define OPENDEBUG_F DebugLog.open(DEBUG_F, std::ofstream::out | std::ofstream::app);

#define CLOSEINFO_F InfoLog.close();
#define CLOSEERROR_F InfoLog.close();
#define CLOSEWARNING_F InfoLog.close();
#define CLOSECRITICAL_F InfoLog.close();
#define CLOSEDEBUG_F InfoLog.close();

#define LOG(_Level_, _Message_) Statics::Logger::GetLogger()->Write(_Level_, __FILE__, __LINE__, __FUNCTION__, _Message_)


namespace Statics{
  class Logger{

  public:
    enum LogLevel { _INFO_, _ERROR_, _WARNING_, _CRITICAL_, _DEBUG_ } Level = _INFO_;
  
    /*  Delete Copy Constructor and Assignment Operator to ensure there is only ever one Logger active */
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;

  private:
    Logger(){
      OPENINFO_F;
      OPENERROR_F;
      OPENWARNING_F;
      OPENCRITICAL_F;
      OPENDEBUG_F;
    }
    virtual ~Logger(){
      if(OutputLogs() != 1){
        std::cerr << "Logger Failed To Output!\n";
      }
    }
    std::ofstream InfoLog, ErrorLog, WarningLog, CriticalLog, DebugLog;
    std::mutex WriteInfoMutex, WriteErrorMutex, WriteWarnMutex, WriteCritMutex, WriteDebugMutex;
  protected:
    std::vector<std::string> Info, Error, Warning, Critical, Debug;
  public:
    static Logger* GetLogger(LogLevel Level = _INFO_) {
      static Logger* Instance = new Logger();
      Instance->Level = Level;
      return Instance;
    }

    void Write(LogLevel Level, const char *fname, int lineno, const char *fxname, const char* Message){
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

    int OutputLogs(){
      std::stringstream SS;
      if(!Info.empty()){
      std::lock_guard<std::mutex> lock(WriteInfoMutex);
        LOG(_DBUG, "Info is not empty...\n");
        for(auto itr = Info.begin(); itr != Info.end(); ++itr){
          SS << *itr << std::endl;
        }
        InfoLog << SS.str();
        SS.clear();
        CLOSEINFO_F;
      }
      if(!Error.empty()){
        std::lock_guard<std::mutex> lock(WriteErrorMutex);
        LOG(_DBUG, "Error is not empty...\n");
        for(auto itr = Error.begin(); itr != Error.end(); ++itr){
          SS << *itr << std::endl;
        }
        ErrorLog << SS.str();
        SS.clear();
        CLOSEERROR_F;
      }
      if(!Warning.empty()){
        std::lock_guard<std::mutex> lock(WriteWarnMutex);
        LOG(_DBUG, "Warning is not empty...\n");
        for(auto itr = Warning.begin(); itr != Warning.end(); ++itr){
          SS << *itr << std::endl;
        }
        WarningLog << SS.str();
        SS.clear();
        CLOSEWARNING_F;
      }
      if(!Critical.empty()){
        std::lock_guard<std::mutex> lock(WriteCritMutex);
        LOG(_DBUG, "Critical is not empty...\n");
        for(auto itr = Critical.begin(); itr != Critical.end(); ++itr){
          std::cerr << *itr << std::endl;
          SS << *itr << std::endl;
        }
        CriticalLog << SS.str();
        SS.clear();
        CLOSECRITICAL_F;
      }
      if(!Debug.empty()){
        std::lock_guard<std::mutex> lock(WriteDebugMutex);
        LOG(_DBUG, "Debug is not empty...\n");
        for(auto itr = Debug.begin(); itr != Debug.end(); ++itr){
          SS << *itr << std::endl;
        }
        DebugLog << SS.str();
        SS.clear();
        CLOSEDEBUG_F;
      }
      return 1;
    }
  };
}


#endif  //  LOGGER_H
