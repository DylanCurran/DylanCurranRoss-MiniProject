// author Dylan Curran
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "blocks.h"
#include "levelLoader.h"
#include "player.h"
#include "invader.h"
#include "ball.h"
class Game
{
public:
	Game();
	~Game();
	static int const M_BLOCK_CELL_1 = 2;
	static int const M_BLOCK_CELL_2 = 6;
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	//void initialiseBlocks();
	Blocks m_blocks[M_BLOCK_CELL_1][M_BLOCK_CELL_2];
	Invader m_invader[M_BLOCK_CELL_1][M_BLOCK_CELL_2];
	Player m_player;
	Ball m_ball;
private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME

