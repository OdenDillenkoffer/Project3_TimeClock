/*
A* Search Algorithm
1.  Initialize the open list
2.  Initialize the closed list
    put the starting node on the open 
    list (you can leave its f at zero)
3.  while the open list is not empty
    a) find the node with the least f on 
       the open list, call it "q"
    b) pop q off the open list
  
    c) generate q's 8 successors and set their 
       parents to q
   
    d) for each successor
        i) if successor is the goal, stop search
        
        ii) else, compute both g and h for successor
          successor.g = q.g + distance between 
                              successor and q
          successor.h = distance from goal to 
          successor (This can be done using many 
          ways, we will discuss three heuristics- 
          Manhattan, Diagonal and Euclidean 
          Heuristics)
          
          successor.f = successor.g + successor.h
        iii) if a node with the same position as 
            successor is in the OPEN list which has a 
           lower f than successor, skip this successor
        iV) if a node with the same position as 
            successor  is in the CLOSED list which has
            a lower f than successor, skip this successor
            otherwise, add  the node to the open list
     end (for loop)
  
    e) push q on the closed list
    end (while loop)
*/
#include "graph.h" // JE: changed <> to ""
#include <numeric>
#include <queue>
#include <algorithm>
#pragma once // JE: added once

int Heuristic(Task& current, Task& goal){
    return goal.TimeToComplete + current.TimeToComplete;
    //maybe this works
}

/* bool compareF(std::unordered_map<int, int>& fScores, int left, int right){
    return fScores[left] > fScores[right];
} */
struct CompareF { // removed old compareF function and implemented a struct to fix the instantiation error
    std::unordered_map<int, int>& fScores;

    CompareF(std::unordered_map<int, int>& f) : fScores(f) {}

    bool operator()(int left, int right) {
        return fScores[left] > fScores[right];  // JE: Min-Heap based on f-scores
    }
};

void ModifiedAStar(Graph& mainGraph, Task& StartTask, Task& goalTask, std::vector<Worker>& employees, int Day, std::unordered_map<int, Task>& allTasks){
    int worker = 0;
    std::unordered_map<int, int> g; //cost to traverse (time to complete)
    std::unordered_map<int, int> f; // f = g + h
    std::unordered_map<int, int> prevTask; //keeps track of relations between nodes

    for(int i = 0; i < mainGraph.AdjList[StartTask.taskID].size(); i++){
        g[mainGraph.AdjList[StartTask.taskID][i].first.taskID] = 100000000;
        f[mainGraph.AdjList[StartTask.taskID][i].first.taskID] = 100000000;
        //all scores set to "infinity"
    }
    
    g[StartTask.taskID] = 0; //no distance to itself
    
    employees[worker].WeeklySch[Day] += StartTask.TimeToComplete;
    //add hours to the day of the worker
    if(employees[worker].WeeklySch[Day] >= 7 || std::accumulate(employees[worker].WeeklySch.begin(), employees[worker].WeeklySch.end(), 0) >= 35){
        worker++;
    }

    //fscore calculation for initial node 
    f[StartTask.taskID] = Heuristic(StartTask, goalTask);

    //priority queue for nodes based on fScore A{PWEfkpamwfwawrf}
    CompareF comparator(f);
    std::priority_queue<int, std::vector<int>, CompareF> openSet(comparator); // JE: changed the old initialization to accomodate for the struct CompareF
    
    openSet.push(StartTask.taskID);
    //push beggining node

    while(!openSet.empty()){
        int current = openSet.top(); //node will lowest fScore (um,mm)
        openSet.pop();

        //assign shift
        employees[worker].WeeklySch[Day] += allTasks[current].TimeToComplete;
        //this might not work :(

        if (employees[worker].WeeklySch[Day] >= 7 || std::accumulate(employees[worker].WeeklySch.begin(), employees[worker].WeeklySch.end(), 0) >= 35) {
            worker++;
            if (worker >= employees.size()) {
                std::cerr << "Not enough workers to complete tasks on this day!" << std::endl;
                //This will be more important in UI.
                return;
            }

        }
        for(int i = 0; i < mainGraph.getNeighbors(current).size(); i++){
            int tentG = g[current] + mainGraph.getNeighbors(current)[i].first.TimeToComplete;
            //tentative G score
            Task neighbor = mainGraph.getNeighbors(current)[i].first;
            //if this path is better than any previous found
            if(tentG < g[neighbor.taskID]){
                g[neighbor.taskID] = tentG;
                f[neighbor.taskID] = g[neighbor.taskID] + Heuristic(neighbor, goalTask);
                prevTask[neighbor.taskID] = current;
    
                //add neighbor to set for exploration
                openSet.push(neighbor.taskID);
            }
        }
        //check if reached goal
        if(current == goalTask.taskID){
            //make path
            std::vector<int> path;
            while(prevTask.find(current) != prevTask.end()){
                path.push_back(current);
                current = prevTask[current];
            }
            path.push_back(StartTask.taskID);
            std::reverse(path.begin(), path.end());
            //kinda redundant in our use of this algorithm, but this how its supposed to end.
        }
    }
    // JE: removed return (void function)
}
