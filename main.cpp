#include <NameGen.h>
int main(){
    std::vector<std::pair<std::string, std::string>> names = NameGenerator();
    for(int i = 0; i < names.size(); i++){
        std::cout << names[i].first << " " << names[i].second << std::endl;
    }
    return 0;
}