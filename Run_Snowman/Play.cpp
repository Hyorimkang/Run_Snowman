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

void Play::snowmanXY(int x, int y) {
	snowman.x_ = x;
	snowman.y_ = y;

	snowman.snowman_.setPosition(snowman.x_, snowman.y_);
}

void Play::treeXY(int x, int y) {
	tree.x_ = x;
	tree.y_ = y;

	tree.tree_.setScale(0.7f, 0.6f);
	tree.tree_.setPosition(tree.x_, tree.y_);
}

bool Play::isColliding(Sprite charactor, Sprite obstacle) {
	//�� sprite�� ���� ����
	FloatRect f1 = charactor.getGlobalBounds();
	FloatRect f2 = obstacle.getGlobalBounds();

	//�浹 ���� ��ȯ
	return f1.intersects(f2);
}

void Play::game() {
	
	//â �����
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
	//1�� ���� ó���ϴ� Ƚ�� ����
	window.setFramerateLimit(60);

	//�̹��� �ε�
	Texture background;
	Texture charactor;
	Texture obstacle;
	background.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");
	obstacle.loadFromFile("img/tree.png");

	//Texture�� Sprite�� �����
	Sprite img_back = Sprite(background);
	snowman.snowman_ = Sprite(charactor);
	tree.tree_ = Sprite(obstacle);

	//����� ��ġ
	snowmanXY(30, 230);

	//���� ��ġ
	treeXY(800, 300);

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

		snowmanXY(30, snowman.y_);

		//���� ������
		if (tree.x_ <= 0) tree.x_ = WIDTH;
		else tree.x_ -= tree.treeSpeed_;

		treeXY(tree.x_, 300);

		//�浹�� ���� ����
		if ((tree.tree_.getGlobalBounds()).intersects(snowman.snowman_.getGlobalBounds())){
			cout << "�浹" << endl;
			Gameover over;
			over.gameover();
		}
		window.clear();
		window.draw(img_back);
		window.draw(snowman.snowman_);
		window.draw(tree.tree_);
		window.display();

	}
}
