#include "pch.h"

std::string ExtractName(std::string path){
  std::stringstream ss(path), name;
  std::string element;
  while(std::getline(ss, element, '\\')){
    name.clear();
    char current;
    ss >> current;
    if(current == '.'){
      return name.str();
    } else{
      name << current;
    }
  }
  return name.str();
}

TicTacToeAssetManager::TicTacToeAssetManager(const char* path):GameAssetManager(path){
  if(!Init()) throw GameFramework::GameFrameworkException("TicTacToeAssetManager failed to initialize!");
  /* Read in assets */
  int filesRead = -1;
  try{
    filesRead = this->ReadInAssetManifest();
  } catch(GameFramework::GameFrameworkException gfe){
    std::cerr << "Error! Cannot read in asset file manifest from '" << path << "'! Exiting...";
    exit(1);
  }
  char buffer[32];
  sprintf_s(buffer, 32, "Number of files read in: %d", filesRead);
  //LOG(_INF, buffer);
  std::cout << buffer << '\n';
}

TicTacToeAssetManager::~TicTacToeAssetManager(){

}

bool TicTacToeAssetManager::Init(){
  try{
    this->TextureFilePaths = new std::vector<std::string>;
    this->SoundFilePaths = new std::vector<std::string>;
    this->MusicFilePaths = new std::vector<std::string>;
    return true;
  } catch(std::exception e){
    char buffer[1024];
    sprintf_s(buffer, 1024, "Error allocating memory for AssetFilePaths vectors: \n%s", e.what());
    LOG(_ERR, buffer);
    return false;
  }
}

int TicTacToeAssetManager::ReadInAssetManifest(){
  std::stringstream ss;
  std::ifstream manifest;
  if(!this->IsAssetManifestPathSet()){
    LOG(_ERR, "Asset path manifest not set when attempting to read in asset paths!");
    return -1;
  }
  ss << "Path parameter is: " << this->GameAssetFileManifest;
  LOG(_INF, ss.str().c_str());
  ss.clear();
  try{
    manifest.open(this->GameAssetFileManifest);
    int filesLocated = 0;
    std::string line, temp, path;
    GameAssetType type = ERROR;
    try{
      while(!manifest.eof()){
        std::getline(manifest, line);
        ss << "Line read: " << line;
        LOG(_INF,ss.str().c_str());
        ss.clear();
        if(IsAssetType(line.c_str())){
          type = GetAssetType(line.c_str());
          if(type == TEXTURE){
            ss << "Reading In 'TEXTURE' Assets.";
            LOG(_INF, ss.str().c_str());
            ss.clear();
          }else if(type == SOUND_FILE){
            ss << "Reading In 'SOUND_FILE' Assets.";
            LOG(_INF, ss.str().c_str());
            ss.clear();
          }else if(type == MUSIC_FILE){
            ss << "Reading In 'MUSIC_FILE' Assets.";
            LOG(_INF, ss.str().c_str());
            ss.clear();
          }else{
            ss << "Reached Error Branch in GameAssetType switch case.";
            LOG(_ERR, ss.str().c_str());
            ss.clear();
          }
          continue;
        }else{
          switch(type){
            case TEXTURE:
              this->TextureFilePaths->push_back(line);
              break;
            case SOUND_FILE:
              this->SoundFilePaths->push_back(line);
              break;
            case MUSIC_FILE:
              this->MusicFilePaths->push_back(line);
              break;
            default:
              std::cout << "Reached unreachable branch in ReadInAssetManager, Line 52\n";
          }
        }
      }
      return this->TextureFilePaths->size() + this->MusicFilePaths->size() + this->SoundFilePaths->size();
    } catch(std::exception ex){
      char buffer[1024];
      sprintf_s(buffer, 1024, "Error reading manifest file:\n%s", ex.what());
      manifest.close();
      throw GameFramework::GameFrameworkException(buffer);
    }
    manifest.close();
  } catch(std::exception e){
    char buffer[1024];
    sprintf_s(buffer, 1024, "Failed to open manifest file:\n%s", e.what());
    manifest.close();
    throw GameFramework::GameFrameworkException(buffer);
  }
  return -1;
}

bool TicTacToeAssetManager::LoadAssets(){
  /* Flag to track that all asset files load properly */
  bool flag = true;
  
  /* Load Textures */
  for(unsigned int i = 0; i < TextureFilePaths->size(); i++){
    std::string path = TextureFilePaths->at(i);
    std::string name = ExtractName(path);
    sf::Texture tex;
  
    try{
      tex.loadFromFile(path);
      Textures.emplace_back(TextureAssetRecord(name.c_str(), tex));
    } catch(std::exception e){
      char buffer[1024];
      sprintf_s(buffer, 1024, "Failed to load texture from path %s:\n%s", path.c_str(), e.what());
      throw GameFramework::GameFrameworkException(buffer);
    }
  }
  
  /* Verify that all textures were loaded from file */
  if(Textures.size() != this->TextureFilePaths->size()){
    flag = false;
  }

  /* Create Sprites */
  for(unsigned int i = 0; i < TextureFilePaths->size(); i++){
    std::string path = TextureFilePaths->at(i);
    std::string name = ExtractName(path);
    sf::Sprite sprite;
    try{
      sprite.setTexture(Textures.at(i).GetTextureAsset());
      Sprites.emplace_back(SpriteAssetRecord(name.c_str(), sprite));
    } catch(std::exception e){
      char buffer[1024];
      sprintf_s(buffer, 1024, "Failed to load soundbuffer from path %s:\n%s", path.c_str(), e.what());
      throw GameFramework::GameFrameworkException(buffer);
    }
  }

  /* Verify that all sprites were created from textures */
  if(this->Sprites.size() != this->Textures.size()){
    flag = false;
  }

  for(unsigned int i = 0; i < SoundFilePaths->size(); i++){
    std::string path = SoundFilePaths->at(i);
    std::string name = ExtractName(path);
    sf::SoundBuffer sb;
    try{
      sb.loadFromFile(path);
      SoundBuffers.emplace_back(SoundBufferAssetRecord(name.c_str(), sb));
    } catch(std::exception e){
      char buffer[1024];
      sprintf_s(buffer, 1024, "Failed to load soundbuffer from path %s:\n%s", path.c_str(), e.what());
      throw GameFramework::GameFrameworkException(buffer);
    }
  }

  /* Verify that all sounds were loaded from files */
  if(this->Sprites.size() != this->Textures.size()){
    flag = false;
  }

  for(unsigned int i = 0; i < SoundFilePaths->size(); i++){
    std::string path = SoundFilePaths->at(i);
    std::string name = ExtractName(path);
    sf::Sound sound;
    try{
      sound.setBuffer(SoundBuffers.at(i).GetSoundBufferAsset());
      SoundFiles.emplace_back(SoundAssetRecord(name.c_str(), sound));
    } catch(std::exception e){
      char buffer[1024];
      sprintf_s(buffer, 1024, "Failed to load soundbuffer from path %s:\n%s", path.c_str(), e.what());
      throw GameFramework::GameFrameworkException(buffer);
    }
  }

  /* Verify that all sounds were created from sound buffers */
  if(this->Sprites.size() != this->Textures.size()){
    flag = false;
  }

  /* 
  * Music cannot be preloaded and stored in memory since sf::Music objects stream music 
  *   from the file. sf::Music objects need to be created and managed in the GameLoop from
  *   the references in MusicAssetPaths.
  */

  return flag;
}

bool TicTacToeAssetManager::EraseAsset(GameAssetType type, unsigned int index){
  // TODO Implement loops to delete asset records
  return false;
}

unsigned int TicTacToeAssetManager::GetNumberOfAssets(GameAssetType type){
  switch(type){
    case TEXTURE:      return this->Textures.size();
    case SPRITE:       return this->Sprites.size();
    case SOUND_BUFFER: return this->SoundBuffers.size();
    case SOUND_FILE:   return this->SoundFiles.size();
    default:           return 0;
  }
}

