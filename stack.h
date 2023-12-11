#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack : private std::vector<T> { // Private inheritance
public:
    // default constructor and destructor
		// using the defaults from std::vector
    Stack() = default;
    ~Stack() = default;

		// checks if the stack is empty
		// Returns true if empty, false otherwise
    bool empty() const {
        return std::vector<T>::empty();
    }

		// returns the number of elements in the stack
    size_t size() const {
        return std::vector<T>::size();
    }

		// adds an item to the top of the stack
    void push(const T& item) {
        std::vector<T>::push_back(item);
    }

		// removes the top item from the stack
    // throws std::underflow_error if the stack is empty
    void pop() {
        if (this->empty()) {
            throw std::underflow_error("Stack is empty");
        }
        std::vector<T>::pop_back();
    }

		// returns a reference to the top item of the stack
    // throws std::underflow_error if the stack is empty
    const T& top() const {
        if (this->empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return std::vector<T>::back();
    }
};

#endif // STACK_H
