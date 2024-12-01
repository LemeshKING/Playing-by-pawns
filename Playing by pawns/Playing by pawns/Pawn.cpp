#include "Pawn.h"


Pawn::Pawn(bool color, int i, int j)
{
   rectangle.setSize(sf::Vector2f(50,50));
   if(color)
      rectangle.setFillColor(sf::Color::Green);
   else
      rectangle.setFillColor(sf::Color::Red);

   rectangle.setPosition(42 + j * 54, 420 - i * 54);
   owner = color;
}

void Pawn::Draw(sf::RenderWindow& window)
{
   window.draw(rectangle);
}

void Pawn::select()
{
   rectangle.setOutlineThickness(1);
   rectangle.setOutlineColor(sf::Color::Yellow);
}

void Pawn::diselect()
{
   rectangle.setOutlineThickness(0);
}

void Pawn::Move(const sf::Vector2f& position)
{
   rectangle.setPosition(position.x + 2, position.y + 2);
}

bool Pawn::getOwner()
{
   return owner;
}
