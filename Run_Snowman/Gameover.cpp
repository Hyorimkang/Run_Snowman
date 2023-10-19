#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#include "Gameover.h";
#include "Play.h";

#define WIDTH 1000
#define HEIGHT 500

class Gameover : public Play{
public:
	void gameover() {
		Texture background;
		Texture back;
		Texture restart;

		background.loadFromFile("img/game_over_bg.png");
		back.loadFromFile("img/btnmain.png");
		restart.loadFromFile("img/btnrestart.png");

		Sprite img_back = Sprite(background);
		Sprite btn_back = Sprite(back);
		Sprite btn_restart = Sprite(restart);

		btn_back.setPosition(300, 350);
		btn_restart.setPosition(400, 350);

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
					Vector2i mousePosition = Mouse::getPosition(window);
					if (btn_restart.getGlobalBounds().contains(Vector2f(mousePosition))) {
						Play p;
						p.Game();
					}
					else if (btn_back.getGlobalBounds().contains(Vector2f(mousePosition))) {
						main();
					}
				}
			}
			window.clear();
			window.draw(img_back);
			window.draw(btn_back);
			window.draw(btn_restart);
			window.display();
		}
	}
};