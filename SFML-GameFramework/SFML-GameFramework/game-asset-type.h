#pragma once

enum AssetType {TEXTURE, SPRITE, SOUND_FILE, MUSIC_FILE, SOUND_BUFFER, ERROR };

static bool IsAssetType(const char* type){
  if(type == "TEXTURE" || type == "SPRITE" || type == "SOUND_FILE" || type == "MUSIC_FILE" || type == "SOUND_BUFFER") return true;
  else return false;
}

static AssetType GetAssetType(const char* type){
  if(type == "TEXTURE"){
    return TEXTURE;
  } else if(type == "SPRITE"){
    return SPRITE;
  } else if(type == "SOUND_FILE"){
    return SOUND_FILE;
  } else if(type == "MUSIC_FILE"){
    return MUSIC_FILE;
  } else if(type == "SOUND_BUFFER"){
    return SOUND_BUFFER;
  } else{
    return ERROR;
  }
}