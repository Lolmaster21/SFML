#include"GameObject.h"
#include<SFML/Graphics.hpp>

void star::draw(sf::RenderWindow& window) { //passes a POINTER to the gamescreen
    sf::CircleShape triangle1(30, 3);
    triangle1.setFillColor(sf::Color(0, 200, 255));
    triangle1.setPosition(xpos, ypos);
    window.draw(triangle1);//draw to gamescreen

    sf::CircleShape triangle2(30, 3);
    triangle2.setFillColor(sf::Color(200, 200, 255));
    triangle2.setPosition(xpos + 40, ypos - 15);
    triangle2.rotate(60); //twist to make star shape
    window.draw(triangle2);
}

void duck::draw(sf::RenderWindow& window) {
    //body
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(255, 255, 0));
    shape.setPosition(xpos, ypos);
    
    //Beak
    sf::CircleShape triangle1(30, 3);
    triangle1.setFillColor(sf::Color(0, 0, 255));
    triangle1.setPosition(xpos-25, ypos+10);
    triangle1.rotate(27.f);
    window.draw(triangle1);//draw to gamescreen

    //eye
    sf::CircleShape shape1(10);
    shape1.setFillColor(sf::Color(0, 0, 0));
    shape1.setPosition(xpos+25, ypos+15);
        
    //drawing

    window.draw(shape);//draw to gamescreen
    window.draw(shape1);
    window.draw(triangle1);




    //can you complete this? make a duck draw to the screen!
    
}
