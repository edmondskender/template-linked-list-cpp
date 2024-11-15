#include <iostream>
#include "linked-list.h"

using std::cout, std::endl;

int main() {
    linked_list<int> foo;
    for (int i = 0; i < 10; ++i)
        foo.push_back(i);
    cout << foo << endl;
    return 0;
}
