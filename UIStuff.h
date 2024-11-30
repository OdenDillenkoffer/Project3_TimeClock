//
// Created by marke on 12/2/2024.
//

#ifndef PROJECT3_TIMECLOCK_UISTUFF_H
#define PROJECT3_TIMECLOCK_UISTUFF_H

#include <SFML/Graphics.hpp>
using namespace std;

class MyWindow {
public:
    MyWindow(int width, int height, const std::string& title);
    void run();

private:
    sf::RenderWindow window;
    void processEvents();
    void update();
    void render();
};

#endif //PROJECT3_TIMECLOCK_UISTUFF_H
