#pragma once
#include <SFML/Graphics.hpp>
#include "math.h"
#include <stdlib.h>
#include <time.h>

#include <map>
#include <string>
#include <stack>

#include <iostream>
using namespace std;

#define PI 3.14

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 1000

#define USERINTERFACE_WIDTH 400

#define INFO_SIZE sf::Vector2f(360, 60)
#define DENSITY_INFO_POS sf::Vector2f(30, 150)
#define DIRECTION_INFO_POS sf::Vector2f(30, 300)
#define COLOR_INFO_POS sf::Vector2f(30, 450)

#define BAR_COLOR sf::Color(51, 51, 51)
#define BAR_SIZE sf::Vector2f(340, 10)
#define DENSITY_BAR_POS sf::Vector2f(30, 230)
#define DIRECTION_BAR_POS sf::Vector2f(30, 380)
#define COLOR_BAR_POS sf::Vector2f(30, 530)

#define SELECT_COLOR sf::Color(140, 140, 140)
#define SELECT_OUTLINE_COLOR sf::Color(51, 51, 51)
#define SELECT_SIZE sf::Vector2f(20, 20)
#define SELECT_OUTLINE_THINKNESS 2
#define DENSITY_SELECT_POS sf::Vector2f(190, 225)
#define DIRECTION_SELECT_POS sf::Vector2f(190, 375)
#define COLOR_SELECT_POS sf::Vector2f(190, 525)



