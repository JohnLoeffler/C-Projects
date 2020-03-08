#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H
#pragma once
#include "../Headers/game-asset-type.h"


namespace GameFramework{
  class GameAssetManager{
  private:
  public:
    
    GameAssetManager(){}

    virtual ~GameAssetManager(){}
  
    /**
    * \fn ReadInAssetManifest()
    * \brief Reads in the file locations for all the game assets to be used
    * \param path A string of the path to the file containing the locations of the necessary assets
    * \return int Returns the number of files located, -1 if the manifest file cannot be found
    */
    virtual int ReadInAssetManifest(const char* path){return -1;}

    /**
    * \fn AddAsset()
    * \brief Adds a Asset to the GameAssetManager
    * \param path A string of the path to the file to be loaded
    * \return True if asset was successfully added, false otherwise
    */
    virtual bool AddAsset(GameAssetType type, std::string name, std::string path){return false;}
    
    /**
    * \fn EraseFile()
    * \brief Removes an asset from the asset map
    * \param index The index of the asset in the map
    * \return True if the asset was erased, false otherwise.
    * \throws GameFrameworkException If index is greater than or equal to the size of the asset map
    */
    virtual bool EraseAsset(GameAssetType type, std::string name){ return false; }

    /**
    * \fn GetNumberOfAssets(AssetType)
    * \brief  Returns the size of the asset map for the given type
    * \param  The AssetType for the map you want to check
    * \return An unsigned int of the size of an asset map
    */
    virtual unsigned int GetNumberOfAssets(GameAssetType type){return 0;}
  };

}
#endif // GAMEASSETMANAGER_H