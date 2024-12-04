#include "Graph.h"
#include "AStar.h"
#include "Dijkstra.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <UIStuff.h>
// commit

int main() {
    Graph taskGraph;

    std::string filename = "names.txt";
    taskGraph.loadWorkersFromFile(filename);


    int totalTasks = 1000000;
    int dailyTasks = 20000;
    int totalDays = 5;
    int taskLengthMin = 1;
    int taskLengthMax = 8;

    std::cout << "\nChoose an optimization algorithm:\n";
    std::cout << "1. A* Algorithm\n";
    std::cout << "2. Dijkstra's Algorithm\n";
    int choice;
    std::cin >> choice;

    taskGraph.generateTaskGraph(totalTasks, dailyTasks, totalDays, taskLengthMin, taskLengthMax);

    AStar astar;
    Dijkstra dijkstra;

    std::string algorithmChoice;
    if (choice == 1) {
        algorithmChoice = "A* Algorithm";
        astar.optimizeTasks(taskGraph.getGraph());
    } else if (choice == 2) {
        algorithmChoice = "Dijkstra's Algorithm";
        dijkstra.optimizeTasks(taskGraph.getGraph());
    } else {
        std::cout << "Invalid choice. Please select 1 for A* or 2 for Dijkstra.\n";
        return 0;
    }
    taskGraph.displayGraph();
    return 0;
}