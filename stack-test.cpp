#include <iostream>
#include "stack.h"

int main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.pop();
	std::cout << "TOP: " << stack.top() << std::endl;
	std::cout << "SIZE: " << stack.size() << std::endl;
	std::cout << "EMPTY: " << stack.empty() << std::endl;
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.top();
	system("pause");
	return 0;	
}
