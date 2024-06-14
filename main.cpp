#include <iostream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <vector>
#include <map>
#include "ascii.h"


// ASCII representation of digits 0-9 and colon ":"
std::map<char, std::vector<std::string>> digit_map = {
    {'0', {" __ ",
           "|  |",
           "|  |",
           "|  |",
           "|__|"}},
    {'1', {"    ",
           "   |",
           "   |",
           "   |",
           "   |"}},
    {'2', {" __ ",
           "   |",
           " __|",
           "|   ",
           "|__ "}},
    {'3', {" __ ",
           "   |",
           " __|",
           "   |",
           " __|"}},
    {'4', {"    ",
           "|  |",
           "|__|",
           "   |",
           "   |"}},
    {'5', {" __ ",
           "|   ",
           "|__ ",
           "   |",
           " __|"}},
    {'6', {" __ ",
           "|   ",
           "|__ ",
           "|  |",
           "|__|"}},
    {'7', {" __ ",
           "   |",
           "   |",
           "   |",
           "   |"}},
    {'8', {" __ ",
           "|  |",
           "|__|",
           "|  |",
           "|__|"}},
    {'9', {" __ ",
           "|  |",
           "|__|",
           "   |",
           " __|"}},
    {':', {"    ",
           "  | ",
           "    ",
           "  | ",
           "    "}}
};

std::string get_time() {
    time_t curr_time = time(nullptr);
    std::string time_str = ctime(&curr_time);
    return time_str.substr(11, 8);
}

void print_clock(const std::string& time) {
    std::vector<std::string> clock_lines(5, ""); // 5 lines for each digit
    
    for (char c : time) {
        for (int i = 0; i < 5; ++i) {
            clock_lines[i] += digit_map[c][i] + "  ";
        }
    }
    
    for (const auto& line : clock_lines) {
        std::cout << line << std::endl;
    }
}

int main() {
    // Clear the screen and hide the cursor
    std::cout << "\033[2J\033[H\033[?25l";

    while (true) {
        std::string current_time = get_time();
        // Move the cursor to the top left of the screen
        std::cout << "\033[H";
        print_clock(current_time);
        std::cout << std::flush;
        sleep(1);
    }
    
    // Show the cursor before exiting (though this part will never be reached)
    std::cout << "\033[?25h";

    return 0;
}
