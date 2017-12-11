#include "invader.h"

Invader::Invader()
{
	m_invSize = { m_invWidth,m_invLength };
	m_invRectangle.setSize(m_invSize);
	m_invRectangle.setFillColor(sf::Color::Yellow);
	m_invRectangle.setOutlineColor(sf::Color::Cyan);
	m_invRectangle.setOutlineThickness(3.0f);
}

Invader::~Invader()
{
}

void Invader::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_invRectangle);
}

void Invader::setPosition(float num1, float num2)
{
	m_invPos = { 100 * num2,  num1 * 200 };
	m_invRectangle.setPosition(m_invPos);
}

void Invader::move()
{
	m_invPos.x += m_invSpeed;
	if (m_invPos.x <= 0 || m_invPos.x >= 800 - m_invWidth)
	{
		m_invSpeed = m_invSpeed * -1;
	}
	m_invRectangle.setPosition(m_invPos);
}
