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
         //std::cout << chessNotation[i * 8 + j] << std::endl;
      }
   for (int i = 0; i < 3; i++)
      for (int j = 5; j < 8; j++)
      {
         UPtrPawn tmp = std::make_unique<Pawn>(true, i, j);
         cells[chessNotation[i * 8 + j]].setPawn(tmp);
         //std::cout << chessNotation[i * 8 + j] << std::endl;
      }

}

void Board::Draw(sf::RenderWindow& window)
{
   for(int i = 0; i < chessNotation.size(); i++)
      cells[chessNotation[i]].Draw(window);
}

void Board::SelectPiece(const int& i)
{
   if(!cells[chessNotation[i]].cheackPawn())
      cells[chessNotation[i]].selectPawn();
}
