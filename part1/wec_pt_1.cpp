#include <iostream>
#include <fstream>
#include <cctype>

#include <vector>
#include <string>
#include <sstream>
#include <cctype>

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










// double get_time(std::string line) 
// {
//     uint8_t size = line.length();
//     double time_elapsed{0.0};
    
//     // don't consider for k=1 or k=0, so just return 0.0
    
//     if (size > 1) {
//         for (unsigned int k{1}; k < size; k++) {
//             char current_char = line[k];
//             char previous_char= line[k-1];

//             time_elapsed += ()


//         }
//     }


//     return time_elapsed;
// }

// input of ac
//
// zero on the first round, and then some movement distance 
