#include "branch.h"

branch::branch(sf::Vector2f branchSize, sf::Vector2f branchPos, float branchRot) {
	Size = branchSize;
	Pos = branchPos;
	Rot = branchRot;
	setBranchSize();
	setBranchPos();
	setBranchRot();
}

void branch::setBranchSize() {
	Line.setSize(Size);
}

void branch::setBranchPos() {
	Line.setPosition(Pos);
}

void branch::setBranchRot() {
	Line.setRotation(Rot);
}

void branch::updateBranchSize(sf::Vector2f branchSize) {
	Size = branchSize;
	setBranchSize();
}
void branch::updateBranchPos(sf::Vector2f branchPos) {
	Pos = branchPos;
	setBranchPos();
}
void branch::updateBranchRot(float branchRot) {
	Rot = branchRot;
	setBranchRot();
}

