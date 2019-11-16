#ifndef GAMEPIECES_HPP
#define GAMEPIECES_HPP
#pragma once
#include <vector>

namespace GameFramework{
  class GamePiece;
  /**
  * @brief A wrapper class for a collections of GamePieces to make grouping and managing them easier
  */
  class GamePieces{
  protected:
    /* Data Members */
    int*    SuperTestWrapperValue;
    std::vector<GamePiece*> Pieces;

  public:
    /******************************
    * Constructors and Destructor *
    ******************************/

    /**
    * @fn GamePieces(int*)
    * @brief Parameterized Constructor
    */
    GamePieces(int* value)     { this->SuperTestWrapperValue = value; }
    /**
    * @fn GamePieces()
    * @brief Default Constructor
    */
    GamePieces()               { this->SuperTestWrapperValue = nullptr; }
    /**
    * @fn ~GamePieces()
    * @brief Destructor
    */
    virtual   ~GamePieces()    { ++(*this->SuperTestWrapperValue); }

    /*********************
    *      Getters      *
    *********************/

    /**
    * @fn GetGamePieces()
    * @brief Gets the vector of GamePieces from the container.
    * @return A vector of GamePiece pointers
    */
    std::vector<GamePiece*>    GetGamePieces(){ return this->Pieces; }
    /**
    * @fn GetNumberOfGamePieces()
    * @brief Gets the number of GamePieces in the container
    * @return A size_t of the size of the containers vector of GamePiece pointers
    */
    size_t GetNumberOfGamePieces()         { return this->Pieces.size(); }

    /*********************
    * Functional Methods *
    *********************/

    /**
    * @fn AddGamePiece(GamePiece*)
    * @brief Adds a GamePiece pointer to the container
    * @param A pointer to the game piece to add to the container
    * @return True if the addition to the vector was successful, false otherwise
    */
    bool AddGamePiece(GamePiece* piece){
      // Validate parameter and object initialization //
      if(piece == nullptr){ return false; }

      // Add piece, verify operation, and report results //
      size_t temp = this->Pieces.size();
      Pieces.emplace_back(piece);
      return (this->Pieces.size() == (temp + 1) ? true : false);
    }

    /**
    * @fn RemoveGamePiece(GamePiece*, int)
    * @brief Adds a GamePiece pointer to the container
    * @param A GamePiece pointer that returns the GamePiece pointer to the calling function rather than destroying it
    * @param An int for the GamePiece's index in the containers vector
    * @return True if the removal of the GamePiece was successful, false otherwise
    */
    bool RemoveGamePiece(GamePiece* piece, int index){
      // Validate parameters and object instantiation //
      if(index < 0 || (unsigned)index >= this->Pieces.size()){ return false; }

      // Assign pointer from vector to external reference variable //
      piece = this->Pieces.at(index);

      // Remove piece at Index, verify operation, and report results //
      size_t temp = this->Pieces.size();
      this->Pieces.erase(this->Pieces.begin() + index);
      return (this->Pieces.size() == (temp - 1) ? true : false);
    }

    /**
    * @fn RemoveGamePiece(int)
    * @brief removes a GamePiece pointer from the container based on its index in the underlying vector
    * @param An int for the index of the GamePiece to remove
    * @return True if the removal of the GamePiece was successful, false otherwise
    */
    bool RemoveGamePiece(int index){
      // Validate parameter and object initialization //
      if(index < 0 || (unsigned)index >= this->Pieces.size()){ return false; }
      if(this->Pieces.size() == 0){ return false; }

      // Remove piece at Index, verify operation, and report results //
      size_t temp = this->Pieces.size();
      this->Pieces.erase(this->Pieces.begin() + index);
      return (this->Pieces.size() == (temp - 1) ? true : false);
    }

    /**
    * @fn RemoveGamePiece(const GamePiece*)
    * @brief Removes any instance of a GamePiece pointer from the container
    * @param A const GamePiece pointer to remove from the container
    * @return True if the GamePiece was found and all instances removed from the containers vector
    */
    bool RemoveGamePiece(const GamePiece* piece){
      // Validate parameter and object initialization //
      if(piece == nullptr){ return false; }
      if(this->Pieces.size() == 0){ return false; }

      // Search for piece in vector, remove all instances of it, verify operations, and report results //
      unsigned count = 0;
      unsigned temp = this->Pieces.size();
      for(unsigned i = 0; i < this->Pieces.size(); i++){
        if(this->Pieces.at(i) == piece){
          count++;
          this->Pieces.erase(this->Pieces.begin() + i);
          i--;
        }
      }
      return (this->Pieces.size() == (temp - count) ? true : false);
    }
  };
}
#endif // GAMEPIECES_HPP
