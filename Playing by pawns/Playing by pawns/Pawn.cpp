#include "Pawn.h"

Pawn::Pawn(bool color, int i, int j)
{
   rectangle.setSize(sf::Vector2f(50,50));
   if(color)
      rectangle.setFillColor(sf::Color::Green);
   else
      rectangle.setFillColor(sf::Color::Red);

   rectangle.setPosition(42 + j * 54, 420 - i * 54);
}

void Pawn::Draw(sf::RenderWindow& window)
{
   window.draw(rectangle);
}

void Pawn::select()
{
   rectangle.setOutlineThickness(5);
   rectangle.setOutlineColor(sf::Color::Yellow);
}
