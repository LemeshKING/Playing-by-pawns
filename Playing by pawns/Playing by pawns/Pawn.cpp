#include "Pawn.h"


Pawn::Pawn(bool color, int i, int j)
{
   if(!texture.loadFromFile("Pawns.png"))
      texture.loadFromFile("../Pawns.png");
   sprite.setTexture(texture);

   rectangle.setSize(sf::Vector2f(50,50));
   if(color)
      sprite.setTextureRect(sf::IntRect(32, 0, 32, 54));
   else
      sprite.setTextureRect(sf::IntRect(0, 0, 32, 54));
   sprite.setPosition(51 + j * 54, 418 - i * 54);
   rectangle.setPosition(42 + j * 54, 420 - i * 54);
   owner = color;
}

void Pawn::Draw(sf::RenderWindow& window)
{
   window.draw(sprite);
}

void Pawn::select()
{


}

void Pawn::diselect()
{

}

void Pawn::Move(const sf::Vector2f& position)
{
   sprite.setPosition(position.x + 11, position.y);
}

bool Pawn::getOwner()
{
   return owner;
}
