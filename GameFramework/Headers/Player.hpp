#ifndef PLAYER_HPP
#define PLAYER_HPP

class GamePiece;

class Player{
  GamePiece*  GamePieces;
  int         ID;
public:
  virtual Player();
  virtual ~Player();

  inline void       SetGamePieces(GamePiece* pieces){this->GamePieces = pieces;}
  inline void       SetID(int id)                   {this->ID = id;}
  inline GamePiece* GetGamePieces()                 {return this->GamePieces;}
  inline int        GetID()                         {return this->ID;}
};
#endif // PLAYER_HPP
