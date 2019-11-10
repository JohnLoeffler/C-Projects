#include "CppUnitTest.h"
#include "../Game-Framework/Headers/game-player.h"
#include "../Game-Framework/Headers/pch.h"
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace GameFrameworkUnitTests {
  TEST_CLASS(PlayerUnitTest){
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

    TEST_CLASS_INITIALIZE(Class_Setup){
      GameFramework::GamePlayer* testPlayer = nullptr;
      GameFramework::GamePlayer* testPlayerGroup = nullptr;
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

  TEST_CLASS(Players){
    public :

      TEST_METHOD(Players_ctor){

      }

      TEST_METHOD(Players_dtor){

      }

      TEST_METHOD(Players_GetPlayers){

      }

      TEST_METHOD(Players_GetNumberOfPlayers){

      }

      TEST_METHOD(Players_RemovePlayerAtIndex){

      }

      TEST_METHOD(Players_RemovePlayerAtAddress){

      }

      TEST_METHOD(Players_AddPlayer){

      }  
  };
}

