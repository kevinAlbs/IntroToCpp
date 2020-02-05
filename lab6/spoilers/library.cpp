
#include "library.hpp"
#include "book.hpp"
#include <algorithm>
#include <numeric>
#include <string>

namespace lab6 {

int Library::pagecount() const {
    return std::accumulate(
        books_.begin(),
        books_.end(),
        0,
        [](int sum, const Book& b) {
            return sum + b.pagecount();
        }
    );
}

void Library::remove_books_by_author(const std::string& author) {
    Book dummy("", author, 0);
    auto range = books_.equal_range(dummy);
    books_.erase(range.first, range.second);
}

template<class Set, class Predicate>
static void erase_if(Set& set, Predicate pred)
{
    auto it = set.begin();
    while (it != set.end()) {
        if (pred(*it)) {
            it = set.erase(it);
        } else {
            ++it;
        }
    }
}

void Library::remove_books_by_title(const std::string& title) {
    lab6::erase_if(
        books_,
        [&](const Book& b) {
            return b.title() == title;
        }
    );
}

}  // namespace lab6
