#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <climits>

class Dijkstra {
public:
    // Function to optimize task assignment using Dijkstra's algorithm
    void optimizeTasks(std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph);

private:
    // Helper functions for cost calculation
    int calculateCost(const std::string& workerName);
    int getWorkerTaskLength(const std::string& workerName);

    // Task assignment function (modify this based on the task allocation logic)
    void assignTask(const std::string& workerName);

    struct Node {
        std::string workerName;
        int cost;
    };

    struct CompareNode {
        bool operator()(const Node& a, const Node& b) {
            return a.cost > b.cost;  // Min-heap based on cost
        }
    };
};

#endif // DIJKSTRA_H
