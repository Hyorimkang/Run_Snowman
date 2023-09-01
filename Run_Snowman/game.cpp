#include <SFML/Graphics.hpp>
using namespace sf;

#define DIR_RIGHT 0
#define DIR_LEFT 1

class Snowman {
public:
	int speed_; //�ӵ�
	int x_;		//��ġ
	int y_;
	int dir_;	//����

	//�ӵ�����
	void Move() {
		x_ += speed_;
	}
};

void Game() {
	const int WIDTH = 1000;
	const int HEIGHT = 500;

	Texture backgound;
	Texture charactor;
	Sprite game_bg(backgound);

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

	Snowman snowman;
	snowman.x_ = 1, snowman.y_ = 2;	//snowman ��ġ
	snowman.dir_;					//snowman �̵� ����
	//snowman.speed_ = 3;				//snowman �ӵ�


	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();

		}

		//Ű���� ���ÿ� ó������ �ʵ���
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snowman.dir_ = DIR_RIGHT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snowman.dir_ = DIR_LEFT;
		}

		//Ű���� ������ �����̱�
		/*if (snowman.dir_ == DIR_RIGHT) {
			snowman.x_++;
		}
		else if (snowman.dir_ == DIR_LEFT) {
			snowman.x_--;
		}*/
		

		window.clear();
		window.draw(game_bg);
		//snowman.setPosition(snowman_.x_, snowman_.y_); // �������� ��ġ ������Ʈ
		window.draw(snowman_);
		window.display();
	}
	
}


//Test ���� : main�� ���� �� �����ϱ�
int main() {
	Game();
}

