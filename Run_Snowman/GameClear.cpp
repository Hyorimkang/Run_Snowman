#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define WIDTH 1000
#define HEIGHT 500

class Gameclear : public Play{
public:
	void gameover() {
		Texture background;
		Texture back;
		background.loadFromFile("img/game_clear_bg.png");
		back.loadFromFile("img/btnmain.png");

		Sprite img_back = Sprite(background);
		Sprite btn_back = Sprite(back);

		btn_back.setPosition(370, 350);

		// 창만들기
		RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");

		while (window.isOpen()) {
			Event e;
			while (window.pollEvent(e))
			{
				//윈도우의 x를 눌렀을 때 창이 닫아지도록 
				if (e.type == Event::Closed)
					window.close();

				if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left) {
					Play p;
					p.Game();
				}
			}
			window.clear();
			window.draw(img_back);
			window.draw(btn_back);
			window.display();
		}
	}
};