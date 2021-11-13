#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <chrono>

// macro to test for float equality
#define float_eq(a, b) (((a)-(b) > -1e-10) && ((a)-(b) < 1e-10))

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

    // Key 0 (Spacebar)
    if (c == ' ') {
        k.num = 0;
        k.pos = 0;
        return k;
    }

    // Key 7 (4 letters)
    char c_low = tolower(c);
    if (c_low >= 'p' && c_low <= 's') {
        k.num = 7;
        k.pos = c_low - 'p';
    }
    
    // Key 8 (3 letters offset by 7)
    else if (c_low >= 't' && c_low <= 'v') {
        k.num = 8;
        k.pos = c_low - 't';
    }

    // Key 9 (4 letters)
    else if (c_low >= 'w' && c_low <= 'z') {
        k.num = 9;
        k.pos = c_low - 'w';
    }

    // Keys 1-6 (3 letters each) 
    else {
        k.num = (char_index(c) / 3) + 2;
        k.pos = char_index(c) % 3;
    };

    return k;
}

float get_time(std::string line) 
{     
    float time_elapsed{0.0};

    key k = get_key(line[0]);
    time_elapsed += k.pos * 0.25; // RULE 1
    time_elapsed += isupper(line[0]) ? 2.0 : 0.0;

    char prev_ch{line[0]};
    key prev_key{get_key(prev_ch)};

    if (line.length() > 1) {
        for (unsigned int k{1}; k < line.length(); k++) {
            char curr_ch{line[k]};
            key curr_key{get_key(curr_ch)};

            time_elapsed += (curr_key.num == prev_key.num) ? 0.5 : 0.25;    // RULE 4

            time_elapsed += curr_key.pos * 0.25;                            // RULE 3
            time_elapsed += isupper(curr_ch) ? 2.0 : 0.0;                   // RULE 5

            prev_ch = curr_ch;
            prev_key = curr_key;
        }
    }

    return time_elapsed;
}

typedef std::pair <std::string, float> timepair; 
// below line *only* used if we have some sort of timer
typedef std::chrono::high_resolution_clock Clock;

int main()
{
    // Get file name from user
    std::string file_name;

    std::cout << "Input file: ";
    std::getline(std::cin, file_name);
    // Search PACKAGE directory for file
    file_name = "../PACKAGE/" + file_name;
#ifdef TIMER
    auto start_time = Clock::now();
#endif
    std::ifstream file;
    file.open(file_name);

    if (!file.is_open()) {
        // Search PACKAGE directory for file
        std::string file_name_package = "../PACKAGE/" + file_name;
    
        file.open(file_name_package);
        // error message output
        if (!file.is_open()) {
            std::cout << "Unable to open " << '"' << file_name << "\"." << std::endl;
            exit(1);
        }
    }

    std::vector<std::string> word_list;

    // Read strings from input file
    std::string input_buffer;

    while (std::getline(file, input_buffer)) {
        // Remove carriage return from string
        if (input_buffer[input_buffer.length() - 1] == '\r')
            { input_buffer.pop_back(); }
        // remove output to prevent being overwritten
        word_list.push_back(input_buffer);
    }

    // get the min ready so that it stays after the loop finishes
    float min_time = get_time(word_list[0]);
    std::vector <timepair> results;

    //push the first pair into the vector
    results.push_back(timepair(word_list[0], get_time(word_list[0])));

    for (unsigned int j{1}; j < word_list.size(); j++) {
        // aliased version of pairs for our purpose
        timepair curr{word_list[j], get_time(word_list[j])};
        
        // testing to make sure that the floats are within 
        // margin of error -- floats are fussy
        if (float_eq(curr.second, min_time)) {
            results.push_back(curr);
        }
        
        // determine whether there is a minimum lower than what we have to clear 
        // out and have a new minimum
        else if (curr.second < min_time) {
            results.clear();
            results.push_back(curr);
            min_time = curr.second;
        }
    }
    
    // print out the values collected
    for (unsigned int k{0}; k < results.size(); k++) 
        {std::cout << results[k].first << " = " << results[k].second << 's' << std::endl;}
    
#ifdef TIMER
    auto end_time = Clock::now();
    std::cout << "\n\n";
    
    // output timing in microseconds from the stage after input
    std::cout << "Time elapsed was: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " microseconds." << std::endl;
#endif

    file.close();
}
