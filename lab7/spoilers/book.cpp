#include "book.hpp"

#include <ostream>
#include <string>

namespace lab7 {

Book::Book(std::string title, std::string author)
    : title_(std::move(title)), author_(std::move(author))
{}

void Book::print(std::ostream& os) const {
    os << title_ << " by " << author_;
    os << " (" << pagecount() << " pages, " << do_get_type() << ")";
}

} // namespace lab7
