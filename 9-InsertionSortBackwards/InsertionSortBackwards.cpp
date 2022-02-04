#include <iostream>

// Time Complexity: O(n^2)
void InsertionSortBackwards(int* array, const int size) {
	int temp;
	for (int i = size - 2; i >= 0; i--) {
		for (int j = i; j < size - 1 && array[j] > array[j + 1]; j++) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
		}
	}
}

int main() {
	// Show title
	std::cout << "INSERTION SORT BACKWARDS\n---\n";

	// Prepare numbers
	const int NUMBERS_SIZE = 8;
	int numbers[NUMBERS_SIZE] = { 4, 10, 7, 87, 45, 11, 32, 2 };

	// Show numbers before sort
	std::cout << "NUMBERS BEFORE SORT: ";
	for (int i = 0; i < NUMBERS_SIZE; i++) {
		std::cout << numbers[i] << ' ';
	}
	std::cout << "\n\n";

	// Sort array
	InsertionSortBackwards(numbers, NUMBERS_SIZE);

	// Show numbers after sort
	std::cout << "NUMBERS AFTER SORT: ";
	for (int i = 0; i < NUMBERS_SIZE; i++) {
		std::cout << numbers[i] << ' ';
	}
	std::cout << "\n\n";

	// Pause
	system("pause");

	// Exit
	return 0;
}