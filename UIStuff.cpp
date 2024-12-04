// commit

#include "UIStuff.h"

void showWelcomeWindow() {
    sf::RenderWindow welcomeWindow(sf::VideoMode(800, 600), "Welcome to the Time Clock");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return;
    }


    sf::Text title("Welcome to the Time Clock", font, 30);
    title.setFillColor(sf::Color::White);
    title.setPosition(400 - title.getLocalBounds().width / 2, 50);

    sf::Text footer("Created by Oden Dillenkoffer, Markell Peterson, and Jaden Edgecombe", font, 20);
    footer.setFillColor(sf::Color::White);
    footer.setPosition(10, 560);

    sf::Text centerText("Press Any Button to Continue", font, 24);
    centerText.setFillColor(sf::Color::White);
    centerText.setPosition(400 - centerText.getLocalBounds().width / 2, 300);

    bool proceedToNext = false;

    while (welcomeWindow.isOpen()) {
        sf::Event event;
        while (welcomeWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                welcomeWindow.close();
            }
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                proceedToNext = true;
                welcomeWindow.close();
            }
        }

        welcomeWindow.clear(sf::Color::Black);
        welcomeWindow.draw(title);
        welcomeWindow.draw(footer);
        welcomeWindow.draw(centerText);
        welcomeWindow.display();
    }

    if (proceedToNext) {
        sf::RenderWindow blackWindow(sf::VideoMode(800, 600), "Base Window");
        while (blackWindow.isOpen()) {
            sf::Event event;
            while (blackWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    blackWindow.close();
                }
            }

            blackWindow.clear(sf::Color::Black);
            blackWindow.display();
        }
    }
}