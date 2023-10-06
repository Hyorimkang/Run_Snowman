#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

#define WIDTH 1000
#define HEIGHT 500

class Snowman {
public:
	int x_;
	int y_;
	Sprite snowman_;
};

void Game() {
	Snowman snowman;

	//â �����
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
	//1�� ���� ó���ϴ� Ƚ�� ����
	window.setFramerateLimit(60);

	//�̹��� �ε�
	Texture background;
	Texture charactor;
	background.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");

	//Texture�� Sprite�� �����
	Sprite img_back = Sprite(background);
	snowman.snowman_ = Sprite(charactor);

	//����� ��ġ
	snowman.x_ = 10;
	snowman.y_ = 230;
	snowman.snowman_.setPosition(snowman.x_, snowman.y_);


	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//�������� x�� ������ �� â�� �ݾ������� 
			if (e.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(img_back);
		window.draw(snowman.snowman_);
		window.display();
	}

}


//Test ���� : main�� ���� �� �����ϱ�
int main() {
	Game();
}

