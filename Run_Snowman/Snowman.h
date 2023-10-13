#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Snowman {
public:
	int x_;
	int y_;
	Sprite snowman_;
	bool isBottom = true;
	bool isJumping = false;
	int gravity;
};