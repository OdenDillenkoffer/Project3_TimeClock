#include "Dijkstra.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>

void Dijkstra::optimizeTasks(std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph) {
    std::priority_queue<Node, std::vector<Node>, CompareNode> openList;
    std::unordered_map<std::string, int> dist;


    for (auto& worker : taskGraph) {
        dist[worker.first] = std::numeric_limits<int>::max();
    }


    for (auto& worker : taskGraph) {
        Node startNode;
        startNode.workerName = worker.first;
        startNode.cost = 0;
        dist[worker.first] = 0;

        openList.push(startNode);
    }


    while (!openList.empty()) {
        Node currentNode = openList.top();
        openList.pop();


        for (const auto& task : taskGraph[currentNode.workerName]) {
            int taskLength = task.second;
            std::string neighbor = std::to_string(task.first);

            int newCost = dist[currentNode.workerName] + taskLength;

            if (newCost < dist[neighbor]) {
                dist[neighbor] = newCost;

                Node neighborNode;
                neighborNode.workerName = neighbor;
                neighborNode.cost = newCost;
                openList.push(neighborNode);
            }
        }

        assignTask(currentNode.workerName);
    }
}

int Dijkstra::calculateCost(const std::string& workerName) {
    return getWorkerTaskLength(workerName);
}

int Dijkstra::getWorkerTaskLength(const std::string& workerName) {
    return 4;
}

void Dijkstra::assignTask(const std::string& workerName) {
}
