#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000, 500), "Run Snowman"); //창만들기

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e))
		{
			//윈도우의 x를 눌렀을 때 창이 닫아지도록 
			if (e.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}

	return 0;
}