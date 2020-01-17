
#include "library.hpp"
#include "book.hpp"
#include <string>

namespace lab3 {

int Library::pagecount() const {
    int result = 0;
    for (const Book& book : books_) {
        result += book.pagecount();
    }
    return result;
}

void Library::remove_books_by_author(const std::string& author) {
    for (size_t i = 0; i < books_.size(); ) {
        if (books_[i].author() == author) {
            books_[i].swap(books_.back());
            books_.pop_back();
        } else {
            ++i;
        }
    }
}

void Library::remove_books_by_title(const std::string& title) {
    for (size_t i = 0; i < books_.size(); ) {
        if (books_[i].title() == title) {
            books_[i].swap(books_.back());
            books_.pop_back();
        } else {
            ++i;
        }
    }
}

}  // namespace lab3
