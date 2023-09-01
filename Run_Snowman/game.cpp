#include <SFML/Graphics.hpp>
using namespace sf;\

#define DIR_RIGHT 0

class Snowman {
public:
	int speed_; //속도
	int x_;		//위치
	int y_;
	int dir_;	//방향

};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);

	//창만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run_Snowman");

	//이미지로드
	backgound.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");

	//배경 이미지 삽입
	game_bg.setTexture(backgound);
	game_bg.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));

	//snowman 이미지 삽입
	RectangleShape snowman(Vector2f(100.0f, 150.0f));
	snowman.setTexture(&charactor);
	snowman.setPosition(30, 230);

	Snowman snowman_;
	snowman_.x_ = 1, snowman_.y_ = 2;	//snowman 위치
	snowman_.dir_ = DIR_RIGHT;			//snowman 이동 방향


	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();

		}
		window.clear();
		window.draw(game_bg);
		window.draw(snowman);
		window.display();
	}
	
}


//Test 목적 : main과 연결 후 삭제하기
int main() {
	Game();
}

