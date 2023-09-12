#include <SFML/Graphics.hpp>
using namespace sf;

#define DIR_RIGHT 0

class Snowman {
public:
	int x_;			   //위치
	int y_;
	int dir_;			//이동 방향
	float jumpHeight_;  // 점프 높이
	float jumpSpeed_;   // 점프 속도
	bool isJumping_;    // 현재 점프 중인지 여부
	RectangleShape sprite_;	//눈사람
};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;
	const int BLOCK_SIZE = 1;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);

	Snowman snowman;
	snowman.x_ = 1, snowman.y_ = 2;
	snowman.dir_ = DIR_RIGHT;
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
	snowman_.setPosition(30, 230);

	//snowman 돌아오는 위치 설정
	Vector2f initialPosition(30, 230);
	snowman_.setPosition(snowman.x_, snowman.y_);


	Clock clock;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		//오른쪽으로 움직이기
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snowman.x_ += 5;
			snowman.y_ = 230;
			snowman_.setPosition(snowman.x_, snowman.y_);
		}

		//왼쪽으로 움직이기
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snowman.x_ -= 5;
			snowman.y_ = 230;
			snowman_.setPosition(snowman.x_, snowman.y_);
		}

		//space bar 누르면 isJumping 활성화
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			snowman.isJumping_ = true;
			clock.restart();
		}

		//점프모션
		if (snowman.isJumping_) {
			float elapsedTime = clock.getElapsedTime().asSeconds();
			float jumpDistance = snowman.jumpSpeed_ * elapsedTime;

			if (jumpDistance <= snowman.jumpHeight_) {
				snowman_.move(0.0f, -jumpDistance);
			}
			else {
				snowman.isJumping_ = false;
				clock.restart();
			}
		} 
		else {
			Vector2f currentPosition = snowman_.getPosition();
			if (currentPosition.y < initialPosition.y) {
				// 중력 적용하여 떨어지기
				float elapsedTime = clock.getElapsedTime().asSeconds();
				float fallDistance = snowman.jumpSpeed_ * elapsedTime;
				snowman_.move(0.0f, fallDistance);
			}
			else {
				// 제자리로 돌아오면 초기 위치로 설정
				snowman_.setPosition(snowman.x_, snowman.y_);
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

