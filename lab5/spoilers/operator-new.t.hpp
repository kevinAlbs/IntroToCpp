#pragma once

// You should not modify this file.

#include <cstddef>
#include <new>

inline bool& new_called() {
    static bool b = false;
    return b;
}

inline size_t& new_count() {
    static size_t i = 0;
    return i;
}

// C++ allows the programmer to override `new` and `delete` globally.
// This is _not_ a good idea in practice. But it does let me write
// a test that fails without move semantics and succeeds with move
// semantics.

void* operator new(size_t);
void operator delete(void*, size_t) noexcept;
