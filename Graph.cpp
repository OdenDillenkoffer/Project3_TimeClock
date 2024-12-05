#include "Graph.h"
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

void Graph::loadWorkersFromFile(const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cerr << "Error opening file " << fileName << "\n";
        return;
    }

    std::string name;
    while (std::getline(inFile, name)) {
        workersTasks[name] = {};
    }

}

void Graph::generateTaskGraph(int totalTasks, int dailyTasks, int totalDays, int taskLengthMin, int taskLengthMax) {
    distributeTasks(totalTasks, dailyTasks, totalDays, taskLengthMin, taskLengthMax);
}

void Graph::distributeTasks(int totalTasks, int dailyTasks, int totalDays, int taskLengthMin, int taskLengthMax) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> lengthDist(taskLengthMin, taskLengthMax);

    int tasksAssigned = 0;
    for (auto& [worker, tasks] : workersTasks) {
        int weeklyHours = 0;
        for (int day = 1; day <= totalDays; ++day) {
            if (tasksAssigned >= totalTasks) break;

            int dailyHours = 0;
            while (dailyHours < 8 && weeklyHours < 35 && tasksAssigned < totalTasks) {
                int taskLength = lengthDist(gen);

                if (dailyHours + taskLength > 8 || weeklyHours + taskLength > 35) break;

                dailyHours += taskLength;
                weeklyHours += taskLength;
                tasksAssigned++;
            }

            if (dailyHours > 0) {
                tasks.emplace_back(day, dailyHours);
            }

            if (tasks.size() == 5) break;
        }
    }

}

void Graph::displayGraph() {
    int totalWorkers = workersTasks.size();

    for (const auto& [worker, tasks] : workersTasks) {
        std::cout << worker << ": ";
        int totalHours = 0;
        if (tasks.empty()) {
            std::cout << "No tasks assigned.\n";
            continue;
        }

        for (const auto& [day, length] : tasks) {
            std::cout << "(Day " << day << ", " << length << "h) ";
            totalHours += length;
        }

        std::cout << "Total: " << totalHours << "h\n\n";
    }

}

std::unordered_map<std::string, std::vector<std::pair<int, int>>>& Graph::getGraph() {
    return workersTasks;
}
