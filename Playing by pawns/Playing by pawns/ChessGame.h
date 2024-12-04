#pragma once
#include<ctime>
#include"AI.h"
#include<array>

typedef std::shared_ptr<Player> SPtrPlayer;

class ChessGame
{
   Board board;
   std::array<SPtrPlayer, 2> pl;
   int turnToMove = 0;
   int indexPlayer = 0;
   bool CheackOwner(const int &cellIndex);
   bool cheackWin();
   void GiveColors();
 public:
   void Run();

};

