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
sf::RenderWindow window(sf::VideoMode(800, 800), "Breakout");

int main() {
	
	Brick block;
	sf::Event event;
	float py = 700;
	float px = 400;
	block.init(200, 200);

	sf::RectangleShape paddle(sf::Vector2f(100.0f, 20.0f));
	paddle.setFillColor(sf::Color::Blue); 
	paddle.setPosition(px, py);

	

	while (window.isOpen()) {
		while (window.pollEvent(event)) {









			//render section------------------------------------------------------------

			window.clear();
			window.draw(paddle);
			block.DrawB();
			window.display();
		}
	}
}
void Brick::init(int x, int y) {
	xpos = x;
	ypos = y;
	width = 100;
	height = 30;
	isDead = false;
}

void Brick::DrawB() {
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(xpos, ypos);
	window.draw(rectangle);

}

