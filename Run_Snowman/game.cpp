#include <SFML/Graphics.hpp>
using namespace sf;\

#define DIR_RIGHT 0

class Snowman {
public:
	int speed_; //�ӵ�
	int x_;		//��ġ
	int y_;
	int dir_;	//����

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
	RectangleShape snowman(Vector2f(100.0f, 150.0f));
	snowman.setTexture(&charactor);
	snowman.setPosition(30, 230);

	Snowman snowman_;
	snowman_.x_ = 1, snowman_.y_ = 2;	//snowman ��ġ
	snowman_.dir_ = DIR_RIGHT;			//snowman �̵� ����


	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();

		}
		window.clear();
		window.draw(game_bg);
		window.draw(snowman);
		window.display();
	}
	
}


//Test ���� : main�� ���� �� �����ϱ�
int main() {
	Game();
}

