#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H
#pragma once

#include "../Headers/game-framework-exception.h"
#include "../pch.h"
#include "../../SFML/include/SFML/Audio.hpp"
#include "../../SFML/include/SFML/Graphics.hpp"
#include <map>

namespace GameFramework{
  class GameAssetManager{

  public:
    enum AssetType{ TEXTURE, SPRITE, SOUND_BUFFER, SOUND_FILE, MUSIC_FILE };

  private:
    class TextureAssetManager{
    protected:
      int Position;
      void Init(){ Position = -1; }
      std::map<int, sf::Texture*> TextureMap;
    public:
      TextureAssetManager(){ Init(); }
      ~TextureAssetManager(){ int i = -1; while(this->TextureMap.size() > 0){ this->TextureMap.erase(++i); } }

      int  LoadAsset(const char* name){ 
        sf::Texture* tex = new sf::Texture(); 
        tex->loadFromFile(name); 
        this->TextureMap.insert(std::pair<int, sf::Texture*>(++Position, tex));
        return this->GetNumberOfTextures();

      }
      bool ReleaseAsset(unsigned int index){ this->TextureMap.erase(index); }

      size_t GetNumberOfTextures(){ return this->TextureMap.size(); }
      sf::Texture* GetTexture(unsigned int index){ if(this->TextureMap.size() < (unsigned int)index || index < 0) return nullptr; else return this->TextureMap.at(index); }
    };

    class SpriteAssetManager{
    protected:
      std::map<int, sf::Sprite*> SpriteMap;
      int Position;
      void Init(){ Position = -1; }
    public:
      SpriteAssetManager(){ Init(); }
      ~SpriteAssetManager(){ int i = -1; while(this->SpriteMap.size() > 0){ this->SpriteMap.erase(++i); } }

      int  LoadAsset(sf::Texture* tex){ 
        sf::Sprite* sprite = new sf::Sprite(); 
        sprite->setTexture(*tex); 
        this->SpriteMap.insert(std::pair<int, sf::Sprite*>(++Position, sprite));
        return this->GetNumberOfSprites();
      }
      bool ReleaseAsset(unsigned int index){ this->SpriteMap.erase(index); }

      size_t GetNumberOfSprites(){ return this->SpriteMap.size(); }
      sf::Sprite* GetSprite(unsigned int index){ if(this->SpriteMap.size() < (unsigned int)index || index < 0) return nullptr; else return this->SpriteMap.at(index); }
    };

    class SoundBufferAssetManager{
    protected:
      std::map<int, sf::SoundBuffer*> SoundBufferMap;
      int Position;
      void Init(){ Position = -1; }
    public:
      SoundBufferAssetManager(){ Init(); }
      ~SoundBufferAssetManager(){ int i = -1; while(this->SoundBufferMap.size() > 0){ this->SoundBufferMap.erase(++i); } }

      int  LoadAsset(const char* name){ 
        sf::SoundBuffer* soundBuf = new sf::SoundBuffer(); 
        soundBuf->loadFromFile(name); 
        this->SoundBufferMap.insert(std::pair<int, sf::SoundBuffer*>(++Position, soundBuf));
        return this->GetNumberOfSoundBuffers();
      }
      bool ReleaseAsset(unsigned int index){ this->SoundBufferMap.erase(index); }

      size_t GetNumberOfSoundBuffers(){ return this->SoundBufferMap.size(); }
      sf::SoundBuffer* GetSoundBuffer(unsigned int index){ if(this->SoundBufferMap.size() < (unsigned int)index || index < 0) return nullptr; else return this->SoundBufferMap.at(index); }
    };

    class SoundAssetManager{
    protected:
      std::map<int, sf::Sound*> SoundMap;
      int Position;
      void Init(){ Position = -1; }
    public:
      SoundAssetManager(){ Init(); }
      ~SoundAssetManager(){ int i = -1; while(this->SoundMap.size() > 0){ this->SoundMap.erase(++i); } }

      int  LoadAsset(sf::SoundBuffer* soundBuf){ 
        sf::Sound* sound = new sf::Sound();
        sound->setBuffer(*soundBuf); 
        this->SoundMap.insert(std::pair<int, sf::Sound*>(++Position, sound)); 
        return this->GetNumberOfSounds();
      }
      bool ReleaseAsset(unsigned int index){ this->SoundMap.erase(index); }

      size_t GetNumberOfSounds(){ return this->SoundMap.size(); }
      sf::Sound* GetSound(unsigned int index){ if(this->SoundMap.size() < (unsigned int)index || index < 0) return nullptr; else return this->SoundMap.at(index); }
    };

    class MusicAssetManager{
    protected:
      std::map<int, sf::Music*> MusicMap;
      int Position;
      void Init(){ Position = -1; }
    public:
      MusicAssetManager(){ Init(); }
      ~MusicAssetManager(){ int i = -1; while(this->MusicMap.size() > 0){ this->MusicMap.erase(++i); } }

      int  LoadAsset(const char* name){ 
        sf::Music* song = new sf::Music(); 
        song->openFromFile(name); 
        this->MusicMap.insert(std::pair<int, sf::Music*>(++Position, song));
        return this->GetNumberOfSongs();
      }
      bool ReleaseAsset(unsigned int index){ this->MusicMap.erase(index); }

      size_t GetNumberOfSongs(){ return this->MusicMap.size(); }
      sf::Music* GetSong(unsigned int index){ if(this->MusicMap.size() < (unsigned int)index || index < 0) return nullptr; else return this->MusicMap.at(index); }
    };

  protected:
    TextureAssetManager     TextureMap;
    SpriteAssetManager      SpriteMap;
    SoundBufferAssetManager SoundBufferMap;
    SoundAssetManager       SoundMap;
    MusicAssetManager       MusicMap;

  public:
    //  Here, create the methods that manage the different Assettypes via setters, getters, and intermediary funtions.

    GameAssetManager(){}

    virtual ~GameAssetManager(){}

    /**
    * @fn AddAsset()
    * @brief Adds a Asset to the GameAssetManager
    * @param type The AssetType to be added
    * @param path A string of the path to the file to be loaded
    * @return Number of assets in the given asset map.
    */
    int AddAsset(AssetType type, std::string path){
      switch(type){
        case TEXTURE:
        case SPRITE:
          this->TextureMap.LoadAsset(path.c_str());
          return this->SpriteMap.LoadAsset(this->GetTexture(this->GetNumberOfAssets(TEXTURE)-1));
        case SOUND_FILE:
        case SOUND_BUFFER:
          this->SoundBufferMap.LoadAsset(path.c_str());
          return this->SoundMap.LoadAsset(this->GetSoundBuffer(this->GetNumberOfAssets(SOUND_BUFFER)-1));
        case MUSIC_FILE:   
          return this->MusicMap.LoadAsset(path.c_str());
      }
      return -1;
    }
    /**
    * @fn GetTexture()
    * @brief Gets a sf::Texture from the texture map
    * @param index The index of the texture to retrieve
    * @return A const pointer to the sf::Texture asset; if index is invalid, returns nullptr.
    */
    sf::Texture* GetTexture(unsigned int index){
      if(index < 0){ return nullptr; } // OOB-Gaurd
      if(index < this->TextureMap.GetNumberOfTextures()){// OOB-Guard
        return this->TextureMap.GetTexture(index);
      } else{
        return nullptr;
      }
    }
    /**
    * @fn GetSprite()
    * @brief Gets a sf::Sprite from the sprite map
    * @param index The index of the sprite to retrieve
    * @return A const pointer to the sf::Sprite asset; if index is invalid, returns nullptr.
    */
    sf::Sprite* GetSprite(unsigned int index){
      if(index < 0){ return nullptr; } // Protects against invalid index
      if(index < this->SpriteMap.GetNumberOfSprites()){// OOB-Guard
        return this->SpriteMap.GetSprite(index);
      } else{
        return nullptr;
      }
    }
    /**
    * @fn GetSoundBuffer()
    * @brief Gets a sf::SoundBuffer from the sound buffer map
    * @param index The index of the sound buffer to retrieve
    * @return A const pointer to the sf::SoundBuffer asset; if index is invalid, returns nullptr.
    */
    sf::SoundBuffer* GetSoundBuffer(unsigned int index){
      if(index < 0){ return nullptr; } // Protects against invalid index
      if(index < this->SoundBufferMap.GetNumberOfSoundBuffers()){// OOB-Guard
        return this->SoundBufferMap.GetSoundBuffer(index);
      } else{
        return nullptr;
      }
    }
    /**
    * @fn GetSound()
    * @brief Gets a sf::Texture from the sound map
    * @param index The index of the texture to retrieve
    * @return A const pointer to the sf::Sound asset; if index is invalid, returns nullptr.
    */
    sf::Sound* GetSound(unsigned int index){
      if(index < 0){ return nullptr; } // Protects against invalid index
      if(index < this->SoundMap.GetNumberOfSounds()){// OOB-Guard
        return this->SoundMap.GetSound(index);
      } else{
        return nullptr;
      }
    }
    /**
    * @fn GetSong()
    * @brief Gets a sf::Music from the music map
    * @param index The index of the song to retrieve
    * @return A pointer to the sf::Music asset; If index is invalid, returns nullptr.
    */
    sf::Music* GetSong(unsigned int index){
      if(index < 0){ return nullptr; } // Protects against invalid index
      if(index < this->MusicMap.GetNumberOfSongs()){// OOB-Guard
        return this->MusicMap.GetSong(index);
      } else{
        return nullptr;
      }
    }

    /**
    * @fn EraseFile()
    * @brief Removes an asset from the asset map
    * @param type The AssetType you want to delete
    * @param index The index of the asset in the map
    * @return If index is valid, returns the size of the asset map after removing the asset.
    * @throws GameFrameworkException If index is greater than or equal to the size of the asset map
    */
    unsigned int EraseAsset(AssetType type, unsigned int index){
      switch(type){
        case TEXTURE:
          if(index < this->TextureMap.GetNumberOfTextures()){ // Protects against invalid index
            this->TextureMap.ReleaseAsset(index);
            return this->TextureMap.GetNumberOfTextures();
          } 
        case SPRITE:
          if(index < this->SpriteMap.GetNumberOfSprites()){ // Protects against invalid index
            this->SpriteMap.ReleaseAsset(index);
            return this->SpriteMap.GetNumberOfSprites();
          } 
        case SOUND_BUFFER:
          if(index < this->SoundBufferMap.GetNumberOfSoundBuffers()){ // Protects against invalid index
            this->SoundBufferMap.ReleaseAsset(index);
            return this->SoundBufferMap.GetNumberOfSoundBuffers();
          } 
        case SOUND_FILE:
          if(index < this->SoundMap.GetNumberOfSounds()){ // Protects against invalid index
            this->SoundMap.ReleaseAsset(index);
            return this->SoundMap.GetNumberOfSounds();
          } 
        case MUSIC_FILE:
          if(index < this->MusicMap.GetNumberOfSongs()){ // Protects against invalid index
            this->MusicMap.ReleaseAsset(index);
            return this->MusicMap.GetNumberOfSongs();
          } 
      }
      throw GameFrameworkException("Attempting to erase an asset at an index greater than the size of the asset map!");
    }

    /**
    * @fn GetNumberOfAssets(AssetType)
    * @brief  Returns the size of the asset map for the given type
    * @param  The AssetType for the map you want to check
    * @return an unsigned int of the size of an asset map
    */
    unsigned int GetNumberOfAssets(AssetType type){
      switch(type){
        case TEXTURE:      return this->TextureMap.GetNumberOfTextures();
        case SPRITE:       return this->SpriteMap.GetNumberOfSprites();
        case SOUND_BUFFER: return this->SoundBufferMap.GetNumberOfSoundBuffers();
        case SOUND_FILE:   return this->SoundMap.GetNumberOfSounds();
        case MUSIC_FILE:   return this->MusicMap.GetNumberOfSongs();
        default:           return 0;
      }
    }
  };

}
#endif // GAMEASSETMANAGER_H