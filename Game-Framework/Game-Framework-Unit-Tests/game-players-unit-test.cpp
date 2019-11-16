#include "stdafx.h"
namespace GameFrameworkUnitTests{
  // Create derived tester class for 'GamePlayers' //
  class PlayersTestClass : public GameFramework::GamePlayers{
    public:
      std::vector<GameFramework::GamePlayer*> gamePlayers;
    /**
    * @fn PlayerTestClass(int*)
    * @brief Parameterized constructor to allow for testing of destructor function on external reference variable
    * @param int* A pointer to an int variable that can be persistently changed by the class destructor
    */
    PlayersTestClass(int* value) : GameFramework::GamePlayers(value){
      this->SuperTestWrapperValue = value;
 
    }
    /**
    * @fn PlayersTestClass()
    * @brief Default constructor
    */
    PlayersTestClass() : GameFramework::GamePlayers(nullptr) {}
    /**
    * @fn ~PlayersTestClass()
    * @brief Destructor
    */
    ~PlayersTestClass(){
      if(this->GetSuperTestWrapperValue() != nullptr){
        ++(*this->GetSuperTestWrapperValue());
      }
    }

    void EvolveValues(){
      this->VectorOfPlayers = gamePlayers;
    }

    void InheritValues(){
      gamePlayers = this->VectorOfPlayers;
    }

  };

  class TestPlayer : public GameFramework::GamePlayer{
  public:
    TestPlayer(int& value) : GameFramework::GamePlayer(value){ }

    TestPlayer() : GameFramework::GamePlayer(){ }

    bool Perform(GameFramework::GameAction* action){ return true;}

  };

  TEST_CLASS(GamePlayersUnitTest){
    PlayersTestClass* testPlayers;
    std::vector<GameFramework::GamePlayer*> players;
    TEST_CLASS_INITIALIZE(Class_Setup){
      
    }

    TEST_METHOD_INITIALIZE(Method_Setup){
      // SETUP THE PLAYERSTESTCLASS OBJECT //
      for(unsigned i = 0; i < 10; i++){
        TestPlayer* player = new TestPlayer();
        players.emplace_back(player);
      }

    }

    TEST_METHOD(PlayersParameterizedConstructor){
      int* value = 0;
      testPlayers = new PlayersTestClass(value);
      Assert::IsNotNull(testPlayers);
    }

    TEST_METHOD(PlayersDefaultConstructor){
      testPlayers = new PlayersTestClass();
      Assert::IsNotNull(testPlayers);
    }

    TEST_METHOD(PlayersDestructor){
      int* value = new int(0);
      testPlayers = new PlayersTestClass(value);
      delete testPlayers;
      Assert::IsTrue(2 == *value);
    }

    TEST_METHOD(Players_RemoveGamePlayer_FromIndex){
      testPlayers = new PlayersTestClass();
      testPlayers->InheritValues();
      testPlayers->SetGamePlayers(players);

      // TEST 'REMOVEGAMEPLAYER_ATINDEX' FUNCTIONALITY //
      unsigned size = testPlayers->GetNumberOfGamePlayers();

      while(testPlayers->GetNumberOfGamePlayers() > 1){
        testPlayers->RemoveGamePlayer(1);
      }
      testPlayers->RemoveGamePlayer(0);

      wchar_t msg[64];
      swprintf_s(msg, L"Out of loop, testPlayers->gamePlayers.size() == %d", testPlayers->GetNumberOfGamePlayers());
      Assert::IsTrue(0 == testPlayers->GetNumberOfGamePlayers(), msg);
    }

    TEST_METHOD(Players_RemoveGamePlayer_PopFromIndex){
    // TEST 'POPGAMEPLAYER_FROMINDEX' FUNCTIONALITY //
      TestPlayer* playerBuffer = nullptr;
      std::vector<TestPlayer*> poppedPlayers;
      
      testPlayers = new PlayersTestClass();
      testPlayers->SetGamePlayers(players);

      unsigned startSize = testPlayers->GetNumberOfGamePlayers(), count = 1;
      while(testPlayers->GetNumberOfGamePlayers() >1){
        playerBuffer = new TestPlayer();
        if(testPlayers->RemoveGamePlayer(playerBuffer, startSize-count)){
          wchar_t msg[64];
          swprintf_s(msg, L"playerBuffer is null. Count == %d", count);
          Assert::IsNotNull(playerBuffer, msg);
          poppedPlayers.emplace_back(playerBuffer);
          count++;
        } else{
          wchar_t msg[64];
          swprintf_s(msg, L"RemoveGamePlayer() returned false: %d", testPlayers->GetNumberOfGamePlayers());
          Assert::IsFalse(true, msg);
        }
      }
        
  // TODO: Figure out which assertions are failing and start including diagnostic messaging in assertions
      wchar_t msg[64];
      swprintf_s(msg, L"GetNumberOfGamePlayers() == %d", testPlayers->GetNumberOfGamePlayers());
      //Assert::IsTrue(0 == testPlayers->GetNumberOfGamePlayers(), msg);
      wchar_t msgTwo[64];
      swprintf_s(msgTwo, L"poppedPlayers.size() == %d", poppedPlayers.size());
      Assert::IsTrue(poppedPlayers.size() > 0, msgTwo);
      TestPlayer* lastPlayer = nullptr;
      for(unsigned i = 0; i < poppedPlayers.size(); i++){
        if(lastPlayer != nullptr){
          wchar_t msgThree[64];
          swprintf_s(msgThree, L"lastPlayer->GetPlayerID() == %d", lastPlayer->GetPlayerID());
          Assert::IsTrue(-1 == lastPlayer->GetPlayerID(), msgThree);
        }
        playerBuffer = poppedPlayers.at(i);
        Assert::IsNotNull(playerBuffer, L"-4-");
        lastPlayer = playerBuffer;
      }
    }

    TEST_METHOD(Players_RemoveGamePlayer_PlayerPointer){
      testPlayers = new PlayersTestClass();
      testPlayers->SetGamePlayers(players);

      int i = 0;

      // TEST 'REMOVEGAMEPLAYER_FROM_POINTER' FUNCTIONALITY //
      while(testPlayers->GetNumberOfGamePlayers() > 1){
        testPlayers->RemoveGamePlayer(players[i]);
        i++;
      }
      testPlayers->RemoveGamePlayer(players[i]);

      wchar_t msg[64];
      swprintf_s(msg, L"Out of loop, testPlayers->gamePlayers.size() == %d", testPlayers->GetNumberOfGamePlayers());
      Assert::IsTrue(0 == testPlayers->GetNumberOfGamePlayers(), msg);
    }

    TEST_METHOD(Players_AddGamePlayer){
    // TODO: Introduce Assertions into test
      std::vector<GameFramework::GamePlayer*> players;
      for(unsigned i = 0; i < 10; i++){
        TestPlayer* player = new TestPlayer();
        players.emplace_back(player);
      }

      PlayersTestClass* testPlayers = new PlayersTestClass();

      // TEST 'ADDGAMEPLAYER' FUNCTIONALITY //
    }
  };
}
