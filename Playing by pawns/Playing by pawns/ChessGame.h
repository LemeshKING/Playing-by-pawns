#pragma once
#include"Board.h"
#include"Player.h"
#include<array>

class ChessGame
{
   Board board;
   std::array<Player,2> pl;
   int indexPlayer = 0;
   bool CheackOwner(const int &cellIndex);
   bool cheackWin();
 public:
   void Run();

};

