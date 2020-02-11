#include "pch.h"
#include "tic-tac-toe-asset-manager.h"

TicTacToeAssetManager::TicTacToeAssetManager(){

}

TicTacToeAssetManager::TicTacToeAssetManager(const char * path){
  std::cout << path << std::endl << std::endl;
  char fileManifest[_MAX_PATH];
  strcpy_s(fileManifest, path);
  strcpy_s(fileManifest, "FileManifest.csv");
  unsigned filesLoaded = 0, count = 0;
  try{
    char msg[128];
    sprintf_s(msg, "fileManifest == %s", fileManifest);
    std::cout << msg << std::endl;
  LOG(_INF, msg);
    std::ifstream manifest(fileManifest);
    std::vector<std::string> textures, sounds, music;
    std::string line = "";
    while(std::getline(manifest,line, ',')){
      std::string filePath = path +  line;
      if(line.find("TEX") != std::string::npos){
        this->AddAsset(TEXTURE, filePath);
        filesLoaded++;
      } else if(line.find("SND") != std::string::npos){
        this->AddAsset(SOUND_FILE, filePath);
        filesLoaded++;
      } else if(line.find("MSC") != std::string::npos){
        this->AddAsset(MUSIC_FILE, filePath);
        filesLoaded++;
      }
      count++;
    }
    char msgg[128];
    sprintf_s(msgg, "Successfully loaded file manifest: %d files loaded on %d attempts", filesLoaded, count);
    LOG(_INF, msgg);
    std::cout << "Successfully loaded file manifest: " << filesLoaded << " files loaded on " << count << " attempts" << std::endl;
  } catch(std::exception ex){
    char msgerr[128];
    sprintf_s(msgerr, "Error opening asset file manifest: %d files loaded on %d attempts", filesLoaded, count);
    LOG(_ERR, msgerr);
    std::cerr << msgerr << std::endl;
    throw ex;
  }
}

TicTacToeAssetManager::~TicTacToeAssetManager(){

}
