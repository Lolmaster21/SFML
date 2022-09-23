#include <SFML/Graphics.hpp>

class tree {
private:
	int xpos;
	int ypos;
	int size;
	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::RectangleShape rect4;
public:
	tree(int x, int y, int s); //constructor
	void draw(sf::RenderWindow& window);

};
tree::tree(int x, int y, int s) {
	xpos = x;
	ypos = y;
	size = s;
}

void tree::draw(sf::RenderWindow& window) {
	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos, ypos);
	rect.setPosition(140, 190);
	rect2.setPosition(340, 390);
	rect3.setPosition(540, 590);
	rect4.setPosition(740, 590);
	rect.setFillColor(sf::Color(100, 80, 0));
	rect.setSize(sf::Vector2f(20, 100));
	rect2.setFillColor(sf::Color(100, 80, 0));
	rect2.setSize(sf::Vector2f(20, 100));
	rect3.setFillColor(sf::Color(100, 80, 0));
	rect3.setSize(sf::Vector2f(20, 100));
	rect4.setFillColor(sf::Color(100, 80, 0));
	rect4.setSize(sf::Vector2f(20, 100));
	window.draw(circle);
	window.draw(rect);
	window.draw(rect2);
	window.draw(rect3);
	window.draw(rect4);

}
tree r1(100, 100, 50);
tree r2(300, 300, 50);
tree r3(500, 500, 50);
tree r4(700, 500, 50);





//class shrubs-------------------------------------------------------------------------------------------------------------------------------------------------
class shrub {
private:
	int xpos;
	int ypos;
	int size;
	sf::CircleShape circle;
	sf::RectangleShape rect;
public:
	shrub(int x, int y, int s); //constructor
	void draw(sf::RenderWindow& window);
};

shrub::shrub(int x, int y, int s) {
	xpos = x;
	ypos = y;
	size = s;
}

void shrub::draw(sf::RenderWindow& window) {
	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos, ypos);
	window.draw(circle);
}

//variablesssss
shrub t1(200, 200, 50);
shrub t2(250, 200, 50);
shrub t3(225, 160, 50);


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "shrubs"); //set up screen
	sf::CircleShape circle;
	sf::RectangleShape rect;



	while (window.isOpen())//GAME LOOP--------------------------------
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		//render section-------------------------------
		window.clear();
		t1.draw(window);
		t2.draw(window);
		t3.draw(window);
		r1.draw(window);
		r2.draw(window);
		r3.draw(window);
		r4.draw(window);
		
		
		window.display(); //flip the buffer

	}//end game loop-------------------------------------------------

	return 0;
} //end main
