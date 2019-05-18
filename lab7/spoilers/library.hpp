#pragma once

#include <string>
#include <vector>
#include "book.hpp"

namespace lab7 {

class Library {
    std::vector<std::unique_ptr<Book>> books_;

public:
    explicit Library() = default;

    int bookcount() const { return books_.size(); }
    int pagecount() const;

    void add_book(std::unique_ptr<Book> pb) {
        books_.push_back(std::move(pb));
    }

    void remove_books_by_author(const std::string& author);
    void remove_books_by_title(const std::string& title);
};

} // namespace lab7
