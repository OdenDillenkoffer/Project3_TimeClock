#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <utility>
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