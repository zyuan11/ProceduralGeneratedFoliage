#include "branch.h"

branch::branch(sf::Vector2f branchSize, sf::Vector2f branchPos, float branchRot, sf::Color branchColor) {
	Size = branchSize;
	Pos = branchPos;
	Rot = branchRot;
	Color = branchColor;
	setBranchSize();
	setBranchPos();
	setBranchRot();
	setBranchColor();
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

void branch::setBranchColor() {
	Line.setFillColor(Color);
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

