#include <iostream>

#include <string>
#include <sstream>
#include <cctype>

int main () {

    return 0;
}











double get_time(std::string line) 
{
    uint8_t size = line.length();
    double time_elapsed{0.0};
    
    // don't consider for k=1 or k=0, so just return 0.0
    
    if (size > 1) {
        for (unsigned int k{1}; k < size; k++) {
            char current_char = line[k];
            char previous_char= line[k-1];

            time_elapsed += ()


        }
    }


    return time_elapsed;
}

// input of ac
//
// zero on the first round, and then some movement distance 
