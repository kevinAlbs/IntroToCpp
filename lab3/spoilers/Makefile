CXXFLAGS= -std=c++14 -O2 -W -Wall -Wextra -pedantic
OBJFILES= book.o library.o tests.m.o

test: tests
	./tests

tests: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) tests

.PHONY: clean
