CXXFLAGS= -std=c++14 -O2 -W -Wall -Wextra -pedantic
OBJFILES= book.o kindle.o library.o book.t.o kindle.t.o library.t.o tests.m.o

test: tests
	./tests

tests: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

p1:
	$(CXX) $(CXXFLAGS) -DSKIP_PART2 -DSKIP_PART3 book.cpp book.t.cpp tests.m.cpp -o tests
	./tests

p2:
	$(CXX) $(CXXFLAGS) -DSKIP_PART1 -DSKIP_PART3 book.cpp library.cpp library.t.cpp tests.m.cpp -o tests
	./tests

p3:
	$(CXX) $(CXXFLAGS) -DSKIP_PART1 -DSKIP_PART2 book.cpp library.cpp kindle.cpp kindle.t.cpp tests.m.cpp -o tests
	./tests

clean:
	rm -f $(OBJFILES) tests

.PHONY: clean p1 p2 p3 test
