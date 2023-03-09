#include <SFML/Graphics.hpp>


//-------------------------------------------------------------------------------
//Player input
enum DIRECTIONS { LEFT, RIGHT}; //left is 0, right is 1

bool keys[] = { false, false, false, false };



class brick {
private:
	int xpos;
	int ypos;
	sf::RectangleShape rect;
public:
	brick(int x, int y); //constructor
	void draw(sf::RenderWindow& window);
};

brick::brick(int x, int y) {
	xpos = x;
	ypos = y;

}

void brick::draw(sf::RenderWindow& window) {
	rect.setSize(sf::Vector2f(100, 50));
	rect.setFillColor((sf::Color(0, 200, 0)));
	rect.setPosition(xpos, ypos);
	window.draw(rect);
}

class ball {
private:
	int xpos;
	int ypos;
	sf::CircleShape shape;

public:
	ball(int x, int y);
	void draw(sf::RenderWindow& window);
	void move(sf::RenderWindow& window);
};

ball::ball(int x, int y) {
	xpos = x;
	ypos = y;

}
void ball::draw(sf::RenderWindow& window) {
	sf::CircleShape shape(25);

	// set the shape color to green
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setPosition(xpos, ypos);

	window.draw(shape);
}

void ball::move(sf::RenderWindow& window) {	
	
	ypos += 1;

}

//----------------------------------------------------------------------------

//instantiate some bricks

brick b1(0, 100);
brick b2(105, 100);
brick b3(210, 100);
brick b4(315, 100);
brick b5(420, 100);
brick b6(525, 100);
brick b7(630, 100);
brick b8(735, 100);
ball v1(400, 400);

int main()
{
	//create a bunch of bricks at once
	brick* BrickBox[40]; //An array of brick ADDRESSESS
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			BrickBox[i] = new brick(100 * i, 200);
		}
	}


	sf::RenderWindow window(sf::VideoMode(800, 800), "Breakout"); //set up screen
	sf::RectangleShape rect;
	sf::CircleShape shape;

	while (window.isOpen())//GAME LOOP--------------------------------
	{
		//input section--------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		//physics section------------------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			keys[LEFT] = true;
		}
		else keys[LEFT] = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			keys[RIGHT] = true;
		}
		else keys[RIGHT] = false;


		//render section-------------------------------
		window.clear();

		//draw bricks
		for (int i = 0; i < 10; i++) {
			BrickBox[i]->draw(window);
		}

		v1.draw(window);
		v1.move(window);
		window.display(); //flip the buffer

	}//end game loop-------------------------------------------------

	return 0;
} //end main
