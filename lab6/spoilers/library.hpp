#ifndef INCLUDED_LIBRARY_HPP
#define INCLUDED_LIBRARY_HPP

#include <set>
#include <string>
#include "book.hpp"

namespace lab6 {

class Library {
    struct ByAuthor {
        bool operator()(const Book& a, const Book& b) const {
            return a.author() < b.author();
        }
    };

    std::multiset<Book, ByAuthor> books_;

public:
    explicit Library() = default;

    int bookcount() const { return books_.size(); }
    int pagecount() const;

    void add_book(Book b) {
        books_.insert(std::move(b));
    }

    void remove_books_by_author(const std::string& author);
    void remove_books_by_title(const std::string& title);

    auto begin() const { return books_.begin(); }
    auto end() const { return books_.end(); }
};

} // namespace lab6

#endif // INCLUDED_LIBRARY_HPP
