include <assert.h>
#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> q;

    // Add 1, 2, 3, 4 to a queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // Print 1, 2, 3, 4
    while (!q.empty()) {
        std::cout << q.top().value_or(-1) << " ";
        q.pop();
    }

    // Print -1 because the queue is empty
    std::cout << q.top().value_or(-1) << "\n";
    return 0;
}
