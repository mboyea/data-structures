#include <iostream>

// Time Complexity: O(n)
int LinearSearch(const int* array, const int size, const int key) {
	for (int i = 0; i < size; i++) {
		if (key == array[i]) {
			// key found
			return i;
		}
	}
	// key not found
	return -1;
}

int main() {
	// Show title
	std::cout << "LINEAR SEARCH\n---\n";

	// Prepare numbers
	const int NUMBERS_SIZE = 8;
	int numbers[NUMBERS_SIZE] = { 2, 4, 7, 10, 11, 32, 45, 87 };

	// Show numbers
	std::cout << "NUMBERS: ";
	for (int i = 0; i < NUMBERS_SIZE; i++) {
		std::cout << numbers[i] << ' ';
	}
	std::cout << '\n';

	// Get target from user
	std::cout << "Enter a target: ";
	int target;
	std::cin >> target;

	// Find target index in numbers array
	int targetIndex = LinearSearch(numbers, NUMBERS_SIZE, target);

	// Return target index to user
	if (targetIndex < 0) {
		std::cout << "Target was not found in the array.";
	} else std::cout << "Target was found at index: " << targetIndex;
	std::cout << "\n\n";

	// Pause
	system("pause");

	// Exit
	return 0;
}