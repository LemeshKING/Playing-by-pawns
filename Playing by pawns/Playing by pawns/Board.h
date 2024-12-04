#pragma once

#include "Cell.h"
#include <map>
#include <vector>
#include <array>



class Board
{
private:
   std::vector<int> indexes;
   std::map<int, std::string> chessNotation;
   std::map<std::string, Cell> cells;
   int lastSelect = -1;
   void CalculateMoveOptions();
   bool moved = false;
public:
   Board();
   void Draw(sf::RenderWindow &window);
   void SelectPiece(const int &i);
   void movePawn(const int& indexCell);
   bool wasMoved();
   bool getOwnerPawn(const int& cellIndex);
   bool cheackPawn(const int& cellIndex);
   bool wasSelected();
   bool canMove(const int& indexCell);
   void setVictoryFields(std::array<int,9> &victoryFields, bool color);
   std::vector<int> getMoveOptions();
   std::map<int,int> getAIPawns(const bool &color);
   
};

