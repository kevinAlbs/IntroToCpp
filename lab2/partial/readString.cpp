#include "readString.hpp"
#include <iostream>
#include <string>

namespace lab2 {

std::string readString() {
    std::string result;
    std::getline(std::cin, result, '\n');
    return result;
}

}  // namespace lab2
