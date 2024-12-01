#include "ChessGame.h"

bool ChessGame::CheackOwner(const int& cellIndex)
{
	return board.getOwnerPawn(cellIndex) == pl[indexPlayer].color;

}

bool ChessGame::cheackWin()
{
	int k = 0;
	for(int i = 0; i < 9; i++)
		if(board.cheackPawn(pl[indexPlayer].victoryField[i]))
			if(CheackOwner(pl[indexPlayer].victoryField[i]))
				k++;
	if(k == 9)
	{
		std::cout<< "Player " << indexPlayer + 1 << " win!" << std::endl;
		return true;
	}
	return false;
}

void ChessGame::Run()
{
	bool flag = false;
	pl[0].color = true;
	pl[1].color = false;
	board.setVictoryFields(pl[0].victoryField, pl[0].color);
	board.setVictoryFields(pl[1].victoryField, pl[1].color);
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Playing by pawns", sf::Style::Fullscreen);
	sf::View view;
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
			if(!flag)
			{
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					int row = float((1080 - mousePos.y) * 512 / 1080 - 40) / 54;
					int col = (float(mousePos.x * 512 / 1920) - 40) / 54;
					if (row >= 0 && row < 8 && col >= 0 && col < 8)
					{
						int index = row * 8 + col;
						if(board.wasSelected() && board.canMove(index))
						{
							board.movePawn(index);
							flag = cheackWin();
							indexPlayer = indexPlayer == 0 ? 1 : 0;
							continue;
						}
						if(board.cheackPawn(index))
							if(CheackOwner(index))
								board.SelectPiece(index);
						
						
					}
				}
			}
			board.Draw(window);
			window.setView(view);
			window.display();
			window.clear(sf::Color::Blue);

		}
	}
}


