#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Snowman {
public:
	int x_ = 0;
	int y_ = 0;
	Sprite snowman_;
	bool isBottom = true;
	bool isJumping = false;
	const int gravity = 30;
};