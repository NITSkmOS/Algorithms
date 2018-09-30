// Must be compiled with -std=c++17

#include <list>
#include <experimental/optional>

template <typename T>
class Queue {
private:
    std::list<T> queue;
public:
    Queue() {}

    bool empty() {
        return queue.empty();
    }

    void push(T value) {
        queue.push_front(value);
    }

    void pop() {
        if (empty()) return;
        queue.pop_back();
    }

    std::experimental::optional<T> top() {
        if (empty()) return std::experimental::nullopt;
        return queue.back();
    }
};