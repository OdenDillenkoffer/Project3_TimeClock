#ifndef ASTAR_H
#define ASTAR_H

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <climits>
// commit 1
class AStar {
public:
    void optimizeTasks(std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph);

private:

    int calculateCost(const std::string& workerName);
    int calculateHeuristic(const std::string& workerName);
    int getWorkerAvailableHours(const std::string& workerName);
    int getWorkerTaskLength(const std::string& workerName);

    void assignTask(const std::string& workerName);

    struct Node {
        std::string workerName;
        int cost;
        int heuristic;
    };

    struct CompareNode {
        bool operator()(const Node& a, const Node& b) {
            return (a.cost + a.heuristic) > (b.cost + b.heuristic);
        }
    };
};

#endif // ASTAR_H
