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
	float jumpSpeed = 0.0f;
	float gravity = 0.5f;
	float jumpHeight = 1.5f;
};