#ifndef INVADER
#define INVADER
#include <SFML\Graphics.hpp>
#include <iostream>
class Invader
{
private:
	sf::RectangleShape m_invRectangle;
	sf::Texture m_invTexture;
	sf::Sprite m_invSprite;
	float const m_invWidth = 75;
	float const m_invLength = 50;
	sf::Vector2f m_invSize;
	sf::Vector2f m_invPos;
	float m_invSpeed = 2.5f;

public:
	static int const M_CELL_1 = 2;
	static int const M_CELL_2 = 6;
	Invader();
	~Invader();
	void render(sf::RenderWindow& t_window);
	void setPosition(float num1, float num2);
	void move();


};

#endif // !INVADER

