#include <SFML/Graphics.hpp>
using namespace sf;


class Snowman {
public:
	int x_;		//위치
	int y_;
	float jumpHeight = 1.5f;  // 점프 높이
	float jumpSpeed = 4.5f;     // 점프 속도
	bool isJumping = false;     // 현재 점프 중인지 여부
};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);

	Snowman snowman;
	snowman.x_ = 1, snowman.y_ = 2;	//snowman 위치

	//창만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run_Snowman");

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

	//snowman 초기 위치 설정
	Vector2f initialPosition(30, 230);
	snowman_.setPosition(initialPosition);


	Clock clock;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		

		//space bar 누르면 isJumping 활성화
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			snowman.isJumping = true;
			clock.restart();
		}

		//점프모션
		if (snowman.isJumping) {
			float elapsedTime = clock.getElapsedTime().asSeconds();
			float jumpDistance = snowman.jumpSpeed * elapsedTime;

			if (jumpDistance <= snowman.jumpHeight) {
				snowman_.move(0.0f, -jumpDistance);
			}
			else {
				snowman.isJumping = false;
				clock.restart();
			}
		} 
		else {
			sf::Vector2f currentPosition = snowman_.getPosition();
			if (currentPosition.y < initialPosition.y) {
				// 중력 적용하여 떨어지기
				float elapsedTime = clock.getElapsedTime().asSeconds();
				float fallDistance = snowman.jumpSpeed * elapsedTime;
				snowman_.move(0.0f, fallDistance);
			}
			else {
				// 제자리로 돌아오면 초기 위치로 설정
				snowman_.setPosition(initialPosition);
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

