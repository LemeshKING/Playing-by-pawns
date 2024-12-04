#include "ChessGame.h"

bool ChessGame::CheackOwner(const int& cellIndex)
{
	return board.getOwnerPawn(cellIndex) == pl[turnToMove]->color;

}

bool ChessGame::cheackWin()
{
	int k = 0;
	for(int i = 0; i < 9; i++)
		if(board.cheackPawn(pl[turnToMove]->victoryField[i]))
			if(CheackOwner(pl[turnToMove]->victoryField[i]))
				k++;
	if(k == 9)
	{
		std::cout<< "Player " << turnToMove + 1 << " win!" << std::endl;
		return true;
	}
	return false;
}

void ChessGame::GiveColors()
{
	int playerColor = std::rand() % 2;
	if(playerColor)
	{
		pl[0] = std::make_shared<Player>();
		pl[1] = std::make_shared<AI>(board.getAIPawns(false), false);
		pl[0]->color = true;
		indexPlayer = 0;
	}
	else
	{
		pl[1] = std::make_shared<Player>();
		pl[0] = std::make_shared<AI>(board.getAIPawns(true), true);
		pl[1]->color = false;
		indexPlayer = 1;
	}
}

void ChessGame::Run()
{
	srand(time(NULL));
	bool flag = false;
	GiveColors();
	board.setVictoryFields(pl[0]->victoryField, pl[0]->color);
	board.setVictoryFields(pl[1]->victoryField, pl[1]->color);
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if(!flag)
			{
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && turnToMove == indexPlayer)
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
							turnToMove = turnToMove == 0 ? 1 : 0;
							continue;
						}
						if(board.cheackPawn(index))
							if(CheackOwner(index))
								board.SelectPiece(index);
						
						
					}
				}
				else if(turnToMove != indexPlayer)
				{
					std::shared_ptr<AI> tmp = std::static_pointer_cast<AI>(pl[turnToMove]);
					tmp->movePawn(board);
					pl[turnToMove] = tmp;
					flag = cheackWin();
					turnToMove = turnToMove == 0 ? 1 : 0;
				}
			}
			board.Draw(window);
			window.setView(view);
			window.display();
			window.clear(sf::Color(125,125,125));

		}
	}
}


