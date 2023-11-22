#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 1000
#define HEIGHT 500


using namespace std;
using namespace sf;

class Play {
public:
	void snowmanXY(int x, int y);
	void treeXY(int x, int y);
	void houseXY(int x, int y);
	void game();
};