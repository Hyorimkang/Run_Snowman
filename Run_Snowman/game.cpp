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
	const int BLOCK_SIZE = 50;
	const int G_WIDTH = WIDTH / BLOCK_SIZE;
	const int G_HEIGHT = HEIGHT / BLOCK_SIZE;

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
	snowman_.setPosition(snowman.x_* BLOCK_SIZE, snowman.y_*BLOCK_SIZE);


	Clock clock;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		//방향 설정
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snowman.dir_ = DIR_RIGHT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snowman.dir_ = DIR_LEFT;
		}

		//바운더리 밖으로 못 나가게
		if (snowman.dir_ == DIR_RIGHT && snowman.x_ < 900) {
			snowman.x_ += 10;
		}
		else if (snowman.dir_ == DIR_LEFT && snowman.x_ > 0){
			snowman.x_ -= 10;
		}


		//space bar 누르면 isJumping 활성화
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			snowman.isJumping_ = true;
			clock.restart();
		}

		if (snowman.isJumping_) {
			float elapsedTime = clock.getElapsedTime().asSeconds();	//현재 경과 시간
			float jumpDistance = snowman.jumpSpeed_ * elapsedTime;	//현재 시간에 따라 올라간 높이 

			//snowman 위로 올리기 
			if (jumpDistance <= snowman.jumpHeight_) { 
				snowman_.move(0.0f, -jumpDistance);
			}
			//점프가 끝났으므로 isJumping_ 비활성화 시키기
			else {
				snowman.isJumping_ = false;
				clock.restart(); //clock 재시작
			}
		}
		else {  // snowman이 점프상태가 아닐 때만 실행 
			Vector2f currentPosition = snowman_.getPosition();
			if (currentPosition.y < 230) {
				// 중력 적용하여 떨어지기
				float elapsedTime = clock.getElapsedTime().asSeconds();
				float fallDistance = snowman.jumpSpeed_ * elapsedTime;
				snowman_.move(0.0f, fallDistance);
			}
			else {
				//위치 업데이트
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

