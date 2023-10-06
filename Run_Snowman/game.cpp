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

class Tree {
public:
	int x_;
	int y_;
	int treeSpeed_;
	Sprite tree_;
};

void Game() {
	Snowman snowman;
	Tree tree;

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
	snowman.x_ = 10;
	snowman.y_ = 230;
	snowman.snowman_.setPosition(snowman.x_, snowman.y_);

	//나무 위치
	tree.x_ = 800;
	tree.y_ = 230;
	tree.tree_.setScale(0.9f, 0.8f);
	tree.tree_.setPosition(tree.x_, tree.y_);
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
		window.clear();
		window.draw(img_back);
		window.draw(snowman.snowman_);
		window.draw(tree.tree_);
		window.display();
	}

}


//Test 목적 : main과 연결 후 삭제하기
int main() {
	Game();
}

