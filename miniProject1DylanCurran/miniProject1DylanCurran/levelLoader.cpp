#include "levelLoader.h"


void operator >> (const YAML::Node& ballNode, BallData& ball)
{
	ball.m_ballType = ballNode["type"].as<std::string>();
	ball.m_ballPos.x = ballNode["position"]["x"].as<float>();
	ball.m_ballPos.y = ballNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& invNode, InvaderData& inv)
{
	inv.m_invType = invNode["type"].as<std::string>();
	inv.m_invPos.x = invNode["position"]["x"].as<float>();
	inv.m_invPos.y = invNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& blockNode, BlockData& block)
{
	block.m_blockType = blockNode["type"].as<std::string>();
	block.m_blockPos.x = blockNode["position"]["x"].as<float>();
	block.m_blockPos.y = blockNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& playerNode, PlayerData& player)
{
	player.m_padPos.x = playerNode["position"]["x"].as<float>();
	player.m_padPos.y = playerNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& backNode, BackgroundData& background)
{
	background.m_fileName = backNode["file"].as<std::string>();
}

void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	levelNode["background"] >> level.m_background;
	levelNode["player"] >> level.m_player;

	const YAML::Node& ballsNode = levelNode["balls"].as<YAML::Node>();
	for (unsigned i = 0; i < ballsNode.size(); i++)
	{
		BallData ball;
		ballsNode[i] >> ball;
		level.m_ball.push_back(ball);
	}
	
	const YAML::Node& invsNode = levelNode["invaders"].as<YAML::Node>();
	for (unsigned j = 0; j < invsNode.size(); j++)
	{
		InvaderData invader;
		invsNode[j] >> invader;
		level.m_invader.push_back(invader);
	}

	const YAML::Node& blocksNode = levelNode["blocks"].as<YAML::Node>();
	for (unsigned k = 0; k < blocksNode.size(); k++)
	{
		BlockData block;
		blocksNode[k] >> block;
		level.m_block.push_back(block);
	}
}

bool LevelLoader::levelLoad(int number, LevelData & level)
{
	std::stringstream ss;
	ss << "ASSETS/Level/";
	ss << "level";
	ss << number;
	ss << ".yaml";
		
		
	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("file: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	return true;
}
