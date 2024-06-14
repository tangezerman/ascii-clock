#include <iostream>
#include <ctime>
#include <string>
#include <unistd.h> 


time_t curr_time;

std::string time_str;

std::string clock_only;





std::string get_time() {
    curr_time = time(nullptr);
    time_str = ctime(&curr_time);
    clock_only = time_str.substr(11, 8);



    std::cout << clock_only << std::endl;

    return clock_only;
}


int main() {
    while(true){
        get_time();
        sleep(1);
    }
    
    return 0;
}




