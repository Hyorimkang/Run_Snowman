#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

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
	RectangleShape snowman_;	//�����
};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);
	Clock clock;	//�ð������� ���� ��ü

	Snowman snowman;
	snowman.x_ = 30, snowman.y_ = 230;
	snowman.jumpHeight_ = 2.5f;
	snowman.jumpSpeed_ = 4.5f;
	snowman.isJumping_ = false;

	//â�����
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run_Snowman");
	//1�ʵ��� ó���ϴ� Ƚ��
	window.setFramerateLimit(10);

	//�̹����ε�
	backgound.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");

	//��� �̹��� ����
	game_bg.setTexture(backgound);
	game_bg.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));

	//snowman �̹��� ����
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

		//����
		if (snowman.isJumping_) {
			//����ð� ���
			float elapsed = clock.restart().asSeconds();
			//���� ���� ����
			snowman.jumpHeight_ -= snowman.jumpSpeed_ * elapsed;
			//���� �ö󰡱�
			snowman.snowman_.move(0, -snowman.jumpSpeed_ *elapsed);
			//���� ����
			if (snowman.jumpHeight_ <= 0) {
				snowman.isJumping_ = false;
				snowman.jumpHeight_ = 0.0f;
			}

		}
		else {
			snowman.y_ = snowman.snowman_.getPosition().y;
			//���� �ִ� ���ȸ� �߷� �ۿ��ϵ���
			if (snowman.y_<230) {
				float elapsed = clock.restart().asSeconds();
				//�������� �Ÿ�
				float fallDistance = 0.5f * snowman.gravity_ * elapsed * elapsed;
				//����������
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


//Test ���� : main�� ���� �� �����ϱ�
int main() {
	Game();
}

