#include "CppUnitTest.h"
#include "../Game-Framework/Headers/player.h"
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace GameFrameworkUnitTests {
  TEST_CLASS(PlayerUnitTest){
  public :
    class PlayerTestClass : public GameFrame::Player{
      // DerivedTestValue is the
      int* DerivedTestValue;
      
      /**
     * @fn PlayerTestClass(int*)
     * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
     * @param int* A pointer to an int variable that can be persistently changed by the class destructor 
     */
      PlayerTestClass(int* value) : GameFrame::Player(value) { this->DerivedTestValue = value; }
      /**
     * @fn PlayerTestClass()
     * @brief Default constructor
     */
      PlayerTestClass() : GameFrame::Player() { this->DerivedTestValue = nullptr; }
      /**
     * @fn Players()
     * @brief Default constructor
     */
      virtual ~PlayerTestClass(){
        if(this->DerivedTestValue != nullptr){
          (*DerivedTestValue)++;
        }else{
          this->DerivedTestValue = new int(-2613394);
        }
        if(this->GamePieces != nullptr){
          delete [] this->GamePieces;
          this->GamePieces = nullptr;
        }
      }
      /**
     * @fn Players()
     * @brief Default constructor
     */
      bool Action(int *value){
        if(value == nullptr){
          return false;
        }else{
          (*value) = -1081;
          return true;
        }
      }
    };

    TEST_CLASS_INITIALIZE(Class_Setup){
      GameFrame::Player* testPlayer = nullptr;
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

