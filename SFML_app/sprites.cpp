//
// Created by Karla Angélica Peña Guerra on 4/17/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
    sf::Texture texture;

    if (!texture.loadFromFile("spiral.png"))
    {
        cout << "Filed to load image" << endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(600,600);
    sprite.setPosition(600,600);
    bool animate;
    /*sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Green);*/
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type== sf::Event::KeyPressed){
                if (event.key.code==sf::Keyboard::Space) {
                    animate = !animate;
                }
            }
        }

        if (animate)
            sprite.rotate(.1);
        window.clear(Color(255,0,0));
        window.draw(sprite);
        window.display();
    }
    return 0;
}
