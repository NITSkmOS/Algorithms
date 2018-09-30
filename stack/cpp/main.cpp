#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> s;

    // Add 1, 2, 3, 4 to a stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // Print 4, 3, 2, 1
    while (!s.empty()) {
        std::cout << s.top().value_or(-1) << " ";
        s.pop();
    }

    // Print -1 because the stack is empty
    std::cout << s.top().value_or(-1) << "\n";
    return 0;
}

