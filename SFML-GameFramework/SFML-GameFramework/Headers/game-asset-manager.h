#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H
#pragma once

namespace GameFramework{
  class GameAssetManager{
  private:
  public:
    
    GameAssetManager();

    virtual ~GameAssetManager();

    /**
    * \fn AddAsset()
    * \brief Adds a Asset to the GameAssetManager
    * \param path A string of the path to the file to be loaded
    * \return true if asset was loaded from the indicated file, false otherwise.
    */
    virtual bool AddAsset(std::string path);
    
    /**
    * \fn EraseFile()
    * \brief Removes an asset from the asset map
    * \param index The index of the asset in the map
    * \return If index is valid, returns true if the asset was erased, false otherwise.
    * \throws GameFrameworkException If index is greater than or equal to the size of the asset map
    */
    virtual bool EraseAsset(unsigned int index);

    /**
    * \fn GetNumberOfAssets(AssetType)
    * \brief  Returns the size of the asset map for the given type
    * \param  The AssetType for the map you want to check
    * \return an unsigned int of the size of an asset map
    */
    virtual unsigned int GetNumberOfAssets();
  };

}
#endif // GAMEASSETMANAGER_H