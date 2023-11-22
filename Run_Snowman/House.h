#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class House {
public:
	int x_ = 0;
	int y_ = 0;
	Sprite house_;
	int houseSpeed_;
};