#include "CppUnitTest.h"
#include "../Game-Framework/Headers/pch.h"
#include "stdafx.h"

class PlayerTestClass;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace GameFrameworkUnitTests{
  TEST_CLASS(GamePieceUnitTest){
    int valueBuffer[120] = {0};
  public:
    PlayerTestClass*             testPlayer;

  //  Extend abstract GamePiece to a test class //
  class GamePieceTestClass : public GameFramework::GamePiece{

    /**
   * @fn GamePieceTestClass(int*)
   * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
   * @param int* A pointer to an int variable that can be persistently changed by the class destructor
   */
    GamePieceTestClass(int* value) : GamePiece(value){ }
    /**
   * @fn PlayerTestClass()
   * @brief Default constructor
   */
    GamePieceTestClass() : GamePiece() { }
    /**
   * @fn ~Players()
   * @brief Destructor
   */
    ~GamePieceTestClass(){
      if(this->GetSuperTestValue() != nullptr){
        ++(*this->GetSuperTestValue());
      } 
      
    }
    


    /**
   * @fn bool Action(int*)
   * @brief The abstract method that is the base behavior for Player-derived objects
   */
bool  Perform(GameFramework::GameAction* value = nullptr){
      if(value == nullptr){
        return true;
      } else{
        return false;
      }
    }
  };

  


  TEST_CLASS_INITIALIZE(Class_Setup){

  }

  TEST_METHOD_INITIALIZE(Method_Setup){

  }

  TEST_METHOD(Player_ctor){

  }

  TEST_METHOD(Player_dtor){

  }

  TEST_METHOD(SetGamePieces){

  }

  TEST_METHOD(SetID){

  }

  TEST_METHOD(SetNumberOfGamePieces){

  }

  TEST_METHOD(GetGamePieces){

  }

  TEST_METHOD(GetID){

  }

  TEST_METHOD(GetNumberOfGamePieces){

  }

  };