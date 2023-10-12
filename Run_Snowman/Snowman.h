#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

class Snowman {
public:
	int x_;
	int y_;
	Sprite snowman_;
	bool isBottom = true;
	bool isJumping = false;
	int gravity;
};