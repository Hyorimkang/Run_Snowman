#include <SFML/Graphics.hpp>
#include <assert.h>
using namespace sf;


int main() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture texture;
	Sprite img_bg;
	Sprite game_bg;
	 
	//창만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
	 
	//파일 불러오기
	texture.loadFromFile("img/main_bg.png");

	//이미지 넣기
	img_bg.setTexture(texture);
	img_bg.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록 
			if (e.type == Event::Closed)
				window.close();

			//키 눌렀을 때 이벤트
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				// TODO : 키를 누르면 화면전환이 되도록 하기
				//배경이미지
				texture.loadFromFile("img/game_bg.png");

				//배경 이미지 삽입
				game_bg.setTexture(texture);
				game_bg.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));
			}
		}
	}
		window.clear();
		window.draw(img_bg);
		window.draw(game_bg);
		window.display();
}
