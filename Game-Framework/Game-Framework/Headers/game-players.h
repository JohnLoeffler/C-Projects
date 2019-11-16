#ifndef GAMEPLAYERS_HPP
#define GAMEPLAYERS_HPP
#pragma once
#include <vector>

namespace GameFramework{
  class GamePlayer;

  /**
  * @brief A wrapper class for a group of GamePlayers to make grouping and managing them easier
  */
  class GamePlayers{
  protected:
    std::vector<GamePlayer*>   VectorOfPlayers; // The vector for the wrapper class that hold pointers to the game's GamePlayers
    int*                       SuperTestWrapperValue;  // A pointer to an int value that was allocated outside the scope of this class.

  public:
    // Constructors And Destructors //
    /**
    * @fn GamePlayers(int*)
    * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
    * @param int* A pointer to an int variable that can be persistently changed by the class destructor
    */
    GamePlayers(int* value)    { this->SuperTestWrapperValue = value; }

    /**
    * @fn GamePlayers()
    * @brief Default constructor for the wrapper class
    */
    GamePlayers()              { this->SuperTestWrapperValue = nullptr; }

    /**
* @fn ~Players()
* @brief Virtual destructor for the wrapper class
*/
    virtual ~GamePlayers()     { if(this->SuperTestWrapperValue != nullptr) ++(*this->SuperTestWrapperValue); }

    /* Setters */
    /**
    * @fn SetGamePlayers(std::vector<GamePlayer*>)
    * @brief Groups a vector of GamePlayers into a single encapsulated object
    * @return A vector of pointers to a group of GamePlayers
    */
    void    SetGamePlayers(std::vector<GamePlayer*> players){ this->VectorOfPlayers = players; }

    /* Getters */
    /**
    * @fn vector<GamePlayer*> GetGamePlayers()
    * @brief Gets the encapsulated vector of the GamePlayers
    * @return A vector of pointers to a group of GamePlayers
    */
    std::vector<GamePlayer*>   GetGamePlayers(){ return this->VectorOfPlayers; }
    /**
    * @fn unsigned GetNumberOfPlayers()
    * @brief Gets the number of Players in the vector
    * @return An unsigned int of the number of Players
    */
    size_t  GetNumberOfGamePlayers()           { return this->VectorOfPlayers.size(); }

    int*    GetSuperTestWrapperValue()         { return this->SuperTestWrapperValue; }

    /* Functional Methods */
    /**
    * @fn T* RemovePlayer(T*, int)
    * @brief Removes the player at the given index, shifting
    *   any players behind them one index forward, and points the param pointer to
    *   location of Player in memory.
    * @param int The index of the Player in the Players vector
    * @return true, if the player was successfully removed, false otherwise
    */
    bool    RemoveGamePlayer(int index){
  // Validate parameters and object initialization //
      if(index < 0 || (unsigned)index > this->VectorOfPlayers.size()){ return false; }
      if(this->VectorOfPlayers.size() == 0){ return false; }

      // Remove player from vector and validate deletion //
      size_t temp = this->VectorOfPlayers.size();
      this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + index);

      // Report results //
      return (this->VectorOfPlayers.size() == (temp - 1) ? true : false);
    }

    /**
    * @fn T* RemovePlayer(T*, int)
    * @brief Removes the player at the given index, shifting
    *   any players behind them one index forward, and points the param pointer to
    *   location of Player in memory.
    * @param T An external pointer that will hold the address of the removed player
    * @param int The index of the Player in the Players vector
    * @return true, if the player was successfully removed, false otherwise
    */
    bool    RemoveGamePlayer(GamePlayer* player, int index){

      // Validate parameters and object initialization //
      if(player == nullptr){ return false; }
      if(index < 0 || (unsigned)index > this->VectorOfPlayers.size()){ return false; }
      if(this->VectorOfPlayers.size() == 0){ return false; }

      // Pull player from vector and validate removal //
      size_t temp = this->VectorOfPlayers.size();
      player = this->VectorOfPlayers.at(index);
      this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + index);

      // Report results //
      return (this->VectorOfPlayers.size() == (temp - 1) ? true : false);
    }
    /**
    * @fn void RemovePlayer(const Player*)
    * @brief Alternative to indexing, removes param player from
    *   vector if found, shifting all players behind them
    *   forward by one.
    * @return true, if the player was successfully removed, false otherwise
    */
    bool    RemoveGamePlayer(const GamePlayer* player){
  // Validate parameters and object initialization //
      if(player == nullptr){ return false; }
      if(this->VectorOfPlayers.size() <= 0){ return false; }

      // Locate any instance of player in vector and remove them //
      bool flag = false;
      for(unsigned i = 0; i < this->VectorOfPlayers.size(); i++){
        if(this->VectorOfPlayers.at(i) == player){
          this->VectorOfPlayers.erase(this->VectorOfPlayers.begin() + i);

          // Player found and removed from group//
          flag = true;
        }
      }

      // Report results //
      return flag;
    }
    /**
    * @fn bool AddPlayer(Player*)
    * @brief Adds a player to the back of the vector
    * @return True if player was successfully added, false otherwise
    */
    bool    AddGamePlayer(GamePlayer* player){
      // Validate parameters and object initialization //
      if(player == nullptr){ return false; }

      // Add pointer to player to the vector, validate operation, and report result //
      size_t temp = this->VectorOfPlayers.size();
      this->VectorOfPlayers.emplace_back(player);
      return (this->VectorOfPlayers.size() == (1 + temp) ? true : false);
    }
  };

}



#endif // GAMEPLAYERS_HPP