#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#define SCREEN_W 800
#define SCREEN_H 600
#include "player.h"
#include "enemy.h"

bool collision_check(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh)
{

    if ( Ay+Ah < By ) return false; //if A is more to the left than B
    else if ( Ay > By+Bh ) return false; //if A is more to the right than B
    else if ( Ax+Aw < Bx ) return false; //if A is higher than B
    else if ( Ax > Bx+Bw ) return false; //if A is lower than B

    return true; //There is a collision because none of above returned false



}


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "SFML project!");
  //  sf::RenderWindow window2(sf::VideoMode(800, 600), "SFML works!");


    sf::Texture texture;
    if (!texture.loadFromFile("graphics/iamge.jpg"))
    {
        cout << "error image not found";
    }

    player boxone(0,300,284,177); // spawn x&y, object width and height
    // psprite must be set here, so that the texture pointer isnt lost in memory
    // perhaps a function could be called to do this? so that it doesnt take up a ton of room in the source code
    boxone.psprite.setTexture(texture);

    // it would be best if the image could be handled inside the object's class


    player box2(0,100,284,177);
  //  box2.psprite.setTexture(texture);
   box2.giveImage(texture);

   enemy first(0,0, 284,177, 3, 1);
   first.psprite.setTexture(texture);

    sf::View view1;


    // Main Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black); // window color
        //window.draw(shape);

        window.draw(boxone.psprite);
        boxone.updateMe();

        window.draw(box2.psprite);
        box2.updateMe();
        // all of the commented out functions below are called/handled by updateMe()
        //boxone.psprite.setPosition(sf::Vector2f(boxone.box_x, boxone.box_y));
        //sprite.setScale(sf::Vector2f(0.5f, 2.f));
        //boxone.drawMe();
        //boxone.movement();

        view1.setCenter(boxone.box_x, boxone.box_y);
        view1.setSize(sf::Vector2f(700, 300));


        window.draw(first.psprite);
        first.updateMe();


        window.display();
    } // end main loop

    return 0;
}
