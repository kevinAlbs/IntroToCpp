
#include "library.hpp"
#include <algorithm>
#include <numeric>
#include <string>
#include "book.hpp"

namespace lab4 {

int Library::pagecount() const
{
    // YOUR CODE HERE -- consider std::accumulate
}

void Library::remove_books_by_author(const std::string& author)
{
    // YOUR CODE HERE -- use the erase-remove idiom
}

void Library::remove_books_by_title(const std::string& title)
{
    // YOUR CODE HERE -- use the erase-remove idiom
}

} // namespace lab4
