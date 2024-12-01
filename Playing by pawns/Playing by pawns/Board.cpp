#include "Board.h"
#include <iostream>

Board::Board()
{
   for(int i = 0; i < 8; i++)
      for(int j = 0; j < 8; j++)
      {
         chessNotation[i * 8 + j] = char('A' + j) + std::to_string(i + 1);
         if(i % 2 == 0)
            if(j % 2 == 0)
               cells[chessNotation[i * 8 + j]] = Cell(false, i, j);
            else
               cells[chessNotation[i * 8 + j]] = Cell(true, i, j);
         else
            if (j % 2 == 0)
               cells[chessNotation[i * 8 + j]] = Cell(true, i, j);
            else
               cells[chessNotation[i * 8 + j]] = Cell(false, i, j);
      }
   for(int i = 5; i < 8; i++)
      for(int j = 0; j < 3; j++)
      {
         UPtrPawn tmp = std::make_unique<Pawn>(false, i, j);
         cells[chessNotation[i * 8 + j]].setPawn(tmp);

      }
   for (int i = 0; i < 3; i++)
      for (int j = 5; j < 8; j++)
      {
         UPtrPawn tmp = std::make_unique<Pawn>(true, i, j);
         cells[chessNotation[i * 8 + j]].setPawn(tmp);

      }

}

void Board::Draw(sf::RenderWindow& window)
{

   for(int i = 0; i < chessNotation.size(); i++)
      cells[chessNotation[i]].Draw(window);
   if (lastSelect != -1)
      for (const auto& i : indexes)
         cells[chessNotation[i]].drawMoveOption(window);
   moved = false;
   
   
}

void Board::SelectPiece(const int& i)
{
   if(lastSelect == i)
   {
      cells[chessNotation[i]].diselectPawn();
      lastSelect = -1;
      return;
   }
   if(!cells[chessNotation[i]].cheackPawn())
   {
      cells[chessNotation[i]].selectPawn();
      if(lastSelect != -1)
         cells[chessNotation[lastSelect]].diselectPawn();
      lastSelect = i;
      showMoveOptions();
   }
   else if (lastSelect != -1)
   {
      cells[chessNotation[lastSelect]].diselectPawn();
      lastSelect = -1;
   }
}

void Board::movePawn(const int& indexCell)
{
   if(lastSelect != -1)
      for(const auto &i : indexes)
         if(i == indexCell)
         {
            cells[chessNotation[indexCell]].movePawn(cells[chessNotation[lastSelect]]);
            cells[chessNotation[indexCell]].diselectPawn();
            moved = true;
            lastSelect = -1;
         }
}

bool Board::wasMoved()
{
   return moved;
}

bool Board::getOwnerPawn(const int& cellIndex)
{
   return cells[chessNotation[cellIndex]].getOwnerPawn();
}

bool Board::cheackPawn(const int& cellIndex)
{
   return !cells[chessNotation[cellIndex]].cheackPawn();
}

bool Board::wasSelected()
{
   return lastSelect != -1;
}

bool Board::canMove(const int& indexCell)
{
   if (lastSelect != -1)
      for (const auto& i : indexes)
         if (i == indexCell)
            return true;
   return false;
}

void Board::setVictoryFields(std::array<int, 9>& victoryFields, bool color)
{
   int k = 0;
   if (color)
      for (int i = 5; i < 8; i++)
         for (int j = 0; j < 3; j++)
               victoryFields[k++] = i * 8 + j;
   else
      for (int i = 0; i < 3; i++)
         for (int j = 5; j < 8; j++)
            victoryFields[k++] = i * 8 + j;
}

void Board::showMoveOptions()
{
   indexes.clear();
   indexes.reserve(4);
   if (lastSelect != -1)
   {
      if(lastSelect + 8 < 64)  
         if(cells[chessNotation[lastSelect + 8]].cheackPawn())
            indexes.emplace_back(lastSelect + 8);
      if(lastSelect - 8 >= 0)
         if (cells[chessNotation[lastSelect - 8]].cheackPawn())
            indexes.emplace_back(lastSelect - 8);
      if(lastSelect % 8 != 0)
         if (cells[chessNotation[lastSelect - 1]].cheackPawn())
            indexes.emplace_back(lastSelect - 1);
      if (lastSelect % 8 != 7)
         if (cells[chessNotation[lastSelect + 1]].cheackPawn())
            indexes.emplace_back(lastSelect + 1);
   }

}
