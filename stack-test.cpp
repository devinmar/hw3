#include <iostream>
#include "stack.h"

int main() {
	Stack<int> stack;
	// Places elements into the stack
	// Placing 1 on top, and going all the way up to 5
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.pop();

	// returns the top of the stack, the size, as well as empty
	std::cout << "TOP: " << stack.top() << std::endl;
	std::cout << "SIZE: " << stack.size() << std::endl;
	std::cout << "EMPTY: " << stack.empty() << std::endl;

// Removal of elements from the stack
// Removes from the top, and goes from there
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.top();
	system("pause");
	return 0;	
}
