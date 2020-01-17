#include "lab2.hpp"
#include <string>

namespace lab2 {

bool is_palindrome(const std::string& s) {
    std::string t = s;
    lab2::reverse_in_place(t);
    return (s == t);
}

void reverse_in_place(std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        size_t j = s.size() - i - 1;
        if (i < j) {
            std::swap(s[i], s[j]);
        }
    }
}

}  // namespace lab2
