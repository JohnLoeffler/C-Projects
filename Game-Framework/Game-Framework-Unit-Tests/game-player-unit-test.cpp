#include "CppUnitTest.h"
#include "../Game-Framework/Headers/pch.h"
#include <string>
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace GameFrameworkUnitTests {
  using namespace std::string_literals;
  TEST_CLASS(GamePlayerUnitTest){
  public :
    
    // Create Derived Tester Classes for Abstract 'GamePlayer' Class 
    class PlayerTestClass : public GameFramework::GamePlayer{
    public:
      int playerID, numberOfGamePieces;
      std::vector<GameFramework::GamePiece*> pieces;

     /**
     * @fn PlayerTestClass(int*)
     * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
     * @param int* A pointer to an int variable that can be persistently changed by the class destructor 
     */
      PlayerTestClass(int& value) : GameFramework::GamePlayer(value){ InheritValues(); }
      /**
     * @fn PlayerTestClass()
     * @brief Default constructor
     */
      PlayerTestClass() : GameFramework::GamePlayer() { InheritValues(); }
      /**
     * @fn ~Players()
     * @brief Destructor
     */
      ~PlayerTestClass(){
        if(this->GetGamePieces().size()>0){
          std::vector<GameFramework::GamePiece*> pieces;
          for(int i = 0; i < this->GetNumberOfGamePieces(); i++){
            GameFramework::GamePiece* temp = pieces.at(i);
            pieces.emplace_back(temp);
            delete temp;
          }
        }
        if(this->GetSuperTestValue() != -1){
          ++this->GetSuperTestValue();
        }
      }

      void InheritValues(){
        playerID = this->PlayerID;
        numberOfGamePieces = this->GamePiecesHeld.size();
        pieces = this->GamePiecesHeld;
      }
      
      void EvolveValues(){
        this->PlayerID = playerID;
        this->GamePiecesHeld = pieces;
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
      testPlayer = nullptr;
    }

    TEST_METHOD_CLEANUP(Method_Cleanup){
      
    }

    TEST_METHOD(PlayerParameterizedConstructor){
      int value = 0;
      
      testPlayer = new PlayerTestClass(value);
      const wchar_t* msg = L"testPlayer is null!";
      Assert::IsNotNull(testPlayer, msg);
    }

    TEST_METHOD(PlayerDefaultConstructor){
      testPlayer = new PlayerTestClass();
      const wchar_t* msg = L"testPlayer is null!";
      Assert::IsNotNull(testPlayer, msg);
    }

    TEST_METHOD(PlayerDeconstructor){
      int value  = 0;
      testPlayer = new PlayerTestClass(value);
      Assert::IsTrue(0 == value, L"PlayerDestructor not working!");
    }

    TEST_METHOD(PlayerSetGamePieces){
      std::vector<GameFramework::GamePiece*> gamePieces;
      GameFramework::GamePiece* piece = new GameFramework::GamePiece();
      gamePieces.emplace_back(piece);
      testPlayer = new PlayerTestClass();
      testPlayer->SetGamePieces(gamePieces);
      testPlayer->InheritValues();

      wchar_t msg[64];
      swprintf_s(msg, L"SetGamePieces Not Working: size of vector = %d", (int) testPlayer->pieces.size());

      Assert::IsTrue(1 == testPlayer->pieces.size(), msg);
    }

    TEST_METHOD(PlayerSetPlayerID){
      testPlayer = new PlayerTestClass();
      testPlayer->SetPlayerID(1);
      testPlayer->InheritValues();
      wchar_t msg[64];
      swprintf_s(msg, L"SetPlayerID Not Working: ID value set as %d", testPlayer->playerID);

      Assert::IsTrue(1 == testPlayer->playerID, msg);
    }

    TEST_METHOD(PlayerGetGamePieces){
      std::vector<GameFramework::GamePiece*> gamePieces;
      for(int i = 0; i < 10; i++){
        GameFramework::GamePiece* piece = new GameFramework::GamePiece();
        gamePieces.emplace_back(piece);
      }
      
      testPlayer = new PlayerTestClass();
      testPlayer->pieces = gamePieces;
      testPlayer->EvolveValues();
      
      wchar_t msg[64];
      swprintf_s(msg, L"GetGamePieces Not Working!");

      Assert::IsTrue(10 == testPlayer->GetGamePieces().size(), msg);
    }

    TEST_METHOD(PlayerGetNumberOfGamePieces){
      std::vector<GameFramework::GamePiece*> gamePieces;
      for(int i = 0; i < 10; i++){
        GameFramework::GamePiece* piece = new GameFramework::GamePiece();
        gamePieces.emplace_back(piece);
      }

      testPlayer = new PlayerTestClass();
      testPlayer->pieces = gamePieces;
      testPlayer->EvolveValues();

      wchar_t msg[64];
      swprintf_s(msg, L"GetNumberOfGamePieces Not Working: size of vector is: %d", testPlayer->GetNumberOfGamePieces());

      Assert::IsTrue(10 == testPlayer->GetNumberOfGamePieces(), msg);
    }

    TEST_METHOD(PlayerGetSuperTestValue){
      int value  = 1;
      testPlayer = new PlayerTestClass(value);
      
      wchar_t msg[64];
      swprintf_s(msg, L"GetSuperTestValue Not Working: Value is %d", (testPlayer->GetSuperTestValue()));
      
      Assert::IsTrue(value == testPlayer->GetSuperTestValue(), msg);
    }

    TEST_METHOD(PlayerGetPlayerID){
      testPlayer = new PlayerTestClass();
      testPlayer->SetPlayerID(1);
      testPlayer->InheritValues();

      wchar_t msg[64];
      swprintf_s(msg, L"SetPlayerID Not Working: Expected value = 1 | Actual Value = %d", testPlayer->playerID);

      Assert::IsTrue(1 == testPlayer->GetPlayerID(), msg);
    }
  };
}

