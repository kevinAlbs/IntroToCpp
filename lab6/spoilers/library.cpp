
#include "library.hpp"
#include <algorithm>
#include <numeric>
#include <string>
#include "book.hpp"

namespace lab6 {

int Library::pagecount() const
{
    return std::accumulate(
        books_.begin(),
        books_.end(),
        0,
        [](int sum, const Book& b) {
            return sum + b.pagecount();
        }
    );
}

void Library::remove_books_by_author(const std::string& author)
{
    Book dummy("", author, 0);
    auto range = books_.equal_range(dummy);
    books_.erase(range.first, range.second);
}

void Library::remove_books_by_title(const std::string& title)
{
    auto erase_if = [](auto& set, auto pred) {
        auto it = set.begin();
        auto last = set.end();
        while (it != last) {
            if (pred(*it)) {
                it = set.erase(it);
            } else {
                ++it;
            }
        }
    };
    erase_if(
        books_,
        [&](const Book& b) {
            return b.title() == title;
        }
    );
}

} // namespace lab6
