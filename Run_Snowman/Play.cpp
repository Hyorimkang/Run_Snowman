#include <SFML/Graphics.hpp>
#include <iostream>

#include "Snowman.h"
#include "Tree.h"
#include "House.h"
#include "Play.h"
#include "Gameover.h"
#include "Gameclear.h"

using namespace std;
using namespace sf;

#define WIDTH 1000
#define HEIGHT 500

//���� ����
Snowman snowman;
Tree tree;
House house;


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

void Play::houseXY(int x, int y) {
	house.x_ = x;
	house.y_ = y;

	house.house_.setScale(0.8f, 0.6f);
	house.house_.setPosition(house.x_, house.y_);
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
	Texture obstacle;
	Texture end;
	background.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");
	obstacle.loadFromFile("img/tree.png");
	end.loadFromFile("img/house.png");

	//Texture�� Sprite�� �����
	Sprite img_back = Sprite(background);
	snowman.snowman_ = Sprite(charactor);
	tree.tree_ = Sprite(obstacle);
	house.house_ = Sprite(end);

	//����� ��ġ
	snowmanXY(30, 230);

	//���� ��ġ
	treeXY(1000, 300);

	//�� ��ġ
	houseXY(1100, 300);

	//���� ���ǵ�
	tree.treeSpeed_ = 10;
	//�� ���ǵ�
	house.houseSpeed_ = 10;

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
		cout << time << endl;

		//ȭ�鿡 ���� ����
		Font font;
		font.loadFromFile("C:/Users/PC/Downloads/�����δ�� Bold.ttf");

		Text text;
		text.setFont(font);
		text.setString("score : " + to_string(time));
		text.setCharacterSize(35);
		text.setFillColor(Color::Black);
		text.setPosition(400, 0);

		//TODO: ���� ������ house sprite�� ���
		if (time == 4) {
			
			//�� �����̱�
			if (house.x_ <= 0) house.x_ = WIDTH;
			else house.x_ -= house.houseSpeed_;

			houseXY(house.x_, 200);

			//���� �浹�� ���� Ŭ����
			if ((tree.tree_.getGlobalBounds()).intersects(snowman.snowman_.getGlobalBounds())) {
				Gameclear c;
				c.gameclear();
			}
		}
		else {
			//���� ������
			if (tree.x_ <= 0) tree.x_ = WIDTH;
			else tree.x_ -= tree.treeSpeed_;

			treeXY(tree.x_, 300);
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

		//���� �� ����� ��ġ ������
		snowmanXY(30, snowman.y_);

		

		//�浹�� ���� ����
		if ((tree.tree_.getGlobalBounds()).intersects(snowman.snowman_.getGlobalBounds())){
			Gameover over;
			over.gameover();
		}

		window.clear();
		window.draw(img_back);
		window.draw(snowman.snowman_);
		window.draw(tree.tree_);
		window.draw(house.house_);
		window.draw(text);
		window.display();

	}
}
