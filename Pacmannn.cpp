//SFML C++ PACMAN pt 2
//created by Dr. Mo 11/21
//dynamicsofanasteroid.com

#include<iostream>
#include "SFML/Graphics.hpp"
using namespace std;

enum DIRECTIONS { LEFT, RIGHT, UP, DOWN }; //left is 0, right is 1, up is 2, down is 3
int radius = 35;
int main() {
    //game set up (you'll need these lines in every game)
    sf::RenderWindow screen(sf::VideoMode(800, 800), "breakout"); //set up screen
    sf::Event event; //set up event queue
    sf::Clock clock; //set up the clock (needed for game timing)
    const float FPS = 60.0f; //FPS
    screen.setFramerateLimit(FPS); //set FPS
    //load in images
    sf::Texture brick;
    brick.loadFromFile("brick.png");
    sf::Sprite wall;
    wall.setTexture(brick);
    sf::Texture pacman;
    pacman.loadFromFile("pacman.png");
    sf::IntRect pac(0, 0, 70, 70);
    sf::Sprite playerImg(pacman, pac);

    int map[10][10] = {
        1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,0,1,1,0,1,
        1,0,1,0,0,0,1,0,0,1,
        1,0,0,0,1,1,0,0,1,1,
        1,1,0,0,0,1,0,0,0,1,
        1,0,0,1,0,0,0,1,0,1,
        1,0,1,1,1,0,1,1,0,1,
        1,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1
    };

    //player setup
    int xpos = 85;
    int ypos = 85;
    int vx = 0;
    int vy = 0;
    int frameNum=0;
    int ticker{};
    int rowNum=0;
    sf::CircleShape player(radius);
    sf::CircleShape dot(radius);
    dot.setFillColor(sf::Color(255, 255, 255));
    player.setFillColor(sf::Color(250, 250, 0)); //using RGB value for color here (hex also works)
    player.setPosition(xpos, ypos); //top left "corner" of circle (not center!)
    bool keys[] = { false, false, false, false };



    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (screen.isOpen()) {//keep window open until user shuts it down

        while (screen.pollEvent(event)) { //look for events-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                screen.close();
            //KEYBOARD INPUT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                keys[LEFT] = true;
            }
            else keys[LEFT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                keys[RIGHT] = true;
            }
            else keys[RIGHT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                keys[UP] = true;
            }
            else keys[UP] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                keys[DOWN] = true;
            }
            else keys[DOWN] = false;




        }//end event loop---------------------------------------------------------------

         //move Mr. Pac
        if (keys[LEFT] == true)
            vx = -5;

        else if (keys[RIGHT] == true)
            vx = 5;

        else if (keys[UP] == true)
            vy = -5;

        else if (keys[DOWN] == true)
            vy = 5;


        else {
            vx = 0;
            vy = 0;
        }

        //check for right collision
        if (vx > 0 &&
            //check Top right corner
            ((map[(ypos) / 80]
                [(xpos + (radius * 2) + 5) / 80] == 1 ||
                //check BOTTOM right corner
                (map[(ypos + (radius * 2)) / 80]
                    [(xpos + (radius * 2) + 5) / 80]) == 1))) {
            vx = 0;
            cout << "Right  collision" << endl;

        }
        //left goes here
        if (vx < 0 &&
            //check Top left corner
            ((map[(ypos) / 80]
                [(xpos - 5) / 80] == 1 ||
                //check BOTTOM left corner
                (map[(ypos + (radius * 2)) / 80]
                    [(xpos -5) / 80]) == 1))) {
            vx = 0;
            cout << "Left collision" << endl;

        }
        //up collision
        if (vy < 0 &&
            //check Top left corner
            ((map[(ypos-5) / 80]
                [(xpos + (radius * 2)) / 80] == 1 ||
                //check BOTTOM left corner
                (map[(ypos-5) / 80]
                    [(xpos) / 80]) == 1))) {
            vy = 0;
            cout << "up collision" << endl;

        }
        //Bottom collision
        if (vy > 0 &&
            ((map[(ypos + (radius * 2) +5 ) / 80][(xpos) / 80] == 1) ||
                (map[(ypos + (radius * 2)+5) / 80]
                    [(xpos + (radius * 2)) / 80] == 1))) {//bottom collision
            vy = 0;
            cout << "bottom" << endl;

        }

        

       //update player
        xpos += vx;
        ypos += vy;
        player.setPosition(xpos, ypos);

        //animate player
        if (vx != 0 || vy != 0) {
            ticker += 1;
            if (ticker % 10 == 0)
                frameNum += 1;
            if (frameNum > 3)
                frameNum = 0;
        }

        
        pac = sf::IntRect(frameNum * 70, rowNum * 70, 68, 68);
        sf::Sprite playerImg(pacman, pac);
        playerImg.setPosition(xpos, ypos);



        //EAT DOTS
        if (map[ypos / 80][xpos / 80] == 0)
            map[ypos / 80][xpos / 80] = 20;

        //render section-----------------------------------------
        screen.clear(); //wipes screen, without this things smear

        //draw map
        for (int rows = 0; rows < 10; rows++)
            for (int cols = 0; cols < 10; cols++) {
                if (map[rows][cols] == 1) {
                    wall.setPosition(cols * 80, rows * 80);
                    screen.draw(wall);
                }
                if (map[rows][cols] == 0) {
                    dot.setPosition(cols * 80, rows * 80);
                    screen.draw(dot);
                }
            }

     
      


        screen.draw(playerImg); //draw player
        screen.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end of main
