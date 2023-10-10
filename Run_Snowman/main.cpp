#include <SFML/Graphics.hpp>
#include <assert.h>
using namespace sf;

#define WIDTH 1000
#define HEIGHT 500

int main() {
	// 창만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");

	Texture back;
	back.loadFromFile("img/main_bg.png");

	//이미지 넣기
	Sprite game_bg = Sprite(back);

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록 
			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left) {

			}
		}
		window.clear();
		window.draw(game_bg);
		window.display();
	}
		
}
