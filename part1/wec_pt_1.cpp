#include <iostream>
#include <cctype>

#include <string>
#include <sstream>
#include <cctype>
#include <math>

inline
uint8_t char_index(char c) 
{
    return isupper(c) ? c - 'A' : c - 'a'; 
}

uint32_t get_key(char c)
{
    char ch = tolower(c);

    if (ch >= 'p' && ch <= 's') return 7;
    if (ch >= 't' && ch <= 'v') return 8;
    if (ch >= 'w' && ch <= 'z') return 9;
    return (char_index(c) / 3) + 2;
}

int main()
{
    for (char c = 'a'; c <= 'z'; c++) {
        std::cout << c << ' ' << get_key(c) << std::endl;
    }
}










double get_time(std::string line) 
{
    uint8_t size = line.length();
    double time_elapsed{0.0};
    
    // RULE 1
    // don't consider for k=1 or k=0, so just return 0.0
    
    if (size > 1) {
        for (unsigned int k{1}; k < size; k++) {
            char current_char = line[k];
            uint8_t current_pos = get_key(current_char).pos;
            char previous_char= line[k-1];
            uint8_t previous_pos get_key(previous_char).pos;
            
            // RULE 2 
            // determine whether they're on the same key, but not the same letter
            bool isSameKey = (current_pos == previous_pos); 

            if (isSameKey) {
                // RULE 3
                uint8_t num_presses{math::abs((get_key(current_char).num) - get_key(previous_char).num)};

                time_elapsed += num_presses*0.25;


            } else if (!isSameKey) {
                time_elapsed += 0.25;  

            } 
        }
    }


    return time_elapsed;
}

// input of ac
//
// zero on the first round, and then some movement distance 
