#include <iostream>
#include <fstream>
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

double get_time(std::string line) 
{     
     uint8_t size = line.length();
     double time_elapsed{0.0};
    
    // RULE 1
    //don't consider for size=1 or size=0 (if line[k] isn't num 2 or capital), so just return 0.0
    
     if (size == 1) {
        
         return time_elapsed;
     }


    if (size > 1) {
        for (unsigned int k{1}; k < size; k++) {
            char current_char = line[k];
            uint8_t current_num = get_key(current_char).num;
            char previous_char= line[k-1];
            uint8_t previous_num get_key(previous_char).num;
            
            // check first if capital
            bool isUpper = isupper(current_char);

            // RULE 2 
            // determine whether they're on the same key, but not the same letter
            bool isSameKey = (current_num == previous_num); 

            if (isSameKey) {
                // RULE 3
                uint8_t num_presses{get_key{current_char}.pos - 1};
                time_elapsed += num_presses*0.25;

            } else if (!isSameKey) {
                time_elapsed += 0.25;  

            } 
        }
    }


    return time_elapsed;
}

int main()
{
    std::string file_name;
    std::getline(std::cin, file_name);
    file_name = "../PACKAGE/" + file_name;

    std::ifstream file;
    file.open(file_name);

    std::vector<std::string> word_list;
    std::string input_buffer;

    while (std::getline(file, input_buffer)) {
        word_list.push_back(input_buffer);
    }

    // main stuff

    file.close();
}
