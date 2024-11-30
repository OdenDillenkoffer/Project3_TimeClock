#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <Jobs.h>
#pragma
std::vector<std::pair<std::string, std::string>> NameGenerator(){
    //takes the names in names.txt provided by
    // 1000randomnames
    // it will randomly generate a name from those
    std::ifstream nameFile("names.txt");
    std::vector<std::pair<std::string, std::string>> names;
    std::string line;
    while(std::getline(nameFile, line)){
        std::istringstream iss(line);
        std::string FirstName, LastName;
        if(iss >> FirstName >> LastName){
            names.emplace_back(FirstName, LastName);
        }
    }
    nameFile.close();
    return names;

}
std::pair<std::string, std::string> randName(std::vector<std::pair<std::string, std::string>> name){
int Rand1 = rand() % 1001;
int Rand2 = rand() % 1001;
auto Pair = std::make_pair(name[Rand1].first, name[Rand2].second);
return Pair;
}

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

