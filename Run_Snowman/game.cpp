#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

#define WIDTH 1000
#define HEIGHT 500

class Snowman {
public:
	int x_;
	int y_;
};

void Game() {
	Snowman snowman;

	//창 만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
	//1초 동안 처리하는 횟수 설정
	window.setFramerateLimit(60);

	//이미지 로드
	Texture background;
	Texture charactor;
	background.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");


	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록 
			if (e.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}

	return 0;
}


//Test 목적 : main과 연결 후 삭제하기
int main() {
	Game();
}

