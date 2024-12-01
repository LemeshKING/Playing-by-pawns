#pragma once
#include"Pawn.h"

typedef std::unique_ptr<Pawn> UPtrPawn;


class Cell
{
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
   Cell(const Cell &other);
   void operator=(const Cell &other);
   bool operator==(const Cell &other);
   void diselectPawn();
   void drawMoveOption(sf::RenderWindow& window);
   void movePawn(Cell &other);
   bool getOwnerPawn();
};

