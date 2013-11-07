
CXXFLAGS=-Wall -Werror -Wfatal-errors -std=c++11  -masm=intel  -pedantic-errors -I. -DNDEBUG=1 -DIN_TEST=1

all:
	$(CXX) buddy_tree.cpp test.cpp test_suite.cpp -I. -lcppunit $(CXXFLAGS) -orun_tests.bin
	timeout 5s ./run_tests.bin
