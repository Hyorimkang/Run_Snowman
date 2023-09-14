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

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);

	Snowman snowman;
	snowman.x_ = 30, snowman.y_ = 230;
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


//Test ���� : main�� ���� �� �����ϱ�
int main() {
	Game();
}

