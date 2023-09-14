#include <SFML/Graphics.hpp>
using namespace sf;

#define DIR_RIGHT	0
#define DIR_LEFT	1

class Snowman {
public:
	int x_;			   //위치
	int y_;
	int dir_;			//이동 방향
	float jumpHeight_;  // 점프 높이
	float jumpSpeed_;   // 점프 속도
	bool isJumping_;    // 현재 점프 중인지 여부
	int gravity_;		//중력
	RectangleShape sprite_;	//눈사람
};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);

	Snowman snowman;
	snowman.x_ = 30, snowman.y_ = 230;
	snowman.jumpHeight_ = 2.5f;
	snowman.jumpSpeed_ = 4.5f;
	snowman.isJumping_ = false;

	//창만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run_Snowman");
	//1초동안 처리하는 횟수
	window.setFramerateLimit(300);

	//이미지로드
	backgound.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");

	//배경 이미지 삽입
	game_bg.setTexture(backgound);
	game_bg.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));

	//snowman 이미지 삽입
	RectangleShape snowman_(Vector2f(100.0f, 150.0f));
	snowman_.setTexture(&charactor);
	snowman_.setPosition(snowman.x_, snowman.y_);


	Clock clock;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Space && !snowman.isJumping_) {
					snowman.isJumping_ = true;
				}
				else if (e.key.code == Keyboard::Right) {
					snowman_.move(8, 0);
				}
				else if (e.key.code == Keyboard::Left) {
					snowman_.move(-8, 0);
				}
			}
		}


		

		window.clear();
		window.draw(game_bg);
		window.draw(snowman_);
		window.display();
	}
}


//Test 목적 : main과 연결 후 삭제하기
int main() {
	Game();
}

