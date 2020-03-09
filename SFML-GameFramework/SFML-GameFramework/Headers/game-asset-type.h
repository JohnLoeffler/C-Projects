#pragma once
#include <string>

enum GameAssetType {TEXTURE, SPRITE, SOUND_FILE, MUSIC_FILE, SOUND_BUFFER, ERROR };

static bool IsAssetType(std::string type){
  if(type == "TEXTURE" || type == "SPRITE" || type == "SOUND_FILE" || type == "MUSIC_FILE" || type == "SOUND_BUFFER") return true;
  else return false;
}

static GameAssetType GetAssetType(std::string type){
  if(type.compare("TEXTURE") == 0){
    return TEXTURE;
  } else if(type.compare("SPRITE") == 0){
    return SPRITE;
  } else if(type.compare("SOUND_FILE") == 0){
    return SOUND_FILE;
  } else if(type.compare("MUSIC_FILE") == 0){
    return MUSIC_FILE;
  } else if(type.compare("SOUND_BUFFER") == 0){
    return SOUND_BUFFER;
  } else{
    return ERROR;
  }
}