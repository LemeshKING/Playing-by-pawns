#pragma once
#include<SFML/Graphics.hpp>

class Pawn
{
   sf::Sprite sprite;
   sf::Vector2f position;
   sf::RectangleShape rectangle;
 public:
   Pawn() = default;
   Pawn(bool color, int i, int j);
   void Draw(sf::RenderWindow &window);
   void select();
   void diselect();
   void Move(const sf::Vector2f& position);
};

