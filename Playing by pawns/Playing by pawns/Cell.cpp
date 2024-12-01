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

Cell::Cell(const Cell& other)
{
   rectangle = other.rectangle;
}

void Cell::operator=(const Cell& other)
{
   rectangle = other.rectangle;
}

bool Cell::operator==(const Cell& other)
{
   return rectangle.getPosition() == other.rectangle.getPosition();
}

void Cell::diselectPawn()
{
   pawn->diselect();
}

void Cell::drawMoveOption(sf::RenderWindow& window)
{
   sf::CircleShape tmp(27);
   tmp.setFillColor(sf::Color::Cyan);
   tmp.setPosition(rectangle.getPosition());
   window.draw(tmp);
}

void Cell::movePawn(Cell& other)
{
   pawn = std::move(other.pawn);
   pawn->Move(rectangle.getPosition());
}
