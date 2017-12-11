#ifndef PLAYER
#define PLAYER
#include <SFML\Graphics.hpp>
#include <iostream>
class Player
{

public:

	Player();
	~Player();
	void render(sf::RenderWindow& t_window);
	void update();
	void handleInputs();
	void setPosition();
	void increaseSpeed();
	void decreaseSpeed();
	
private:
	sf::RectangleShape m_paddle;
	float const PADDLE_HEIGHT = 20.f;
	float m_paddleWidth = 100.f;
	float m_speed = 0;
	sf::Vector2f m_padPos;
	sf::Vector2f m_padSize;
	sf::Sprite m_padSprite;
	std::vector<sf::Sprite> m_padSpriteMain;
	sf::Texture m_padTexture;
	int m_lives = 3;

};

#endif // !PLAYER

