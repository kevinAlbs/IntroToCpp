#ifndef INCLUDED_BOOK_HPP
#define INCLUDED_BOOK_HPP

#include <iosfwd>
#include <string>

namespace lab4 {

class Book {
    std::string title_;
    std::string author_;
    int pagecount_;
public:
    explicit Book(const std::string& title, const std::string& author, int pagecount);
    
    std::string title() const { return title_; }
    std::string author() const { return author_; }
    int pagecount() const { return pagecount_; }

    void swap(Book& rhs);
    void print(std::ostream& os) const;

    friend void swap(Book& a, Book& b) {
        a.swap(b);
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& b) {
        b.print(os);
        return os;
    }
};

} // namespace lab4

#endif // INCLUDED_BOOK_HPP
