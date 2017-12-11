// author Dylan Curran

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	for (int cell1 = 0; cell1 < M_BLOCK_CELL_1; cell1++)
	{
		for (int cell2 = 0; cell2 < M_BLOCK_CELL_2; cell2++)
		{
			m_blocks[cell1][cell2].setPosition(cell1, cell2);
			m_invader[cell1][cell2].setPosition(cell1, cell2);
		}
	}
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
//void Game::initialiseBlocks()
//{
//	for (int index1 = 0; index1 < M_BLOCK_CELL_1; index1++)
//	{
//		for (int index2 = 0; index2 < M_BLOCK_CELL_2; index2++)
//		{
//			m_blocks[index1][index2].
//		}
//	}
//}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				
				m_player.handleInputs();
			}
			else
			{
				
				m_player.handleInputs();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_ball.handleInputs();
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	m_player.update();
	for (int cell1 = 0; cell1 < M_BLOCK_CELL_1; cell1++)
	{
		for (int cell2 = 0; cell2 < M_BLOCK_CELL_2; cell2++)
		{
			
			m_invader[cell1][cell2].move();
		}
	}
	
	m_player.setPosition();
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	for (int cell1 = 0; cell1 < M_BLOCK_CELL_1; cell1++)
	{
		for (int cell2 = 0; cell2 < M_BLOCK_CELL_2; cell2++)
		{
			m_blocks[cell1][cell2].render(m_window);
			m_invader[cell1][cell2].render(m_window);
		}
		m_player.render(m_window);
		m_ball.render(m_window);
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>


/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>

