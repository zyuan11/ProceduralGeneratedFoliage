#pragma once
#include <SFML/Graphics.hpp>
#include "math.h"
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

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

#define DENSTIY_SELECT_HEIGHT 225
#define DENSITY_SELECT_MEDIAM_POS sf::Vector2f(190, DENSTIY_SELECT_HEIGHT)
#define DENSITY_SELECT_LOW_POS sf::Vector2f(20, DENSTIY_SELECT_HEIGHT)
#define DENSITY_SELECT_HIGH_POS sf::Vector2f(360, DENSTIY_SELECT_HEIGHT)

#define DIRECTION_SELECT_HEIGHT 375
#define DIRECTION_SELECT_LEFT_POS sf::Vector2f(20, DIRECTION_SELECT_HEIGHT)
#define DIRECTION_SELECT_MIDDLE_POS sf::Vector2f(190, DIRECTION_SELECT_HEIGHT)
#define DIRECTION_SELECT_RIGHT_POS sf::Vector2f(360, DIRECTION_SELECT_HEIGHT)

#define COLOR_SELECT_HEIGHT 525
#define COLOR_SELECT_RED_POS sf::Vector2f(20, COLOR_SELECT_HEIGHT)
#define COLOR_SELECT_GREEN_POS sf::Vector2f(190, COLOR_SELECT_HEIGHT)
#define COLOR_SELECT_BLUE_POS sf::Vector2f(360, COLOR_SELECT_HEIGHT)


enum Arrow {GoLeft, Stay, GoRight};
enum Density {LOW = 0, MEDIAM = 1, HIGH = 2};
enum Direction {LEFT, MIDDLE, RIGHT};
enum Color {RED, GREEN, BLUE};




