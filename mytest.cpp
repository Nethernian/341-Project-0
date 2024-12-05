#include <iostream>
#include "puzzle.h"

using namespace std;

int main() {
    cout << "Testing Default Constructor" << endl;
    Puzzle Puzzle1(20);
    cout << endl;

    cout << "Testing Dump()" << endl;
    Puzzle1.dump();
    cout << endl;

    cout << "Copying and Dumping" << endl;
    Puzzle Puzzle2(Puzzle1);
    Puzzle2.dump();
    cout << endl;

    cout << "Testing overloaded assignment operator" << endl;
    Puzzle Puzzle3 = Puzzle1;
    Puzzle3.dump();
    cout << endl;

    return 0;
}
