#include <assert.h>
#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> q;
    q.push(2);
    q.push(3);
    assert(!q.empty());
    assert(q.top().value_or(-1) == 2);
    q.pop();
    assert(q.top().value_or(-1) == 3);
    q.pop();
    assert(q.empty());
    assert(q.top().value_or(-1) == -1);
    return 0;
}