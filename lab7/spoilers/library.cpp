
#include "library.hpp"
#include <algorithm>
#include <numeric>
#include <string>
#include "book.hpp"

namespace lab7 {

int Library::pagecount() const
{
    return std::accumulate(
        books_.begin(),
        books_.end(),
        0,
        [](int sum, const std::unique_ptr<Book>& b) {
            return sum + b->pagecount();
        }
    );
}

void Library::remove_books_by_author(const std::string& author)
{
    books_.erase(
        std::remove_if(
            books_.begin(),
            books_.end(),
            [&](const auto& b) {
                return b->author() == author;
            }
        ),
        books_.end()
    );
}

void Library::remove_books_by_title(const std::string& title)
{
    books_.erase(
        std::remove_if(
            books_.begin(),
            books_.end(),
            [&](const auto& b) {
                return b->title() == title;
            }
        ),
        books_.end()
    );
}

} // namespace lab7
