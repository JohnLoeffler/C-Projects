#ifndef TICTACTOEASSETMANAGER_HPP
#define TICTACTOEASSETMANAGER_HPP
#pragma once
#include "pch.h"

class TicTacToeAssetManager : GameFramework::GameAssetManager{
private:
  /* Helper struct to manage game asset data structures */
  class GameAssetRecord{
  public:
    const char* Name;
  };

  class TextureAssetRecord : public GameAssetRecord{
  private:
    sf::Texture Texture;
  public:
    TextureAssetRecord(const char* name, sf::Texture texture){this->Name = name; this->Texture = texture;}
    const sf::Texture& GetTextureAsset(){return this->Texture;}
  };

  class SpriteAssetRecord : public GameAssetRecord{
  private:
    sf::Sprite Sprite;
  public:
    SpriteAssetRecord(const char* name, sf::Sprite sprite){ this->Name = name; this->Sprite = sprite; }
    const sf::Sprite& GetSpriteAsset(){ return this->Sprite;}
  };

  class SoundBufferAssetRecord : public GameAssetRecord{
  private:
    sf::SoundBuffer SoundBuffer;
  public:
    SoundBufferAssetRecord(const char* name, sf::SoundBuffer sbuffer){ this->Name = name; this->SoundBuffer = sbuffer; }
    const sf::SoundBuffer& GetSoundBufferAsset(){ return this->SoundBuffer;}
  };

  class SoundAssetRecord : public GameAssetRecord{
  private:
    sf::Sound Sound;
  public:
    SoundAssetRecord(const char* name, sf::Sound sound){ this->Name = name; this->Sound = sound; }
    const sf::Sound& GetSoundAsset(){ return this->Sound;}
  };

  std::vector<TextureAssetRecord>     Textures; 
  std::vector<SpriteAssetRecord>      Sprites; 
  std::vector<SoundBufferAssetRecord> SoundBuffers; 
  std::vector<SoundAssetRecord>       SoundFiles; 
  
  std::vector<std::string>     *TextureFilePaths, *SoundFilePaths, *MusicFilePaths;

  bool Init();

public:

  /** \fn Default constructor */
  TicTacToeAssetManager(){}

  /** 
  * \fn Parameterized constructor 
  * \param path The path to the game asset path manifest. This will tell the Asset manager where to look for the required multimedia files needed for the game.
  */
  TicTacToeAssetManager(const char* path);

  /** \fn Destructor */
  virtual ~TicTacToeAssetManager();

  /**
    * \fn ReadInAssetManifest()
    * \brief Reads in the file locations for all the game assets to be used
    * \param path A string of the path to the file containing the locations of the necessary assets
    * \return int Returns the number of files located, -1 if the manifest file cannot be found
    */
  virtual int ReadInAssetManifest();

  /**
  * \fn LoadAssets()
  * \brief Loads assets read in from ReadInAssetManifest() into SFML Objects. DOES NOT LOAD IN MUSIC OBJECTS! THESE MUST BE CREATED AND MANAGED AS NEEDED IN THE GAME LOOP!
  * \return True if assets were successfully loaded, false otherwise
  * \throws Throws GameFrameworkException
  */
  virtual bool LoadAssets();
  
  /**
  * \fn EraseFile()
  * \brief Removes an asset from the asset map
  * \param index The index of the asset in the map
  * \return If index is valid, returns true if the asset was erased, false otherwise.
  * \throws GameFrameworkException If index is greater than or equal to the size of the asset map
  */
  virtual bool EraseAsset(GameAssetType type, unsigned int index);
  
  /**
  * \fn GetNumberOfAssets(AssetType)
  * \brief  Returns the size of the asset map for the given type
  * \param  The AssetType for the map you want to check
  * \return an unsigned int of the size of an asset map
  */
  virtual unsigned int GetNumberOfAssets(GameAssetType type);

  sf::Sprite GetSprite(unsigned int index){if(index < Sprites.size()) return Sprites.at(index).GetSpriteAsset(); else throw GameFramework::GameFrameworkException("");}

  sf::Sound GetSound(unsigned int index){ if(index < SoundFiles.size()) return SoundFiles.at(index).GetSoundAsset(); else throw GameFramework::GameFrameworkException(""); }
};


#endif // TICTACTOEASSETMANAGER_HPP