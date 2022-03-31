#include <iostream>

// Precondition: array is sorted from least to greatest
// Time Complexity: O(log_2(n))
int BinarySearch(const int* array, const int size, const int key) {
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high) {
		mid = (high + low) / 2;
		if (array[mid] < key) {
			// key index is greater than mid
			low = mid + 1;
		} else if (array[mid] > key) {
			// key index is less than mid
			high = mid - 1;
		} else {
			// array[mid] equals key; key found
			return mid;
		}
	}
	// key not found in array
	return -1;
}

int main() {
	// Show title
	std::cout << "BINARY SEARCH\n---\n";

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
	int targetIndex = BinarySearch(numbers, NUMBERS_SIZE, target);

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