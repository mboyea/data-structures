/* 
 * DESCRIPTION:
 * Implement a linked list which includes the
 * Append(list, target)
 * Prepend(list, target)
 * InsertAfter(list, target)
 * RemoveAfter(list, target)
 * 
 * Date: 2/21/2022
 * Author: Matthew Boyea
 */

#include <iostream>

template <class T>
struct Node {
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList {
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
};

int main() {


	// Show title
	std::cout << "BUBBLE SORT BACKWARDS\n---\n";

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