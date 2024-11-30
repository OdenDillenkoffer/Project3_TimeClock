#include <Jobs.h>
#include <NameGen.h>
#include <utility>
#pragma
struct GraphNode{
    public:
    int workID;
    std::pair<std::pair<std::string, std::string>, Job> Information;
    
    //Constructor

    GraphNode(int ID = 0, std::string first = " ", std::string last = " ", Job job = Job()){
        this->workID = ID;
        this->Information.first = std::make_pair(first, last);
        this->Information.second = job;
    }
};

class AdjacencyList {

};
