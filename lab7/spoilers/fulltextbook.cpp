#include "fulltextbook.hpp"
#include <string>

namespace lab7 {

int FullTextBook::do_pagecount() const {
    return pages_.size();
}

std::string FullTextBook::do_get_type() const {
    return "full text";
}

std::string FullTextBook::get_page(int n) const {
    return pages_.at(n);
}

}  // namespace lab7
