#include <iostream>


// Precondition: array is sorted from least to greatest
// Time Complexity: O(log_2(n))
int BinarySearchRecursive(const int* array, const int size, const int key, int low, int high) {
	if (low > high) {
		// key not found
		return -1;
	}

	int mid = (low + high) / 2;
	if (array[mid] < key) {
		// element is to the right
		return BinarySearchRecursive(array, size, key, mid + 1, high);
	}	else if (array[mid] > key) {
		// element is to the left
		return BinarySearchRecursive(array, size, key, low, mid - 1);
	}
	// key found
	return mid;
}

// Precondition: array is sorted from least to greatest
// Time Complexity: O(log_2(n))
int BinarySearchRecursive(const int* array, const int size, const int key) {
	return BinarySearchRecursive(array, size, key, 0, size-1);
}

int main() {
	// Show title
	std::cout << "RECURSIVE BINARY SEARCH\n---\n";

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
	int targetIndex = BinarySearchRecursive(numbers, NUMBERS_SIZE, target);

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