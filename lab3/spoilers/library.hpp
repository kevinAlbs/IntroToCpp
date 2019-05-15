#ifndef INCLUDED_LIBRARY_HPP
#define INCLUDED_LIBRARY_HPP

#include <string>
#include <vector>
#include "book.hpp"

namespace lab3 {

class Library {
    std::vector<Book> books_;

public:
    int bookcount() const { return books_.size(); }
    int pagecount() const;

    void add_book(const Book& b) {
        books_.push_back(b);
    }

    void remove_books_by_author(const std::string& author);
    void remove_books_by_title(const std::string& title);
};

} // namespace lab3

#endif // INCLUDED_LIBRARY_HPP
