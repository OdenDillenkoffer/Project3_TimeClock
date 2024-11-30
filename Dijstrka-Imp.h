/*
    1.Mark the source node with a current distance of 0 and the rest with infinity.
    2.Set the non-visited node with the smallest current distance as the current node.
    3.For each neighbor, N of the current node adds the current distance of the adjacent node with the weight of the edge connecting 0->1. If it is smaller than the current distance of Node, set it as the new current distance of N.
    4.Mark the current node 1 as visited.
    5.Go to step 2 if there are any nodes are unvisited.
*/
#include <graphImp.h>
#include <unordered_map>
#pragma
void Dijkstra(AdjacencyList grph, GraphNode* src){
 std::unordered_map<int, int> stuff;
 //first item is workID, second will be distance
 stuff.emplace(src->workID);
stuff[src->workID] = 0;
for(auto it = grph.adjList.begin(); it != grph.adjList.end(); it++){
    stuff.emplace(it->first);
    stuff[it->first] = 10^9;
}
//edges will be the time between end of shift and possible begining of next

}