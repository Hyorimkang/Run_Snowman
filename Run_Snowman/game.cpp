#include <SFML/Graphics.hpp>
using namespace sf;

#define DIR_RIGHT 0

class Snowman {
public:
	int x_;			   //��ġ
	int y_;
	int dir_;			//�̵� ����
	float jumpHeight_;  // ���� ����
	float jumpSpeed_;   // ���� �ӵ�
	bool isJumping_;    // ���� ���� ������ ����
	RectangleShape sprite_;	//�����
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
	Vector2f initialPosition(30, 230);
	snowman_.setPosition(snowman.x_, snowman.y_);


	Clock clock;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		//���������� �����̱�
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snowman.x_ += 5;
			snowman.y_ = 230;
			snowman_.setPosition(snowman.x_, snowman.y_);
		}

		//�������� �����̱�
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snowman.x_ -= 5;
			snowman.y_ = 230;
			snowman_.setPosition(snowman.x_, snowman.y_);
		}

		//space bar ������ isJumping Ȱ��ȭ
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			snowman.isJumping_ = true;
			clock.restart();
		}

		//�������
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
				// �߷� �����Ͽ� ��������
				float elapsedTime = clock.getElapsedTime().asSeconds();
				float fallDistance = snowman.jumpSpeed_ * elapsedTime;
				snowman_.move(0.0f, fallDistance);
			}
			else {
				// ���ڸ��� ���ƿ��� �ʱ� ��ġ�� ����
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

