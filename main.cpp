#include <NameGen.h>
#include <graphImp.h>
#include <unordered_set>
#pragma
//job Stuff
Job Janitor("Janitor", 0, 24, 4, 8, 12);
Job Pilot("Pilot", 0, 24, 2, 10, 50);
Job CustomerService("Customer Service", 9, 17, 4, 8, 13);
Job CEO("CEO", 9, 17, 8, 12, 300);
Job Engineer("Engineer", 9, 17, 8, 12, 50);
Job Security("Security", 0, 24, 4, 8, 15);
Job BaggageHandle("Baggage Handler", 0, 24, 4, 8, 12);
Job Fueler("Fueler", 0 ,24, 4, 12, 13);
Job Mechanic("Mechanic", 5, 24, 4, 12, 20);
Job RampSup("Ramp Supplier", 0 ,24, 4, 8, 13);
Job Manager("Manager", 9, 20, 4, 10, 35);
Job SpaceTrafficController("Space Traffic Controller", 0, 24, 4, 8, 40);

int main(){
    AdjacencyList graph;
    std::vector<std::pair<std::string, std::string>> names = NameGenerator();
    std::unordered_set<int> IDs;
    for(int i = 0; i < 100000; i++){
        std::pair<std::string, std::string> newName = randName(names);
        int RanID = 10000000 + std::rand() % 90000000;
        //add a checking mechanism here
        //Use the set
        GraphNode newNode(RanID, newName.first, newName.second, Janitor);
        //need more jobs in here
        graph.AddNode(newNode);
    }
    //create weights and edges
    auto it = graph.adjList.begin();
    std::vector<std::pair<GraphNode, int>> nodes = it->second;
    std::vector<int> info = it->second[0].first.Information.second.GetInfo();
    //earliest possible shift
    GraphNode* src = &it->second[0].first;
    int srcID = src->workID;
    it->second[0].first.shift.first = info[0];
    it->second[0].first.shift.second = info[0] + info[2];
    //smallest possible shift

    //weight to all nodes will be difference in time between end of shift and possible beggining of other
    //Jobs might all be destroyed for a singlular title for simplicity
    for(int i = 0; i < nodes.size(); i++){
        std::vector<int> nodeInfo = nodes[i].first.Information.second.GetInfo();
        if(src->shift.second >= nodeInfo[0] && src->shift.second < nodeInfo[1]){
        graph.addEdge(srcID, &nodes[i].first, 0);}
        //if weight is between both begin and end times of possible shift
        else{
            graph.addEdge(srcID, &nodes[i].first, nodeInfo[0] - src->shift.second);
        }
    }
    //creates all the edges I think, will need to be recaculated per shift?
    return 0;
}