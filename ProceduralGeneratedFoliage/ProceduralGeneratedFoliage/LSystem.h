#pragma once
#include "config.h"

class LSystem {
	string axiom;
	std::map <char, string> Rules;
	int height;
public:
	void InitalizeLSystem(string axiom_i, int height_i);
	void InitalizeRules();
	string Generate();
};