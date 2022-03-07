/*#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Memory Game", sf::Style::Close | sf::Style::Titlebar);
    sf::Texture backg;
    if (!backg.loadFromFile("C:\\tlo.jpg"))
    {
        //handling an error 
    }
    sf::Sprite final_bg;
    final_bg.setTexture(backg);
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    while (window.isOpen())
    {
        int margin_side = 340;
        int margin_top = 150;
        /*std::vector<sf::RectangleShape> cards(16, // num of elems
            sf::RectangleShape(sf::Vector2f(margin_side, margin_top))); 
        std::vector<Button> cards(16, Button("click", { 100,100 }, { 0,0 }, sf::Color::Green));
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(final_bg);
        for (int i = 0; i < 16; i++)
        {
            if (i % 4 == 0 && i != 0)
            {
                margin_side = 340;
                margin_top += 150;
                sf::Vector2f pos(margin_side, margin_top);
                cards[i].setFont(arial);
                cards[i].setPosition(pos);
            }
            else
            {
                sf::Vector2f pos(margin_side, margin_top);
                cards[i].setFont(arial);
                cards[i].setPosition(pos);
            }
            cards[i].drawTo(window);
            margin_side += 150;
        }
        window.display();
    }

    return 0;
}*/