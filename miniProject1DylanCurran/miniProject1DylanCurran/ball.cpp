#include "ball.h"

Ball::Ball()
{
	m_circlePos = { 390.f,490.f };
	m_circle.setPosition(m_circlePos);
	m_circle.setRadius(RADIUS);
	m_circle.setFillColor(sf::Color::Black);
}

Ball::~Ball()
{
}

void Ball::move()
{
}

void Ball::render(sf::RenderWindow & window)
{
	window.draw(m_circle);
}

void Ball::handleInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_ballSpeed = bonusSpeed;
	}
	else
	{
		m_ballSpeed = 3;
	}
}

void Ball::setPosition()
{
	m_circle.setPosition(m_circlePos);
}

void Ball::collision()
{
}

void Ball::update()
{
	m_circlePos.x += m_ballSpeed;
	m_circle.setPosition(m_circlePos);
}
