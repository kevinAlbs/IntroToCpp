#ifndef INCLUDED_LIBRARY_HPP
#define INCLUDED_LIBRARY_HPP

#include "book.hpp"
#include <string>
#include <vector>

namespace lab4 {

class Library {
    std::vector<Book> books_;

public:
    explicit Library() = default;

    int bookcount() const { return books_.size(); }
    int pagecount() const;

    void add_book(const Book& b) {
        books_.push_back(b);
    }

    void remove_books_by_author(const std::string& author);
    void remove_books_by_title(const std::string& title);

    auto begin() { return books_.begin(); }
    auto end() { return books_.end(); }
    auto begin() const { return books_.begin(); }
    auto end() const { return books_.end(); }
};

}  // namespace lab4

#endif  // INCLUDED_LIBRARY_HPP
