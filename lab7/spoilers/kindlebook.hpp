#pragma once

#include "book.hpp"
#include <string>

namespace lab7 {

class KindleBook : public Book {
    int do_pagecount() const override {
        return 0;
    }

    std::string do_get_type() const override {
        return "Kindle";
    }

public:
    explicit KindleBook(std::string title, std::string author)
        : Book(std::move(title), std::move(author)) {}
};

}  // namespace lab7
