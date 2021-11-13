#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <math>

inline
uint8_t char_index(char c) 
{
    return isupper(c) ? c - 'A' : c - 'a'; 
}

typedef struct {
    uint32_t num;
    uint32_t pos;
} key;

key get_key(char c)
{
    key k;
    char c_low =tolower(c);

    if (c_low >= 'p' && c_low <= 's') {
        k.num = 7;
        k.pos = c_low - 'p';
    }
    
    else if (c_low >= 't' && c_low <= 'v') {
        k.num = 8;
        k.pos = c_low - 't';
    }

    else if (c_low >= 'w' && c_low <= 'z') {
        k.num = 9;
        k.pos = c_low - 'w';
    }

    else {
        k.num = (char_index(c) / 3) + 2;
        k.pos = char_index(c) % 3;
    };

    return k;
}

int main()
{
    for (char c{'a'}; c <= 'z'; c++) {
        key k = get_key(c);
        std::cout << c << ": " << k.num << ", " << k.pos << std::endl;
    }

    // std::vector<std::string> word_list;

    // std::string buff;
    // while (std::cin.eofbit != 0) {
    //     std::getline(std::cin, buff);
    //     word_list.push_back(buff);
    // }

    // for (std::string str : word_list) {
    //     std::cout << str << std::endl;
    // }
}










// double get_time(std::string line) 
// {
//     uint8_t size = line.length();
//     double time_elapsed{0.0};
    
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
                // find the number difference if on the same key and then figure out how many extra 
                uint8_t num_presses{math::abs((get_key(current_char).num) - get_key(previous_char).num)};

                time_elapsed += num_presses*0.25;


            } else if (!isSameKey) {
                time_elapsed += 0.25;  

            } 

            return time_elapsed;
        }
    }


//     return time_elapsed;
// }

// input of ac
//
// zero on the first round, and then some movement distance 
