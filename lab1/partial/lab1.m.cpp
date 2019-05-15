#include <string>
#include <iostream>
#include <iomanip>

#include "readString.hpp"
#include "lab1.hpp"

int main()
{
    std::cout << "Enter a string: " << std::flush;
    std::string s = lab1::readString();

    if (lab1::is_palindrome(s)) {
        std::cout << "The string " << std::quoted(s) << " is a palindrome.\n";
    } else {
        std::cout << "The string " << std::quoted(s) << " is NOT a palindrome.\n";
        lab1::reverse_in_place(s);
        std::cout << "Reversed, it is " << std::quoted(s) << "\n";
    }
}
