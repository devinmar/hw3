#include <iostream>
#include <cassert>
#include "stack.h"

// test function to verify push and pop operations
void testPushPop() {
    Stack<int> stack;
    assert(stack.empty());

		// push elements onto the stack and verify the state after each push
    stack.push(1);
    stack.push(2);
    assert(stack.size() == 2);
    assert(stack.top() == 2);

		// pop an element and verify the state after the pop
    stack.pop();
    assert(stack.size() == 1);
    assert(stack.top() == 1);

		// pop the remaining element and verify the stack is empty
    stack.pop();
    assert(stack.empty());

    std::cout << "Test Push and Pop: Passed" << std::endl;
}

// test function to verify the behavior of top() on an empty stack.
void testTopException() {
    Stack<int> stack;
    try {
        stack.top();
        assert(false); // should not reach this line.
    } catch (const std::underflow_error& e) {
        assert(true); // exception caught as expected.
    }

    std::cout << "Test Top Exception: Passed" << std::endl;
}

// test function to verify the behavior of pop() on an empty stack
void testPopException() {
    Stack<int> stack;
    try {
        stack.pop();
        assert(false); // should not reach this line.
    } catch (const std::underflow_error& e) {
        assert(true); // exception caught as expected.
    }

    std::cout << "Test Pop Exception: Passed" << std::endl;
}

// main function to execute all test cases.
int main() {
    testPushPop();
    testTopException();
    testPopException();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
