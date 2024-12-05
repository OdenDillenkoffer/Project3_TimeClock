#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <climits>

class Dijkstra {
public:
    void optimizeTasks(std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph);

private:
    int calculateCost(const std::string& workerName);
    int getWorkerTaskLength(const std::string& workerName);

    void assignTask(const std::string& workerName);

    struct Node {
        std::string workerName;
        int cost;
    };

    struct CompareNode {
        bool operator()(const Node& a, const Node& b) {
            return a.cost > b.cost;
        }
    };
};

#endif // DIJKSTRA_H
