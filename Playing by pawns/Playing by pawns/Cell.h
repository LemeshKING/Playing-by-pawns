#pragma once
#include"Pawn.h"

typedef std::unique_ptr<Pawn> UPtrPawn;

class Cell
{
   std::string position;
   sf::Sprite sprite;
   sf::RectangleShape rectangle;
   UPtrPawn pawn;
public:
   Cell() = default;
   Cell(bool color, int i, int j);
   void Draw(sf::RenderWindow &window);
   void setPawn(UPtrPawn &_pawn);
   bool cheackPawn();
   void selectPawn();
};

