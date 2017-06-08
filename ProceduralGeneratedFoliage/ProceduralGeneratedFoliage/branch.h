#pragma once
#include "config.h"
class branch {
	float Rot;
	sf::Vector2f Pos;
	sf::Vector2f Size;
public:
	sf::RectangleShape Line;
	

	branch(sf::Vector2f branchSize, sf::Vector2f branchPos, float branchRot);
	void setBranchSize();
	void setBranchPos();
	void setBranchRot();
	void updateBranchSize(sf::Vector2f branchSize);
	void updateBranchPos(sf::Vector2f branchPos);
	void updateBranchRot(float branchRot);
};