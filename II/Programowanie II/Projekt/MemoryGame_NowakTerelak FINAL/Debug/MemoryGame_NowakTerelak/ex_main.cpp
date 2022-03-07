/*#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "TextBox.h"

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
    sf::RectangleShape title(sf::Vector2f(250, 100));   //rozmiar loga
    title.setPosition(sf::Vector2f(500, 500));  //pozycja loga
    title.setFillColor(sf::Color::Black);   //stworzy sie sf::sprite z tekstura

    Textbox test(25, sf::Color::White, false);
    test.setFont(arial);
    test.setPosition({ 100,100 });
    test.setLimit(true, 10);

    while (window.isOpen())
    {
        window.clear();
        sf::Event Event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            test.setSelected(true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            test.setSelected(false);
        }

        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
            case sf::Event::MouseMoved:
                //TODO
            case sf::Event::TextEntered: //textbox
                test.typedOn(Event);
            }
        }
        window.draw(final_bg);
        window.draw(title);
        test.drawTo(window);
        window.display();
    }

    return 0;
}*/