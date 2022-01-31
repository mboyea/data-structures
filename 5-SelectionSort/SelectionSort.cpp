#include <iostream>

// Time Complexity: O(n^2)
void SelectionSort(int* array, const int size) {
	int temp;
	// i ranges from the first to the second-to-last element
	for (int i = 0; i < size - 1; i++) {
		// FIND SMALLEST FROM i+1 TO size
		int indexSmallest = i;
		// j ranges from the second to the last element
		for (int j = i + 1; j < size; j++) {
			// if element j is less than the current known smallest element
			if (array[j] < array[indexSmallest]) {
				// set the smallest known element to j
				indexSmallest = j;
			}
		}
		// SWAP THE SMALLEST KNOWN INDEX WITH i
		temp = array[i];
		array[i] = array[indexSmallest];
		array[indexSmallest] = temp;
	}
}

int main() {
	// Show title
	std::cout << "SELECTION SORT\n---\n";

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
	SelectionSort(numbers, NUMBERS_SIZE);

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