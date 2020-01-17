#pragma once

#include "book.hpp"
#include <string>
#include <vector>

namespace lab7 {

class FullTextBook : public Book {
    std::vector<std::string> pages_;

    int do_pagecount() const override;

    std::string do_get_type() const override;

public:
    explicit FullTextBook(std::string title, std::string author, std::vector<std::string> pages)
        : Book(std::move(title), std::move(author)), pages_(std::move(pages)) {}

    std::string get_page(int n) const;
};

}  // namespace lab7
