#include <graph.h>
#include <queue>
#include <numeric>
#pragma once

/*
    1.Mark the source node with a current distance of 0 and the rest with infinity.
    2.Set the non-visited node with the smallest current distance as the current node.
    3.For each neighbor, N of the current node adds the current distance of the 
    adjacent node with the weight of the edge connecting 0->1. 
    If it is smaller than the current distance of Node, 
    set it as the new current distance of N.
    4.Mark the current node 1 as visited.
    5.Go to step 2 if there are any nodes are unvisited.
*/

void Dijkstra(Graph& graphMain, std::vector<Worker>& employees, Task& srcNode, int Day) {
    std::unordered_map<int, int> distances;
    std::unordered_map<int, int> prevTask;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    // Initialize distances
    for (auto& adj : graphMain.AdjList) {
        for (auto& task : adj.second) {
            distances[task.first.taskID] = 10000000;
        }
    }
    
    distances[srcNode.taskID] = 0;
    pq.push({0, srcNode.taskID});

    int worker = 0;
    employees[worker].WeeklySch[Day] = 0; // Workday starts at 9 AM
    int curTaskID = srcNode.taskID;
    int curDistance = srcNode.TimeToComplete;
    while (!pq.empty()) {
        auto uhhh = std::make_pair(curDistance, curTaskID);
        uhhh = pq.top();
        pq.pop();

        if (curDistance > distances[curTaskID]) continue;

        for (auto& neighbor : graphMain.AdjList[curTaskID]) {
            Task& nextTask = neighbor.first;
            int travelTime = neighbor.second;
            int newDistance = curDistance + nextTask.TimeToComplete + travelTime;

            if (newDistance < distances[nextTask.taskID]) {
                distances[nextTask.taskID] = newDistance;
                prevTask[nextTask.taskID] = curTaskID;
                pq.push({newDistance, nextTask.taskID});
            }
        }

        // Assign task to the current worker
        employees[worker].WeeklySch[Day] += graphMain.AdjList[curTaskID][0].first.TimeToComplete;
        if (employees[worker].WeeklySch[Day] >= 7 || std::accumulate(employees[worker].WeeklySch.begin(), employees[worker].WeeklySch.end(), 0) >= 35) {
            worker++;
            if (worker >= employees.size()) {
                std::cerr << "Not enough workers to complete tasks on this day!" << std::endl;
                //This will be more important in UI.
                return;
            }
            employees[worker].WeeklySch[Day] = 0;
        }
    }
}
