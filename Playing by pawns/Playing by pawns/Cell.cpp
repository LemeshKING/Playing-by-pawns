#include "Cell.h"


Cell::Cell(bool color, int i, int j)
{
   rectangle.setSize(sf::Vector2f(54, 54));
   if(color)
      rectangle.setFillColor(sf::Color::Black);
   else
      rectangle.setFillColor(sf::Color::White);
   rectangle.setPosition(40 + j * 54, 418 - i * 54);
}

void Cell::Draw(sf::RenderWindow& window)
{

   window.draw(rectangle);
   if (pawn != nullptr)
      pawn->Draw(window);

}

void Cell::setPawn(UPtrPawn& _pawn)
{
   pawn = std::move(_pawn);
}

bool Cell::cheackPawn()
{
   return pawn == nullptr;
}

void Cell::selectPawn()
{
   pawn->select();
}
