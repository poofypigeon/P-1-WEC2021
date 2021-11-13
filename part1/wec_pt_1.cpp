#include <iostream>
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

    return 0;
}