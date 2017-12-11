#ifndef BLOCKS
#define BLOCKS
#include <SFML\Graphics.hpp>
class Blocks
{
	sf::RectangleShape m_rectangle;
	float const m_width = 132.0f;
	float const m_length = 50.f;
	sf::Vector2f m_size;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
public:
	Blocks();
	~Blocks();
	void setPosition(int num1, int num2);
	void render(sf::RenderWindow & t_window);
	//void setPosition(int t_val1, int t_val2);


};

#endif // !BLOCKS

