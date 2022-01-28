#include <iostream>

int FibonacciRecursive(int termIndex) {
	if (termIndex == 0) {
		return 0;
	} else if (termIndex == 1) {
		return 1;
	} else return FibonacciRecursive(termIndex - 1) + FibonacciRecursive(termIndex - 2);
}

int main() {
	// Show title
	std::cout << "FIBONACCI NUMBER CALCULATOR\n---\n";

	// Get target from user
	std::cout << "Enter a target: ";
	int target;
	std::cin >> target;

	// Find target index in numbers array
	int result = FibonacciRecursive(target);

	// Return result to user
	std::cout << "Fibonacci Number: " << result << "\n\n";

	// Pause
	system("pause");

	// Exit
	return 0;
}