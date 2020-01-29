#include <iomanip>
#include <iostream>
#include <string>

#include "readString.hpp"

// YOUR CODE GOES HERE

int main() {
    std::cout << "Enter a string: " << std::flush;
    std::string s = lab1::readString();

    if (is_palindrome(s)) {
        std::cout << "The string " << std::quoted(s) << " is a palindrome.\n";
    } else {
        std::cout << "The string " << std::quoted(s) << " is NOT a palindrome.\n";
        reverse_in_place(&s);
        std::cout << "Reversed, it is " << std::quoted(s) << "\n";
    }
}
