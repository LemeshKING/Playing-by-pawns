#include "AI.h"

int AI::ChooseMove(std::vector<int>& MoveOptions, int &indexSelectedPawn)
{
   int initDistY = abs(victoryField[target] / 8 - AIPawns[indexSelectedPawn] / 8);
   int initDistX = abs(victoryField[target] % 8 - AIPawns[indexSelectedPawn] % 8);
   if(initDistY == 0 && initDistX == 0)
   {
      PawnsReachedTarget.emplace_back(indexSelectedPawn);
      if(!color)
      {
         target--;
         if(target == -1)
            target = 5;
         if(target == 2)
            target = 8;
      }
      else
      {
         target++;
         if(target == 9)
            target = 3;
         if(target == 6)
            target = 0;
      }
      return -1;
   }
   std::vector<int> indexsMove;
   indexsMove.reserve(2);
   int distY = 0;
   int distX = 0;
   for (int i = 0; i < MoveOptions.size(); i++)
   {
      distY = abs(victoryField[target] / 8 - MoveOptions[i] / 8);
      distX = abs(victoryField[target] % 8 - MoveOptions[i] % 8);
      if (distY < initDistY || distX < initDistX)
         indexsMove.emplace_back(i);
   }
   if(indexsMove.empty())
      return MoveOptions[std::rand() % MoveOptions.size()];
   int randIndexMove = 0;
   if(indexsMove.size() == 2)
      randIndexMove = std::rand() % 2;
   
   return MoveOptions[indexsMove[randIndexMove]];
}

AI::AI(std::map<int, int>  _AIPawns, bool _color)
{
   AIPawns = _AIPawns;
   PawnsReachedTarget.reserve(9);
   color = _color;
   target = 2;
   if(color)
      target = 6;
}

void AI::movePawn(Board& board)
{
   int selectedIndexPawn = std::rand() % 9;
   for(const auto &i : PawnsReachedTarget)
      if (i == selectedIndexPawn)
      {
         movePawn(board);
         return;
      }
   board.SelectPiece(AIPawns[selectedIndexPawn]);
   std::vector<int> indexesCellsToMove = board.getMoveOptions();
   int selectedMove = -1;
   while (indexesCellsToMove.empty())
   {
      selectedIndexPawn = std::rand() % 9;
      for (const auto& i : PawnsReachedTarget)
         if (i == selectedIndexPawn)
         {
            movePawn(board);
            return;
         }
      board.SelectPiece(AIPawns[selectedIndexPawn]);
      indexesCellsToMove = board.getMoveOptions();

   }
   selectedMove = ChooseMove(indexesCellsToMove, selectedIndexPawn);
   if (selectedMove == -1)
   {
      movePawn(board);
      return;
   }
   board.movePawn(selectedMove);
   AIPawns[selectedIndexPawn] = selectedMove;

}
