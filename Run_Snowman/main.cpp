#include <SFML/Graphics.hpp>
#include <assert.h>
using namespace sf;



int main() {
	Texture texture;
	Sprite img_bg;
	RectangleShape btn;
	btn.setPosition(500, 300);
	btn.setFillColor(Color::White);
	btn.setOutlineColor(Color::Black);
	btn.setOutlineThickness(10);
	 
	//창만들기
	RenderWindow window(VideoMode(1000, 500), "Run Snowman");
	 
	//파일 불러오기
	texture.loadFromFile("img/main_bg.png");

	//이미지 넣기
	img_bg.setTexture(texture);
	img_bg.setTextureRect(IntRect(0, 0, 1000, 500));

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록 
			if (e.type == Event::Closed)
				window.close();

			//버튼 이미지

		}
		window.clear();
		window.draw(img_bg);
		window.draw(btn);
		window.display();
	}

	return 0;
}