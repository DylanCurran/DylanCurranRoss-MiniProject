#ifndef BALL
#define BALL
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
class Ball
{
	
	sf::CircleShape m_circle;
	float const RADIUS = 5.f;
	float const PI = acos(1.0f);
	sf::Vector2f m_circlePos;
	float m_ballSpeed = 3.f;
	sf::Sprite m_ballSprite;
	std::vector<sf::Sprite*> m_multiBallSprite;
	sf::Texture m_ballTexture;
	float bonusSpeed = 5.f;
public:
	Ball();
	~Ball();
	void move();
	void render(sf::RenderWindow& window);
	void handleInputs();
	void setPosition();
	void collision();
	void update();

};

#endif // !BALL

