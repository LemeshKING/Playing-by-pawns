#include "Board.h"

int main()
{
	Board board;
   sf::RenderWindow window(sf::VideoMode(1920, 1080), "Playing by pawns", sf::Style::Fullscreen);
	sf::View view;
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::Yellow);
	rect.setSize(sf::Vector2f(32,32));
	rect.setPosition(0,0);
	view.reset(sf::FloatRect(1920, 1080, 512, 512));
	view.setCenter(256, 256);
   window.setFramerateLimit(144);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				int row = (1080 - mousePos.y)  / 54;  
				int col = mousePos.x  / 54; 
				if (row >= 0 && row < 8 && col >= 0 && col < 8)
					board.SelectPiece(row * 8 + col);
			}
			window.draw(rect);
			board.Draw(window);
			window.setView(view);
			window.display();
			window.clear(sf::Color::Blue);

		}
	}
}