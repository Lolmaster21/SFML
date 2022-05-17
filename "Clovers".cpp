#include <SFML/Graphics.hpp>


class shamrock {
private:
	int xpos;
	int ypos;
	int size;
	sf::CircleShape circle;
	sf::RectangleShape rect;

public:
	shamrock(int x, int y, int s);
	void draw(sf::RenderWindow& window);








};
shamrock::shamrock(int x, int y, int s) {

	xpos = x;
	ypos = y;
	size = s;




}

void shamrock::draw(sf::RenderWindow& window) {
	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos, ypos);
	rect.setFillColor((sf::Color(0, 100, 0)));
	rect.setPosition(xpos, ypos+10);
	window.draw(circle);
	window.draw(rect);


}


int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Shamrocks");
	sf::CircleShape circle;
	sf::RectangleShape rect;
	//void draw::shamrock(int x, int y, int s);

	//instantiate your objects INSIDE MAIN!
	shamrock s1(100, 100, 50);
	shamrock s2(300, 300, 50);
	shamrock s3(500, 500, 50);
	while(true){
		//put a little game loop here
		s1.draw(window);
		s2.draw(window);
		s3.draw(window);


		window.display();
	}
}

