#ifndef ASTAR_H
#define ASTAR_H

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <climits>
// commit
class AStar {
public:
    // Function to optimize task assignment using A* algorithm
    void optimizeTasks(std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph);

private:
    // Helper functions for cost and heuristic calculation
    int calculateCost(const std::string& workerName);
    int calculateHeuristic(const std::string& workerName);
    int getWorkerAvailableHours(const std::string& workerName);
    int getWorkerTaskLength(const std::string& workerName);

    // Task assignment function (modify this based on the task allocation logic)
    void assignTask(const std::string& workerName);

    struct Node {
        std::string workerName;
        int cost;
        int heuristic;
    };

    struct CompareNode {
        bool operator()(const Node& a, const Node& b) {
            return (a.cost + a.heuristic) > (b.cost + b.heuristic);  // Min-heap based on cost + heuristic
        }
    };
};

#endif // ASTAR_H
