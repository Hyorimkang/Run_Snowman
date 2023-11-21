#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "main.h"
#include "Gameover.h"
#include "Play.h"


using namespace std;
using namespace sf;

#define WIDTH 1000
#define HEIGHT 500

void Gameover::gameover() {
	Texture background;
	Texture back;
	Texture restart;

	background.loadFromFile("img/game_over_bg.png");
	back.loadFromFile("img/btnmain.png");
	restart.loadFromFile("img/btnrestart.png");

	Sprite img_back = Sprite(background);
	Sprite btn_back = Sprite(back);
	Sprite btn_restart = Sprite(restart);

	btn_back.setPosition(170, 300);
	btn_restart.setPosition(500, 300);

	// â�����
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//�������� x�� ������ �� â�� �ݾ������� 
			if (e.type == Event::Closed)
				window.close();
		}

		//��ư �̺�Ʈ
		if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left) {
			Vector2i mousePosition = Mouse::getPosition(window);
			if (btn_restart.getGlobalBounds().contains(Vector2f(mousePosition))) {
				Play p;
				p.game();
			}
			else if (btn_back.getGlobalBounds().contains(Vector2f(mousePosition))) {
				Main s;
				s.start();
			}
		}

		window.clear();
		window.draw(img_back);
		window.draw(btn_back);
		window.draw(btn_restart);
		window.display();
	}
}