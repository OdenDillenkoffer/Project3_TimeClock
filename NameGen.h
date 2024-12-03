#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <utility>
#include "Jobs.h" // JE: changed the <> to ""

#pragma once // JE: added "once"

std::vector<std::pair<std::string, std::string>> NameGenerator(){ 
    std::ifstream nameFile("names.txt"); // JE: takes the names from name.txt (generated randomly from 1000 randomnames)
    std::vector<std::pair<std::string, std::string>> names;
    std::string line;
    
    while(std::getline(nameFile, line)){ // JE: splits the names and stores them as pairs in the vector names
        std::istringstream iss(line);
        std::string FirstName, LastName;
        if(iss >> FirstName >> LastName){
            names.emplace_back(FirstName, LastName);
        }
    }
    
    nameFile.close();
    return names; // JE: returns names (contains all the names) 
}

std::pair<std::string, std::string> randName(std::vector<std::pair<std::string, std::string>> name){ // JE: adjusted indentation and added whitespace
    int Rand1 = rand() % 1001;
    int Rand2 = rand() % 1001;
    auto Pair = std::make_pair(name[Rand1].first, name[Rand2].second);
    
    return Pair;
}


