#include "blocks.h"

Blocks::Blocks()
{
	m_size = { m_width,m_length };
	m_rectangle.setSize(m_size);
	m_rectangle.setFillColor(sf::Color::Green);
	m_rectangle.setOutlineColor(sf::Color::Red);
	m_rectangle.setOutlineThickness(3.0f);
	
	
}

Blocks::~Blocks()
{
}

void Blocks::setPosition(int num1, int num2)
{
	m_rectangle.setPosition( num2 * m_width, 100 + 200 * num1);
}

void Blocks::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_rectangle);
}
