#include <SFML/Graphics.hpp>
#include <iostream>

#include "Snowman.h"
#include "Tree.h"
#include "Play.h"
#include "Gameover.h"

using namespace std;
using namespace sf;

#define WIDTH 1000
#define HEIGHT 500

//���� ����
Snowman snowman;
Tree tree;

//��ġ �缳�� �Լ�
void Snowman::snowmanXY(int x, int y) {
	snowman.x_ = x;
	snowman.y_ = y;

	snowman.snowman_.setPosition(snowman.x_, snowman.y_);
}

void Tree::treeXY(int x, int y) {
	tree.x_ = x;
	tree.y_ = y;

	tree.tree_.setScale(0.7f, 0.6f);
	tree.tree_.setPosition(tree.x_, tree.y_);
}

void Play::game() {
	Clock clock;
		
	//â �����
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
	//1�� ���� ó���ϴ� Ƚ�� ����
	window.setFramerateLimit(60);

	//�̹��� �ε�
	Texture background;
	Texture charactor;
	Texture obstacle1;
	background.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");
	obstacle1.loadFromFile("img/tree.png");

	//Texture�� Sprite�� �����
	Sprite img_back = Sprite(background);
	snowman.snowman_ = Sprite(charactor);
	tree.tree_ = Sprite(obstacle1);

	//����� ��ġ
	snowman.snowmanXY(30, 230);

	//���� ��ġ
	tree.treeXY(1000, 300);

	//���� ���ǵ�
	tree.treeSpeed_ = 10;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//�������� x�� ������ �� â�� �ݾ������� 
			if (e.type == Event::Closed)
				window.close();
			
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				if (snowman.isBottom && !snowman.isJumping) { //�ٴڿ� �ְ� �������� �ƴ� ��
					snowman.isJumping = true;
					snowman.isBottom = false;
				}
			}
		}

		//������ �� ����
		int time = static_cast<int>(clock.getElapsedTime().asSeconds());

		//ȭ�鿡 ���� ����
		Font font;
		font.loadFromFile("C:/Users/PC/Downloads/�����δ�� Bold.ttf");

		Text text;
		text.setFont(font);
		text.setString("score : " + to_string(time));
		text.setCharacterSize(35);
		text.setFillColor(Color::Black);
		text.setPosition(400, 0);
		
		//���� �ð� ������ ���� �ӵ� ��������
		if (time >= 10) {
			tree.treeSpeed_ = 13;
		}
		else if (time >= 15) {
			tree.treeSpeed_ = 17;
		}

		//���� �����̱�
		if (tree.x_ <= 0) tree.x_ = WIDTH;
		else tree.x_ -= tree.treeSpeed_;

		tree.treeXY(tree.x_, 300);

		//����
		if (snowman.isJumping) {
			snowman.y_ -= snowman.gravity;
		}
		else {
			snowman.y_ += snowman.gravity;
		}

		//������ ������ �ȳ�������
		int test = HEIGHT - 230;

		if (snowman.y_ >= test) {
			snowman.y_ = test;
			snowman.isBottom = true;
		}
		if (snowman.y_ <= test - 230) snowman.isJumping = false;

		//���� �� ����� ��ġ ������
		snowman.snowmanXY(30, snowman.y_);

		//��ֹ��� �浹�� ���� ����
		if ((tree.tree_.getGlobalBounds()).intersects(snowman.snowman_.getGlobalBounds())){
			Gameover over;
			over.gameover();
		}

		window.clear();
		window.draw(img_back);
		window.draw(snowman.snowman_);
		window.draw(tree.tree_);
		window.draw(text);
		window.display();

	}
}
