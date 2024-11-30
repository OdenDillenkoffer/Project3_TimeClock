#include <Jobs.h>
#include <NameGen.h>
#include <utility>
#include <unordered_map>
#pragma
struct GraphNode{
    public:
    int workID;
    std::pair<std::pair<std::string, std::string>, Job> Information;
    std::pair<int, int> shift;
    
    //Constructor

    GraphNode(int ID = 0, std::string first = " ", std::string last = " ", Job job = Job()){
        this->workID = ID;
        this->Information.first = std::make_pair(first, last);
        this->Information.second = job;
        this->shift = std::make_pair(0, 0);
    }
};

class AdjacencyList {
public:
std::unordered_map<int, std::vector<std::pair<GraphNode, int>>> adjList;


void AddNode(GraphNode node){adjList[node.workID];}
void addEdge(GraphNode* from, GraphNode* to, int weight){
adjList[from->workID].emplace_back(to, weight);
}

};
