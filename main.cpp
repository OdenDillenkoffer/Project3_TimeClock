#include "Graph.h"
#include "AStar.h"
#include "Dijkstra.h"
#include "UIStuff.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
    showWelcomeWindow();

    int algorithmChoice = 0;
    showUserInputPage(algorithmChoice);

    if (algorithmChoice == 0) {
        std::cout << "No algorithm chosen. Exiting...\n";
        return 0;
    }

    Graph taskGraph;
    taskGraph.loadWorkersFromFile("names.txt");

    taskGraph.generateTaskGraph(1000000, 20000, 5, 1, 8);

    if (algorithmChoice == 1) {
        AStar astar;
        astar.optimizeTasks(taskGraph.getGraph());
    } else if (algorithmChoice == 2) {
        Dijkstra dijkstra;
        dijkstra.optimizeTasks(taskGraph.getGraph());
    }

    showTaskGraphPage(taskGraph.getGraph());

    return 0;
}


