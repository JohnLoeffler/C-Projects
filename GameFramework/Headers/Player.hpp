#ifndef PLAYER_HPP
#define PLAYER_HPP

class GamePiece;

class Player{
  GamePiece*        GamePieces;
  int               ID;
public:
                    Player()  {this->GamePieces = nullptr; this->ID = INT_MIN;}
  virtual           ~Player();

  inline void       SetGamePieces(GamePiece* pieces){this->GamePieces = pieces;}
  inline void       SetID(int id)                   {this->ID = id;}
  inline GamePiece* GetGamePieces()                 {return this->GamePieces;}
  inline int        GetID()                         {return this->ID;}

  virtual void      Action() =0;
};
#endif // PLAYER_HPP
