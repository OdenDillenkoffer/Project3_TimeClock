#include "AStar.h"
#include <iostream>
#include <queue>
// commit 1
void AStar::optimizeTasks(std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph) {
    std::priority_queue<Node, std::vector<Node>, CompareNode> openList;
    std::unordered_map<std::string, int> closedList;


    for (auto& worker : taskGraph) {
        Node startNode;
        startNode.workerName = worker.first;
        startNode.cost = calculateCost(worker.first);
        startNode.heuristic = calculateHeuristic(worker.first);

        openList.push(startNode);
    }


    while (!openList.empty()) {
        Node currentNode = openList.top();
        openList.pop();

        if (closedList.find(currentNode.workerName) != closedList.end()) {
            continue;
        }

        closedList[currentNode.workerName] = currentNode.cost;

        assignTask(currentNode.workerName);


        for (const auto& task : taskGraph[currentNode.workerName]) {
            int taskLength = task.second;
            int day = task.first;

            Node neighborNode;
            neighborNode.workerName = currentNode.workerName;
            neighborNode.cost = currentNode.cost + taskLength;
            neighborNode.heuristic = calculateHeuristic(currentNode.workerName);

            openList.push(neighborNode);
        }
    }
}

int AStar::calculateCost(const std::string& workerName) {
    return getWorkerTaskLength(workerName);
}

int AStar::calculateHeuristic(const std::string& workerName) {
    return 100 - getWorkerAvailableHours(workerName);
}

int AStar::getWorkerAvailableHours(const std::string& workerName) {
    return 8;
}

int AStar::getWorkerTaskLength(const std::string& workerName) {
    return 4;
}

void AStar::assignTask(const std::string& workerName) {
    std::cout << "Assigning task to worker: " << workerName << std::endl;
}
