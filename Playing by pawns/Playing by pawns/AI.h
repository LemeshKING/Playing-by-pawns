#pragma once
#include "Player.h"
#include "Board.h"
#include <map>
#include <vector>
class AI :
    public Player
{
private:
   int selectedPawn;
   std::map<int, int> AIPawns;
   int ChooseMove(std::vector<int> &MoveOptions, int &indexSelectedPawn);
   int target;
   std::vector<int> PawnsReachedTarget;
public:
   AI() = default;
   AI(std::map<int,int> _AIPawns, bool _color);
   void movePawn(Board &board);
   
};

