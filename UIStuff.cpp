#include "UIStuff.h"
#include <iostream>
#include <unordered_map>

void showWelcomeWindow() {
    sf::RenderWindow welcomeWindow(sf::VideoMode(1024, 768), "Welcome to the Time Clock", sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font.\n";
        return;
    }

    sf::Text title("Welcome to the Time Clock", font, 50);
    title.setFillColor(sf::Color::White);
    title.setPosition((1024 - title.getLocalBounds().width) / 2, 100);

    sf::Text footer("Created by Oden Dillenkoffer, Markell Peterson, and Jaden Edgecombe", font, 20);
    footer.setFillColor(sf::Color::White);
    footer.setPosition(20, 720);

    sf::Text centerText("Press Any Button to Continue", font, 30);
    centerText.setFillColor(sf::Color(180, 180, 180));
    centerText.setPosition((1024 - centerText.getLocalBounds().width) / 2, 500);

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

        welcomeWindow.clear(sf::Color(40, 44, 52));
        welcomeWindow.draw(title);
        welcomeWindow.draw(footer);
        welcomeWindow.draw(centerText);
        welcomeWindow.display();
    }


}

void showUserInputPage(int& algorithmChoice) {
    sf::RenderWindow inputWindow(sf::VideoMode(1000, 700), "User Input - Choose Optimization Algorithm");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font.\n";
        return;
    }

    sf::Text title("Choose an Optimization Algorithm", font, 36);
    title.setFillColor(sf::Color::White);
    title.setPosition(500 - title.getLocalBounds().width / 2, 100);

    sf::Text option1("1. A* Algorithm", font, 30);
    option1.setFillColor(sf::Color::White);
    option1.setPosition(400, 200);

    sf::Text option2("2. Dijkstra's Algorithm", font, 30);
    option2.setFillColor(sf::Color::White);
    option2.setPosition(400, 300);

    sf::Text prompt("Press 1 or 2 to choose:", font, 24);
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(500 - prompt.getLocalBounds().width / 2, 500);

    while (inputWindow.isOpen()) {
        sf::Event event;
        while (inputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                inputWindow.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    algorithmChoice = 1;
                    inputWindow.close();
                } else if (event.key.code == sf::Keyboard::Num2) {
                    algorithmChoice = 2;
                    inputWindow.close();
                }
            }
        }

        inputWindow.clear(sf::Color::Black);
        inputWindow.draw(title);
        inputWindow.draw(option1);
        inputWindow.draw(option2);
        inputWindow.draw(prompt);
        inputWindow.display();
    }
}



void showTaskGraphPage(const std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph) {
    sf::RenderWindow graphWindow(sf::VideoMode(1200, 800), "Task Graph - Worker Schedule");
    sf::Font font;

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font.\n";
        return;
    }

    float scrollOffset = 0;
    const float scrollSpeed = 20.0f;
    const float maxScrollOffset = 2000.0f;

    sf::RectangleShape scrollbar(sf::Vector2f(20, 800));
    scrollbar.setFillColor(sf::Color(100, 100, 100));
    scrollbar.setPosition(1180, 0);

    float scrollbarHeight = (static_cast<float>(taskGraph.size()) / 20.0f) * graphWindow.getSize().y;
    sf::RectangleShape scrollbarKnob(sf::Vector2f(20, scrollbarHeight));
    scrollbarKnob.setFillColor(sf::Color(200, 200, 200));
    scrollbarKnob.setPosition(1180, 0);

    bool draggingScrollbar = false;
    float scrollbarDragOffset = 0;


    std::vector<std::pair<std::string, std::vector<std::pair<int, int>>>> sortedTasks(taskGraph.begin(), taskGraph.end());

    std::string searchQuery = "";
    sf::Text searchText("", font, 24);
    searchText.setFillColor(sf::Color::Black);
    searchText.setPosition(50, 20);

    sf::Text resultText("", font, 24);
    resultText.setFillColor(sf::Color::Black);
    resultText.setPosition(50, 50);

    sf::Text summaryText("", font, 24);
    summaryText.setFillColor(sf::Color::Black);

    while (graphWindow.isOpen()) {
        sf::Event event;
        while (graphWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                graphWindow.close();
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                scrollOffset += event.mouseWheelScroll.delta * -scrollSpeed;
                scrollOffset = std::max(0.0f, std::min(scrollOffset, maxScrollOffset));
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
                    scrollOffset -= scrollSpeed;
                } else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
                    scrollOffset += scrollSpeed;
                }
                scrollOffset = std::max(0.0f, std::min(scrollOffset, maxScrollOffset));
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (scrollbarKnob.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    draggingScrollbar = true;
                    scrollbarDragOffset = event.mouseButton.y - scrollbarKnob.getPosition().y;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                draggingScrollbar = false;
            }

            if (event.type == sf::Event::MouseMoved && draggingScrollbar) {
                float newY = event.mouseMove.y - scrollbarDragOffset;
                newY = std::max(0.0f, std::min(newY, graphWindow.getSize().y - scrollbarKnob.getSize().y));
                scrollbarKnob.setPosition(1180, newY);
                scrollOffset = (newY / (graphWindow.getSize().y - scrollbarKnob.getSize().y)) * maxScrollOffset;
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8 && !searchQuery.empty()) { // Backspace
                    searchQuery.pop_back();
                } else if (event.text.unicode < 128) {
                    searchQuery += static_cast<char>(event.text.unicode);
                }
            }
        }

        graphWindow.clear(sf::Color(173, 216, 230)); // Light blue background

        searchText.setString("Search: " + searchQuery);
        graphWindow.draw(searchText);

        int totalTasks = 0;
        bool foundWorker = false;

        float yPosition = 100 - scrollOffset;
        for (const auto& worker : sortedTasks) {
            if (worker.first.find(searchQuery) != std::string::npos || searchQuery.empty()) {
                foundWorker = true;

                int totalHours = 0;
                for (const auto& task : worker.second) {
                    totalHours += task.second;
                }


                sf::Text workerText(worker.first + " (Total Hours: " + std::to_string(totalHours) + ")", font, 24);
                workerText.setFillColor(sf::Color::Black);
                workerText.setPosition((graphWindow.getSize().x - workerText.getGlobalBounds().width) / 2, yPosition);
                graphWindow.draw(workerText);

                yPosition += 40;


                for (const auto& task : worker.second) {
                    sf::Text taskText("Day " + std::to_string(task.first) + ": " + std::to_string(task.second) + "h", font, 20);
                    taskText.setFillColor(sf::Color(50, 50, 50));
                    taskText.setPosition((graphWindow.getSize().x - taskText.getGlobalBounds().width) / 2, yPosition);
                    graphWindow.draw(taskText);
                    yPosition += 30;
                    totalTasks++;
                }

                yPosition += 20;
            }
        }

        if (!foundWorker && !searchQuery.empty()) {
            resultText.setString("Worker not found.");
            graphWindow.draw(resultText);
        }


        int totalWorkers = sortedTasks.size();
        summaryText.setString("Total Workers: " + std::to_string(totalWorkers) + " | Total Tasks: " + std::to_string(totalTasks));
        summaryText.setPosition((graphWindow.getSize().x - summaryText.getGlobalBounds().width) / 2, graphWindow.getSize().y - 50);
        graphWindow.draw(summaryText);


        graphWindow.draw(scrollbar);
        graphWindow.draw(scrollbarKnob);

        graphWindow.display();
    }
}
