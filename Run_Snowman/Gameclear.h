#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Gameclear : public Play, public Start{
public:
	void gameclear();
};