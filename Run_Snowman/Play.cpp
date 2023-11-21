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

//전역 변수
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
	//두 sprite의 겉의 범위
	FloatRect f1 = charactor.getGlobalBounds();
	FloatRect f2 = obstacle.getGlobalBounds();

	//충돌 여부 반환
	return f1.intersects(f2);
}

void Play::game() {
	
	//창 만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
	//1초 동안 처리하는 횟수 설정
	window.setFramerateLimit(60);

	//이미지 로드
	Texture background;
	Texture charactor;
	Texture obstacle;
	background.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");
	obstacle.loadFromFile("img/tree.png");

	//Texture를 Sprite로 만들기
	Sprite img_back = Sprite(background);
	snowman.snowman_ = Sprite(charactor);
	tree.tree_ = Sprite(obstacle);

	//눈사람 위치
	snowmanXY(30, 230);

	//나무 위치
	treeXY(800, 300);

	//나무 스피드
	tree.treeSpeed_ = 10;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록 
			if (e.type == Event::Closed)
				window.close();

			
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				if (snowman.isBottom && !snowman.isJumping) { //바닥에 있고 점프중이 아닐 때
					snowman.isJumping = true;
					snowman.isBottom = false;
				}
			}

			
		}
		//점프
		if (snowman.isJumping) {
			snowman.y_ -= snowman.gravity;
		}
		else {
			snowman.y_ += snowman.gravity;
		}

		//프레임 밖으로 안나가도록
		int test = HEIGHT - 230;

		if (snowman.y_ >= test) {
			snowman.y_ = test;
			snowman.isBottom = true;
		}
		if (snowman.y_ <= test - 230) snowman.isJumping = false;

		snowmanXY(30, snowman.y_);

		//나무 움직임
		if (tree.x_ <= 0) tree.x_ = WIDTH;
		else tree.x_ -= tree.treeSpeed_;

		treeXY(tree.x_, 300);

		//충돌시 게임 오버
		if ((tree.tree_.getGlobalBounds()).intersects(snowman.snowman_.getGlobalBounds())){
			cout << "충돌" << endl;
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
