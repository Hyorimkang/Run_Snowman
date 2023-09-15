#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

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
	RectangleShape snowman_;	//눈사람
};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);
	Clock clock;	//시간측정을 위한 객체

	Snowman snowman;
	snowman.x_ = 30, snowman.y_ = 230;
	snowman.jumpHeight_ = 2.5f;
	snowman.jumpSpeed_ = 4.5f;
	snowman.isJumping_ = false;

	//창만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run_Snowman");
	//1초동안 처리하는 횟수
	window.setFramerateLimit(10);

	//이미지로드
	backgound.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");

	//배경 이미지 삽입
	game_bg.setTexture(backgound);
	game_bg.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));

	//snowman 이미지 삽입
	snowman.snowman_.setSize(Vector2f(100.0f, 150.0f));
	snowman.snowman_.setTexture(&charactor);
	snowman.snowman_.setPosition(snowman.x_, snowman.y_);


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
					snowman.snowman_.move(8, 0);
				}
				else if (e.key.code == Keyboard::Left) {
					snowman.snowman_.move(-8, 0);
				}
			}
		}

		cout << "isJumping " << snowman.isJumping_ << endl;
		cout << "jumpHeight_ " << snowman.jumpHeight_ << endl;
		cout << "y" << snowman.snowman_.getPosition().y << endl;

		//점프
		if (snowman.isJumping_) {
			//경과시간 계산
			float elapsed = clock.restart().asSeconds();
			//점프 높이 감소
			snowman.jumpHeight_ -= snowman.jumpSpeed_ * elapsed;
			//위로 올라가기
			snowman.snowman_.move(0, -snowman.jumpSpeed_ *elapsed);
			//점프 종료
			if (snowman.jumpHeight_ <= 0) {
				snowman.isJumping_ = false;
				snowman.jumpHeight_ = 0.0f;
			}

		}
		else {
			snowman.y_ = snowman.snowman_.getPosition().y;
			//땅에 있는 동안만 중력 작용하도록
			if (snowman.y_<230) {
				float elapsed = clock.restart().asSeconds();
				//내려가는 거리
				float fallDistance = 0.5f * snowman.gravity_ * elapsed * elapsed;
				//내려보내기
				snowman.snowman_.move(snowman.x_, fallDistance);
			}
			else {
				snowman.snowman_.setPosition(snowman.snowman_.getPosition().x, 230);
			}
		}

		window.clear();
		window.draw(game_bg);
		window.draw(snowman.snowman_);
		window.display();
	}
}


//Test 목적 : main과 연결 후 삭제하기
int main() {
	Game();
}

