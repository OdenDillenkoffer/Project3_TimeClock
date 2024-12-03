#include <vector>
#include <utility>
#include <iostream>

// JE: fixed indentation on classes
struct Worker{
    std::pair<std::string, std::string> Name; //first name is first, last name is second
    int ID;
    std::vector<int> WeeklySch;
    //begin and end times of the day (24 hr buisness)
    //inside weekly sch each pair is a daily schedule from .first (begin) to .second(end)
    //24 Hr clock to simplify
};

struct Task{
    std::string TaskTitle;
    int taskID;
    int TimeToComplete;
    //Jobs are made up of tasks to complete, which vary in hourage.
    //Essentially everyone has the same job, with tasks to complete.
};
