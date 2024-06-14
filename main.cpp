#include <iostream>
#include <ctime>


time_t curr_time;

std::string clock_only;

void get_time() {
    curr_time = time(nullptr);
    std::string time_str = ctime(&curr_time);
    
    
    std::string clock_only = time_str.substr(11, 8);

    std::cout << clock_only << std::endl;
}


int main() {
    get_time(); 
    return 0;
}




