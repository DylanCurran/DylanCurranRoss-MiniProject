#include "player.h"

Player::Player()
{
	m_padPos = { 400.f,500.f };
	m_padSize = { m_paddleWidth,PADDLE_HEIGHT };
	m_paddle.setSize(m_padSize);
	m_paddle.setFillColor(sf::Color::Blue);
	m_paddle.setOutlineColor(sf::Color::Red);
	m_paddle.setOutlineThickness(3.0f);
	m_paddle.setPosition(m_padPos);
}

Player::~Player()
{
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_paddle);
}

void Player::update()
{
	/*initSprites(sf::Vector2f(m_tankBase.getPosition().x + cos(m_rotation * DEG_TO_RAD) * m_speed * (dt / 1000),
		m_tankBase.getPosition().y + sin(m_rotation * DEG_TO_RAD) * m_speed * (dt / 1000)));
	m_tankBase.setRotation(m_rotation);
	m_turret.setRotation(m_turretRotation + m_rotation);*/
	m_padPos.x += m_speed ;// (dt / 1000);
	m_paddle.setPosition(m_padPos);
	std::cout << m_speed << std::endl;
}

void Player::handleInputs()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			decreaseSpeed();
		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			increaseSpeed();
		}
	else
	{
		m_speed = 0;
	}
}

void Player::setPosition()
{
	m_paddle.setPosition(m_padPos);
	
}

void Player::increaseSpeed()
{
	m_speed = 5;
}

void Player::decreaseSpeed()
{
	m_speed = -5;
}
