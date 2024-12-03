#include <unordered_map>
#include "Nodes.h" // JE: changed <> to ""
#pragma once

class Graph { // JE: fixed indentation and added whitespace
    public:
    std::unordered_map<int, std::vector<std::pair<Task, int>>> AdjList;
    //int is Task ID
    //vector is connect
    void AddNode(Task& node) {
        AdjList[node.taskID] = {};
    }

    void AddEdge(Task& srcTask, Task& nextTask) {
        AdjList[srcTask.taskID].push_back(std::make_pair(nextTask, srcTask.TimeToComplete));
    }

    std::vector<std::pair<Task, int>> getNeighbors(int id) {
        return AdjList[id];
    }
};
