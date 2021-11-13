#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>

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
     double time_elapsed{0.0};
    
    // RULE 1
    //don't consider for size=1 or size=0 (if line[k] isn't num 2 or capital), so just return 0.0
    
    if (line.length() == 0) return 0.0;

    if (line.length() == 1) {
    
        return time_elapsed;
    }

    for (unsigned int k{1}; k < line.length(); k++) {
        key curr_key = get_key(line[k]);
        key prev_key = get_key(line[k - 1]);

        // RULE 2 
        // determine whether they're on the same key, but not the same letter

        if (curr_key.num == prev_key.num) {
            // RULE 3
            time_elapsed += curr_key.pos * 0.25;
        }
        
        else {
            time_elapsed += 0.25;  
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
