#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Gameclear : public Main, public Play{
public:
	void gameclear();
};