//
// Created by marke on 12/2/2024.
//

#include "UIStuff.h"

MyWindow::MyWindow(int width, int height, const std::string& title)
        : window(sf::VideoMode(width, height), title) {}

void MyWindow::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void MyWindow::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void MyWindow::update() {

}

void MyWindow::render() {
    window.clear(sf::Color::Black);
    window.display();
}