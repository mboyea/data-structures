#include <iostream>

// Time Complexity: O(n^2)
void BubbleSort(int* array, const int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main() {
	// Show title
	std::cout << "BUBBLE SORT\n---\n";

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
	BubbleSort(numbers, NUMBERS_SIZE);

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