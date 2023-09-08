#include <SFML/Graphics.hpp>
using namespace sf;


class Snowman {
public:
	int x_;		//��ġ
	int y_;
	float jumpHeight = 1.5f;  // ���� ����
	float jumpSpeed = 4.5f;     // ���� �ӵ�
	bool isJumping = false;     // ���� ���� ������ ����
};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);

	Snowman snowman;
	snowman.x_ = 1, snowman.y_ = 2;	//snowman ��ġ

	//â�����
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run_Snowman");

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

	//snowman �ʱ� ��ġ ����
	Vector2f initialPosition(30, 230);
	snowman_.setPosition(initialPosition);


	Clock clock;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		

		//space bar ������ isJumping Ȱ��ȭ
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			snowman.isJumping = true;
			clock.restart();
		}

		//�������
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
				// �߷� �����Ͽ� ��������
				float elapsedTime = clock.getElapsedTime().asSeconds();
				float fallDistance = snowman.jumpSpeed * elapsedTime;
				snowman_.move(0.0f, fallDistance);
			}
			else {
				// ���ڸ��� ���ƿ��� �ʱ� ��ġ�� ����
				snowman_.setPosition(initialPosition);
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

