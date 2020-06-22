#pragma once

#include <iosfwd>
#include <string>

namespace lab8 {

class Book {
    std::string title_;
    std::string author_;

private:
    virtual std::string do_get_type() const = 0;
    virtual int do_pagecount() const = 0;

protected:
    explicit Book(std::string title, std::string author);

public:
    std::string title() const { return title_; }
    std::string author() const { return author_; }

    int pagecount() const {
        return do_pagecount();
    }

    void print(std::ostream& os) const;

    virtual ~Book() = default;

    friend std::ostream& operator<<(std::ostream& os, const Book& b) {
        b.print(os);
        return os;
    }
};

}  // namespace lab8
