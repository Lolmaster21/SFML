#include <SFML/Graphics.hpp>
int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML")
		;
	sf::CircleShape circle;
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		circle.setRadius(rand()%50);
		circle.setFillColor(sf::Color(rand() % 250, rand() % 152, rand() % 24));
		circle.setPosition(rand()%1000,rand()%1000);

		window.draw(circle);
		window.display();
	}

	return 0;
}
