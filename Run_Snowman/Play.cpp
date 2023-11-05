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

	tree.tree_.setScale(0.9f, 0.8f);
	tree.tree_.setPosition(tree.x_, tree.y_);
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
	snowmanXY(10, 230);

	//나무 위치
	treeXY(800, 230);

	//나무 스피드
	tree.treeSpeed_ = 5;

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록 
			if (e.type == Event::Closed)
				window.close();
		}
		//위치 재설정
		tree.tree_.setPosition(tree.x_, tree.y_);
		snowman.snowman_.setPosition(snowman.x_, snowman.y_);

		window.clear();
		window.draw(img_back);
		window.draw(snowman.snowman_);
		window.draw(tree.tree_);
		window.display();

	}


	

}
