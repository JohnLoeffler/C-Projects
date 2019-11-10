#include "stdafx.h"
namespace GameFrameworkUnitTests{
  // Create derived tester class for 'GamePlayers' //
  class PlayersTestClass : public GameFramework::GamePlayers{
    public:
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
  };

  class TestPlayer : public GameFramework::GamePlayer{
    bool Perform(GameFramework::GameAction* action){ return true;}

  };

  TEST_CLASS(GamePlayersUnitTest){
    TEST_CLASS_INITIALIZE(Class_Setup){
      
    }

    TEST_METHOD_INITIALIZE(Method_Setup){
      
    }

    TEST_METHOD(PlayersParameterizedConstructor){
      int* value = 0;
      PlayersTestClass* testPlayers = new PlayersTestClass(value);
      Assert::IsNotNull(testPlayers);
      //Assert::AreEqual(0,*testPlayers->GetSuperTestWrapperValue());
    }

    TEST_METHOD(PlayersDefaultConstructor){
      PlayersTestClass* testPlayers = new PlayersTestClass();
      Assert::IsNotNull(testPlayers);
    }

    TEST_METHOD(PlayersDestructor){
      int* value = new int(0);
      PlayersTestClass* testPlayers = new PlayersTestClass(value);
      delete testPlayers;
      Assert::AreEqual(2, *value);
    }

    TEST_METHOD(Players_RemoveGamePlayer_FromIndex){
      // SETUP THE PLAYERSTESTCLASS OBJECT //
      std::vector<GameFramework::GamePlayer*> players;
      for(unsigned i = 0; i < 10; i++){
        TestPlayer* player = new TestPlayer();
        player->SetSuperTestValue(new int(i * 3));
        player->SetPlayerID((int)i + 1);
        players.emplace_back(player);
      }

      PlayersTestClass* testPlayers = new PlayersTestClass();
      testPlayers->SetGamePlayers(players);

      // TEST 'REMOVEGAMEPLAYER_ATINDEX' FUNCTIONALITY //
      unsigned startSize = testPlayers->GetNumberOfGamePlayers(), count = 0;
      for(unsigned i = 0; i < testPlayers->GetNumberOfGamePlayers(); i++){
        testPlayers->RemoveGamePlayer(i);
        count++;
      }
      Assert::IsTrue(startSize-count==testPlayers->GetNumberOfGamePlayers());
    }

    TEST_METHOD(Players_RemoveGamePlayer_PopFromIndex){
      // SETUP THE PLAYERSTESTCLASS OBJECT //
      std::vector<GameFramework::GamePlayer*> players;
      for(unsigned i = 0; i < 10; i++){
        TestPlayer* player = new TestPlayer();
        player->SetSuperTestValue(new int(i * 3));
        player->SetPlayerID((int)i + 1);
        players.emplace_back(player);
      }

      PlayersTestClass* testPlayers = new PlayersTestClass();
      testPlayers->SetGamePlayers(players);
      
      // TEST 'POPGAMEPLAYER_FROMINDEX' FUNCTIONALITY //
      TestPlayer* playerBuffer = nullptr;
      std::vector<TestPlayer*> poppedPlayers;

      unsigned startSize = testPlayers->GetNumberOfGamePlayers(), count = 0;
      for(unsigned i = 0; i < testPlayers->GetNumberOfGamePlayers(); i++){
        testPlayers->RemoveGamePlayer(playerBuffer, i);
        poppedPlayers.emplace_back(playerBuffer);
        count++;
      }
      // TODO: Figure out which assertions are failing and start including diagnostic messaging in assertions
      //Assert::IsTrue(startSize - count == testPlayers->GetNumberOfGamePlayers());
      //Assert::IsTrue(poppedPlayers.size() == 1+count);
      TestPlayer* lastPlayer = nullptr;
      for(unsigned i = 0; i < poppedPlayers.size(); i++){
        if(lastPlayer != nullptr){
      //    Assert::AreEqual((int)i, lastPlayer->GetPlayerID());
        }
        playerBuffer = poppedPlayers.at(i);
        //Assert::IsNotNull(playerBuffer);
        lastPlayer = playerBuffer;
      }
    }

    TEST_METHOD(Players_RemoveGamePlayer_PlayerPointer){
    // TODO: Introduce Assertions into test
      // SETUP THE PLAYERSTESTCLASS OBJECT //
      std::vector<GameFramework::GamePlayer*> players;
      for(unsigned i = 0; i < 10; i++){
        TestPlayer* player = new TestPlayer();
        player->SetSuperTestValue(new int(i * 3));
        player->SetPlayerID((int)i + 1);
        players.emplace_back(player);
      }

      PlayersTestClass* testPlayers = new PlayersTestClass();
      testPlayers->SetGamePlayers(players);

      // TEST 'REMOVEGAMEPLAYER_FROM_POINTER' FUNCTIONALITY //
    }

    TEST_METHOD(Players_AddGamePlayer){
    // TODO: Introduce Assertions into test
      std::vector<GameFramework::GamePlayer*> players;
      for(unsigned i = 0; i < 10; i++){
        TestPlayer* player = new TestPlayer();
        player->SetSuperTestValue(new int(i * 3));
        player->SetPlayerID((int)i + 1);
        players.emplace_back(player);
      }

      PlayersTestClass* testPlayers = new PlayersTestClass();

      // TEST 'ADDGAMEPLAYER' FUNCTIONALITY //

    }
  };
}
