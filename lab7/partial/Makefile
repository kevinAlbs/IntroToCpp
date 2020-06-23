CXXFLAGS= -std=c++14 -O2 -W -Wall -Wextra -pedantic
OBJFILES= book.o library.o book.t.o library.t.o tests.m.o

test: tests
	./tests

tests: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

book.t.o: book.t.cpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

library.o: library.cpp library.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

library.t.o: library.t.cpp library.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) tests

.PHONY: clean
