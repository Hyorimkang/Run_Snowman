#pragma once

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


//void Play::game() {
//	Snowman snowman;
//	Tree tree;
//
//	//â �����
//	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
//	//1�� ���� ó���ϴ� Ƚ�� ����
//	window.setFramerateLimit(60);
//
//	//�̹��� �ε�
//	Texture background;
//	Texture charactor;
//	Texture obstacle;
//	background.loadFromFile("img/game_bg.png");
//	charactor.loadFromFile("img/snowman.png");
//	obstacle.loadFromFile("img/tree.png");
//
//	//Texture�� Sprite�� �����
//	Sprite img_back = Sprite(background);
//	snowman.snowman_ = Sprite(charactor);
//	tree.tree_ = Sprite(obstacle);
//
//	//����� ��ġ
//	snowman.x_ = 10;
//	snowman.y_ = 230;
//	snowman.snowman_.setPosition(snowman.x_, snowman.y_);
//
//	//���� ��ġ
//	tree.x_ = 800;
//	tree.y_ = 230;
//	tree.tree_.setScale(0.9f, 0.8f);
//	tree.tree_.setPosition(tree.x_, tree.y_);
//	//���� ���ǵ�
//	tree.treeSpeed_ = 5;
//
//	while (window.isOpen()) {
//		Event e;
//		while (window.pollEvent(e))
//		{
//			//�������� x�� ������ �� â�� �ݾ������� 
//			if (e.type == Event::Closed)
//				window.close();
//		}
//
//		//spaceŰ�� ������ ����
//		if (Keyboard::isKeyPressed(Keyboard::Space))
//		{
//			//������ ������ ��Ȳ�� ��
//			if (snowman.isBottom && !snowman.isJumping)
//			{
//				snowman.isJumping = true;
//				snowman.isBottom = false;
//			}
//		}
//		//������ ��
//		if (snowman.isJumping) {
//			//�����ϸ� �߷¸�ŭ ������ (���� ������ y���� �����ϱ� ����
//			snowman.y_ -= snowman.gravity;
//		}
//		else {
//			snowman.y_ += snowman.gravity;
//		}
//
//		//��ġ �缳��
//		tree.tree_.setPosition(tree.x_, tree.y_);
//		snowman.snowman_.setPosition(snowman.x_, snowman.y_);
//
//		window.clear();
//		window.draw(img_back);
//		window.draw(snowman.snowman_);
//		window.draw(tree.tree_);
//		window.display();
//	}
//
//}

