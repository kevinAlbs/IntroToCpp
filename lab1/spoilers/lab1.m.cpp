#include <string>
#include <iostream>
#include <iomanip>

#include "readString.hpp"

void reverse_in_place(std::string& s)
{
    for (size_t i=0; i < s.size(); ++i) {
        size_t j = s.size() - i - 1;
        if (i < j) {
            std::swap(s[i], s[j]);
        }
    }
}

bool is_palindrome(const std::string& s)
{
    std::string t = s;
    reverse_in_place(t);
    return (s == t);
}

int main()
{
    std::cout << "Enter a string: " << std::flush;
    std::string s = lab1::readString();

    if (is_palindrome(s)) {
        std::cout << "The string " << std::quoted(s) << " is a palindrome.\n";
    } else {
        std::cout << "The string " << std::quoted(s) << " is NOT a palindrome.\n";
        reverse_in_place(s);
        std::cout << "Reversed, it is " << std::quoted(s) << "\n";
    }
}
