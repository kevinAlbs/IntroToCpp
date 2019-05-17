#include "book.hpp"

#include <ostream>
#include <string>
#include <utility>

namespace lab6 {

Book::Book(std::string title, std::string author, int pagecount)
    : title_(std::move(title)), author_(std::move(author)), pagecount_(pagecount)
{}

void Book::swap(Book& rhs) {
    std::swap(title_, rhs.title_);
    std::swap(author_, rhs.author_);
    std::swap(pagecount_, rhs.pagecount_);
}

void Book::print(std::ostream& os) const {
    os << title_ << " by " << author_;
    os << " (" << pagecount_ << " pages)";
}

} // namespace lab6
