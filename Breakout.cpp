#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
class Brick {
private:
	int width;
	int height;
	int xpos;
	int ypos;
	bool isDead;

public:
	void init(int x, int y);
	void DrawB();


};

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 800), "Breakout");

	while (true) {

		window.display();
	}
}
void Brick:: init(int x, int y) {
	xpos = x;
	ypos = y;
	width = 100;
	height = 30;
	isDead = false;
}

void Brick::DrawB() {


}

