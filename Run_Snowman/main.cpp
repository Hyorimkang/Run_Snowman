#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>
#include "Play.h";

using namespace sf;
using namespace std;

#define WIDTH 1000
#define HEIGHT 500

void main() {

	// 창만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");

	Texture background;
	Texture btn;
	background.loadFromFile("img/main_bg.png");
	btn.loadFromFile("img/btnstart.png");

	//이미지 넣기
	Sprite game_bg = Sprite(background);
	Sprite button_ = Sprite(btn);

	//이미지 위치
	button_.setPosition(370, 350);

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
		window.draw(game_bg);
		window.draw(button_);
		window.display();
	}
}

