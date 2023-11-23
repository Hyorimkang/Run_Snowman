#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Tree {
public:
	//¸â¹öº¯¼ö
	int x_ = 0;
	int y_ = 0;
	int treeSpeed_;
	Sprite tree_;
	//¸â¹öÇÔ¼ö
	void treeXY(int x, int y);
};