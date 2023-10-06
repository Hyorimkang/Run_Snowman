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


	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//�������� x�� ������ �� â�� �ݾ������� 
			if (e.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}

	return 0;
}


//Test ���� : main�� ���� �� �����ϱ�
int main() {
	Game();
}

