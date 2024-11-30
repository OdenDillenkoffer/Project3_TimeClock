#include <utility>
#include <iostream>
#include <vector>
class Job{
public:
std::pair<int, int> Worktime;
int MinimumShift;
int MaxShift;
int stdWage;

std::string JobTitle;

//constructor
Job(std::string title = " ", int begin = 0, int end = 0, int MiniumShift = 0, int MaxShift = 0, int stdWage = 0)
: JobTitle(std::move(title)), Worktime(begin, end), MinimumShift(MiniumShift), MaxShift(MaxShift), stdWage(stdWage) {}


std::vector<int> GetInfo(){
std::vector<int> JobInfo;
JobInfo.push_back(Worktime.first);
JobInfo.push_back(Worktime.second);    
JobInfo.push_back(MinimumShift);    
JobInfo.push_back(MaxShift);    
JobInfo.push_back(stdWage);
return JobInfo;
//returns a vector with the start time of job, end time, shortest possible shift, longest possible shift, and wage of the position
}
void setWorktimes(int begin, int end){
    this->Worktime.first = begin;
    this->Worktime.second = end;
}
void setMin(int time){this->MinimumShift = time;}
void setMax(int time){this->MaxShift = time;}
void setWages(int money){this->stdWage = money;};
};
