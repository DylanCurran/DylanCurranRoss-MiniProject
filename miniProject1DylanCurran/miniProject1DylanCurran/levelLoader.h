#ifndef LEVELLOADER
#define LEVELLOADER

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "yaml-cpp\yaml.h"

/// <summary>
///  Struct for the player object
/// </summary>

struct PlayerData
{
	sf::Vector2f m_padPos;
};
struct BallData
{
	std::string m_ballType;
	sf::Vector2f m_ballPos;
};
struct InvaderData
{
	std::string m_invType;
	sf::Vector2f m_invPos;
};
struct BlockData
{
	std::string m_blockType;
	sf::Vector2f m_blockPos;
};
struct BackgroundData
{
	std::string m_fileName;
};
struct LevelData
{
	PlayerData m_player;
	std::vector<BallData> m_ball;
	std::vector<InvaderData> m_invader;
	std::vector<BlockData> m_block;
	BackgroundData m_background;
	
};
class LevelLoader
{

public:
	LevelLoader() = default;
	static bool levelLoad(int number, LevelData& level);
private:

};

#endif // !LEVELLOADER

