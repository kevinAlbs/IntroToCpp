#include <iomanip>
#include <iostream>
#include <string>

#include "lab2.hpp"
#include "readString.hpp"

int main() {
    std::cout << "Enter a string: " << std::flush;
    std::string s = lab2::readString();

    if (lab2::is_palindrome(s)) {
        std::cout << "The string " << std::quoted(s) << " is a palindrome.\n";
    } else {
        std::cout << "The string " << std::quoted(s) << " is NOT a palindrome.\n";
        lab2::reverse_in_place(&s);
        std::cout << "Reversed, it is " << std::quoted(s) << "\n";
    }
}
