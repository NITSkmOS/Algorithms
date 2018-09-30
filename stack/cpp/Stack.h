// Must be compiled with -std=c++17

#include <list>
#include <experimental/optional>

template <typename T>
class Stack {
private:
    std::list<T> stack;
public:
    Stack() {}

    bool empty() {
        return stack.empty();
    }

    void push(T value) {
        stack.push_front(value);
    }

    void pop() {
        if (empty()) return;
        stack.pop_front();
    }

    std::experimental::optional<T> top() {
        if (empty()) return std::experimental::nullopt;
        return stack.front();
    }
};

