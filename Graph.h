#ifndef GRAPH_H
#define GRAPH_H
// commit 1
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

class Graph {
public:

    void loadWorkersFromFile(const std::string& fileName);


    void generateTaskGraph(int totalTasks, int dailyTasks, int totalDays, int taskLengthMin, int taskLengthMax);


    void distributeTasks(int totalTasks, int dailyTasks, int totalDays, int taskLengthMin, int taskLengthMax);


    void displayGraph();


    std::unordered_map<std::string, std::vector<std::pair<int, int>>>& getGraph();

private:
    std::unordered_map<std::string, std::vector<std::pair<int, int>>> workersTasks;


    int assignedWorkers = 0;
};

#endif // GRAPH_H
