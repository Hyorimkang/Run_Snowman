#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Tree {
public:
	int x_ = 0;
	int y_ = 0;
	int treeSpeed_;
	Sprite tree_;
};