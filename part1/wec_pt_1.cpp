#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <chrono>

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
    char c_low = tolower(c);

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

int main()
{
    // Get file name from user
    std::string file_name;

    std::cout << "Input file: ";
    std::getline(std::cin, file_name);
    // Search PACKAGE directory for file
    file_name = "../PACKAGE/" + file_name;

    #ifdef TIMED
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
    #endif

    std::ifstream file;
    file.open(file_name);

    if (!file.is_open()) {
        // Search PACKAGE directory for file
        std::string file_name_package = "../PACKAGE/" + file_name;

        file.open(file_name_package);
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

        word_list.push_back(input_buffer);
    }

    #ifdef TIMED
        std::vector<float> times;

        // Print strings with times
        for (std::string str : word_list)
            { times.push_back(get_time(str)); }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;

        std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    #else
        // get the min ready so that it stays after the loop finishes
        timepair min = timepair(word_list[0], get_time(word_list[0]));
        std::vector <timepair> results;

        //push the first pair into the vector
        results.push_back(min);

        for (unsigned int j{1}; j < word_list.size(); j++)
            {
                timepair current = timepair(word_list[j],get_time(word_list[j]));
                if (current.second < min.second) {
                    results.clear();
                    results.push_back(current);
                } else if (current.second == min.second ) {
                    results.push_back(current);
                }
            }

        for (unsigned int k{0}; k < results.size(); k++) 
        {std::cout << results[k].first << " = " << results[k].second << 's' << std::endl;}
    
    #endif

    file.close();
}
