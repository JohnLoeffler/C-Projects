#include "CppUnitTest.h"
#include "../Game-Framework/Headers/pch.h"
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace GameFrameworkUnitTests {
  TEST_CLASS(GamePlayerUnitTest){
  public :
    
    // Create Derived Tester Classes for Abstract 'GamePlayer' Class 
    class PlayerTestClass : public GameFramework::GamePlayer{
      /**
     * @fn PlayerTestClass(int*)
     * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
     * @param int* A pointer to an int variable that can be persistently changed by the class destructor 
     */
      PlayerTestClass(int& value) : GamePlayer(value){
        
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
        }

        if(this->GetGamePieces().size()>0){
          std::vector<GamePiece*> pieces;
          for(int i = 0; i < this->GetNumberOfGamePieces(); i++){
            GamePiece* temp = pieces.at(i);
            pieces.emplace_back(temp);
            delete temp;
          }
        }
      }
      
      /**
     * @fn bool Action(int*)
     * @brief The abstract method that is the base behavior for Player-derived objects
     */
      bool Perform(GameFramework::GameAction* value = nullptr){
        if(value == nullptr){ 
          return true; 
        } else { 
          return false; 
        }
      }
    };

    PlayerTestClass* testPlayer = nullptr;
    

    TEST_CLASS_INITIALIZE(Class_Setup){

    }

    TEST_METHOD_INITIALIZE(Method_Setup){
      
    }

    TEST_METHOD(Player_ctor){
      int* value = new int(400);
      
      PlayerTestClass testPlayer(); 
      testPlayer.SetSuperTestValue(value);
      Assert::IsNotNull(testPlayer,"Player parameterized ctor working", __FILE__, __LINE__);
    }

    TEST_METHOD(Player_dtor){

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

