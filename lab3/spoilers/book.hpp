#ifndef INCLUDED_BOOK_HPP
#define INCLUDED_BOOK_HPP

#include <string>

namespace lab3 {

class Book {
    std::string title_;
    std::string author_;
    int pagecount_;

public:
    Book(const std::string& title, const std::string& author, int pagecount);

    std::string title() const { return title_; }
    std::string author() const { return author_; }
    int pagecount() const { return pagecount_; }

    void swap(Book& rhs);
};

}  // namespace lab3

#endif  // INCLUDED_BOOK_HPP
