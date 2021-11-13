#include <iostream>
#include <cctype>

<<<<<<< HEAD
#include <string>
#include <sstream>
#include <cctype>

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
