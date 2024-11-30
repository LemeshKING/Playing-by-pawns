#pragma once

#include "Cell.h"
#include <map>


class Board
{
   std::map<int, std::string> chessNotation;
   std::map<std::string, Cell> cells;

public:
   Board();
   void Draw(sf::RenderWindow &window);
   void SelectPiece(const int &i);
};

