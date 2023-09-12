#include <SFML/Graphics.hpp>
using namespace sf;

#define DIR_RIGHT	0
#define DIR_LEFT	1

class Snowman {
public:
	int x_;			   //��ġ
	int y_;
	int dir_;			//�̵� ����
	float jumpHeight_;  // ���� ����
	float jumpSpeed_;   // ���� �ӵ�
	bool isJumping_;    // ���� ���� ������ ����
	int gravity_;		//�߷�
	RectangleShape sprite_;	//�����
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

	//â�����
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run_Snowman");
	//1�ʵ��� ó���ϴ� Ƚ��
	window.setFramerateLimit(300);

	//�̹����ε�
	backgound.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");

	//��� �̹��� ����
	game_bg.setTexture(backgound);
	game_bg.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));

	//snowman �̹��� ����
	RectangleShape snowman_(Vector2f(100.0f, 150.0f));
	snowman_.setTexture(&charactor);
	snowman_.setPosition(30, 230);

	//snowman ���ƿ��� ��ġ ����
	snowman_.setPosition(snowman.x_* BLOCK_SIZE, snowman.y_*BLOCK_SIZE);


	Clock clock;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		//���� ����
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snowman.dir_ = DIR_RIGHT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snowman.dir_ = DIR_LEFT;
		}

		//�ٿ���� ������ �� ������
		if (snowman.dir_ == DIR_RIGHT && snowman.x_ < 900) {
			snowman.x_ += 10;
		}
		else if (snowman.dir_ == DIR_LEFT && snowman.x_ > 0){
			snowman.x_ -= 10;
		}


		//space bar ������ isJumping Ȱ��ȭ
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			snowman.isJumping_ = true;
			clock.restart();
		}

		if (snowman.isJumping_) {
			float elapsedTime = clock.getElapsedTime().asSeconds();	//���� ��� �ð�
			float jumpDistance = snowman.jumpSpeed_ * elapsedTime;	//���� �ð��� ���� �ö� ���� 

			//snowman ���� �ø��� 
			if (jumpDistance <= snowman.jumpHeight_) { 
				snowman_.move(0.0f, -jumpDistance);
			}
			//������ �������Ƿ� isJumping_ ��Ȱ��ȭ ��Ű��
			else {
				snowman.isJumping_ = false;
				clock.restart(); //clock �����
			}
		}
		else {  // snowman�� �������°� �ƴ� ���� ���� 
			Vector2f currentPosition = snowman_.getPosition();
			if (currentPosition.y < 230) {
				// �߷� �����Ͽ� ��������
				float elapsedTime = clock.getElapsedTime().asSeconds();
				float fallDistance = snowman.jumpSpeed_ * elapsedTime;
				snowman_.move(0.0f, fallDistance);
			}
			else {
				//��ġ ������Ʈ
				snowman_.setPosition(snowman.x_, snowman.y_);
			}
		}

		window.clear();
		window.draw(game_bg);
		window.draw(snowman_);
		window.display();
	}
}


//Test ���� : main�� ���� �� �����ϱ�
int main() {
	Game();
}

