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
	//sf::Clock clock; //set up the clock (needed for game timing)
	const float FPS = 60.0f; //FPS
	window.setFramerateLimit(FPS); //set FPS
	
	Brick block;
	sf::Event event;
	float py = 700;
	float px = 400;
	
	block.init(200, 200);

	float bx = 450;
	float by = 650;
	float xVel = 5;
	float yVel = -5;
	sf::CircleShape ball(20); //sets radius of circle
	ball.setFillColor(sf::Color(200, 50, 50)); //numbers and color names
	ball.setPosition(bx, by); //position

	sf::RectangleShape paddle(sf::Vector2f(100.0f, 20.0f));
	paddle.setFillColor(sf::Color::Blue); 
	paddle.setPosition(px, py);
	

	

	while (window.isOpen()) {
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::EventType::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				paddle.move(-5, 0);
				px -= 5;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				paddle.move(5, 0);
				px += 5;
			}
			
			




			
		}
	
		
		if (bx < 0 || bx >800) {
			xVel *= -1;
		}
		if (by < 0 || by >800) {
			yVel *= -1;
		}

		if (by+20  > py && bx + 20 > px && bx < px + 100)
			yVel *= -1;

		
		bx += xVel;
		by += yVel;

		ball.setPosition(bx, by);


		//render section------------------------------------------------------------

		window.clear();
		window.draw(paddle);
		window.draw(ball);
		block.DrawB();
		window.display();
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
