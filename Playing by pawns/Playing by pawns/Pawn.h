#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>

class Pawn
{
   sf::Sprite sprite;
   sf::Vector2f position;
   sf::RectangleShape rectangle;
   sf::Texture texture;
   bool owner;
 public:
   Pawn(bool color, int i, int j);
   void Draw(sf::RenderWindow &window);
   void select();
   void diselect();
   void Move(const sf::Vector2f& position);
   bool getOwner();
};

