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

//위치 재설정 함수
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
		
	//창 만들기
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Run Snowman");
	//1초 동안 처리하는 횟수 설정
	window.setFramerateLimit(60);

	//이미지 로드
	Texture background;
	Texture charactor;
	Texture obstacle1;
	background.loadFromFile("img/game_bg.png");
	charactor.loadFromFile("img/snowman.png");
	obstacle1.loadFromFile("img/tree.png");

	//Texture를 Sprite로 만들기
	Sprite img_back = Sprite(background);
	snowman.snowman_ = Sprite(charactor);
	tree.tree_ = Sprite(obstacle1);

	//눈사람 위치
	snowman.snowmanXY(30, 230);

	//나무 위치
	tree.treeXY(1000, 300);

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

		//정수로 초 보기
		int time = static_cast<int>(clock.getElapsedTime().asSeconds());

		//화면에 점수 띄우기
		Font font;
		font.loadFromFile("C:/Users/PC/Downloads/땅스부대찌개 Bold.ttf");

		Text text;
		text.setFont(font);
		text.setString("score : " + to_string(time));
		text.setCharacterSize(35);
		text.setFillColor(Color::Black);
		text.setPosition(400, 0);
		
		//일정 시간 지나면 나무 속도 빨라지기
		if (time >= 10) {
			tree.treeSpeed_ = 13;
		}
		else if (time >= 15) {
			tree.treeSpeed_ = 17;
		}

		//나무 움직이기
		if (tree.x_ <= 0) tree.x_ = WIDTH;
		else tree.x_ -= tree.treeSpeed_;

		tree.treeXY(tree.x_, 300);

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

		//점프 후 눈사람 위치 재정의
		snowman.snowmanXY(30, snowman.y_);

		//장애물과 충돌시 게임 오버
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
