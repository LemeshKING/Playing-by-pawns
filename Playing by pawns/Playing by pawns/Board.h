#pragma once

#include "Cell.h"
#include <map>
#include <vector>


class Board
{
private:
   std::vector<int> indexes;
   std::map<int, std::string> chessNotation;
   std::map<std::string, Cell> cells;
   int lastSelect = -1;
   void showMoveOptions();
   bool moved = false;
public:
   Board();
   void Draw(sf::RenderWindow &window);
   void SelectPiece(const int &i);
   void movePawn(const int& indexCell);
   bool wasMoved();

   
};

