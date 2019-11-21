#ifndef GAMEFILEMANAGER_H
#define GAMEFILEMANAGER_H
#pragma once

namespace GameFramework{
  template <class T>
  class GameFileManager{
    std::vector<T>   FileVector;
  public:
    GameFileManager()  {}
    ~GameFileManager() {}
    int  LoadFile()    { return 0; }
    bool ReleaseFile() { return false; }
  };
}
#endif // GAMEFILEMANAGER_H