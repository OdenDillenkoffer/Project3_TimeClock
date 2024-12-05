
#ifndef PROJECT3_TIMECLOCK_UISTUFF_H
#define PROJECT3_TIMECLOCK_UISTUFF_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
void showWelcomeWindow();
void showUserInputPage(int& algorithmChoice);
void showTaskGraphPage(const std::unordered_map<std::string, std::vector<std::pair<int, int>>>& taskGraph);
#endif //PROJECT3_TIMECLOCK_UISTUFF_H
