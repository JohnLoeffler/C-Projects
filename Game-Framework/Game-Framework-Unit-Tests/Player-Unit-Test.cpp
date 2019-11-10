#include "CppUnitTest.h"
#include "../Game-Framework/Headers/pch.h"
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace GameFrameworkUnitTests {
  TEST_CLASS(GamePlayerUnitTest){
  public :
    
    // Create Derived Tester Classes for Abstract 'Player' Class 
    class PlayerTestClass : public GameFramework::GamePlayer{
      
      /**
     * @fn PlayerTestClass(int*)
     * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
     * @param int* A pointer to an int variable that can be persistently changed by the class destructor 
     */
      PlayerTestClass(int* value) : GamePlayer(value){
        
      }
      /**
     * @fn PlayerTestClass()
     * @brief Default constructor
     */
      PlayerTestClass() : GamePlayer() { }
      /**
     * @fn ~Players()
     * @brief Destructor
     */
      ~PlayerTestClass(){
        if(this->GetSuperTestValue() != nullptr){
          ++(*this->GetSuperTestValue());
        }else{
          this->SetSuperTestValue(new int(-1081));
        }
        if(this->GetGamePieces() != nullptr){
          GamePiece** pieces = this->GetGamePieces();
          this->SetGamePieces(nullptr);
          for(int i = 0; i < this->GetNumberOfGamePieces(); i++){
            GamePiece* temp = pieces[i];
            pieces[i] = nullptr;
            delete temp;
          }
          delete [] pieces;
        }
      }
      
      /**
     * @fn bool Action(int*)
     * @brief The abstract method that is the base behavior for Player-derived objects
     */
      bool Perform(GameAction* value = nullptr){
        if(value == nullptr){
          return true;
        }else{
          return false;
        }
      }
    };

    class PlayersTestClass : public GameFramework::GamePlayers{
      PlayersTestClass(int* value) : GamePlayers(value){ }
      
      PlayersTestClass() : GamePlayers(nullptr){ }

      ~PlayersTestClass(){ if( this->SuperTestWrapperValue != nullptr ) ++(*this->SuperTestWrapperValue); }
    };

    PlayerTestClass*           testPlayer;
    PlayersTestClass*          testPlayers;

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

  TEST_CLASS(GamePlayers){
  public :

    TEST_METHOD(GamePlayers_ctor){

    }

    TEST_METHOD(GamePlayers_dtor){

    }

    TEST_METHOD(GamePlayers_GetPlayers){

    }

    TEST_METHOD(GamePlayers_GetNumberOfPlayers){

    }

    TEST_METHOD(GamePlayers_RemovePlayerAtIndex){

    }

    TEST_METHOD(GamePlayers_RemovePlayerAtAddress){

    }

    TEST_METHOD(GamePlayers_AddPlayer){

    }
  };

  TEST_CLASS(GamePiece){
    public:

  };

  TEST_CLASS(GamePieces){
  public:

  };

  TEST_CLASS(GameAction){
  public:

  };

  TEST_CLASS(GameBoard){
  public:

  };

  TEST_CLASS(GameController){
  public:

  };

  TEST_CLASS(GameRuleSet){
  public:

  };

  TEST_CLASS(GameState){
  public:

  };

  TEST_CLASS(GameFrameworkException){
  public:

  };

  TEST_CLASS(GameRules){
  public:

  };
}

