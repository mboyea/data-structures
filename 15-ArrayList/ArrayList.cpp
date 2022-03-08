/* ASSIGNMENT:
 * Create an array-based list with the following methods.
 * Append(data)
 * Prepend(data)
 * InsertAfter(data, index)
 * RemoveAt(index)
 * operator[](index)
 * operator<<(os, list)
 * 
 * Date: 3/2/2022
 * Author: Matthew Boyea
 */

#include <iostream>
#include <string>
#include <cstring>

template<typename T>
class ArrayList {
private:
	T* array;
	unsigned int allocatedSize;
	unsigned int size;

	void Reallocate() {
		if (size == allocatedSize) {
			T* newArray = new T[allocatedSize * 2];
			std::memcpy((void*)newArray, (void*)array, sizeof(T) * size);
			delete array;
			array = newArray;
			allocatedSize = allocatedSize * 2;
		}
	}
public:
	ArrayList(unsigned int allocateSize = 1)
		: array(new T[allocateSize]), allocatedSize(allocateSize), size(0) {}
	void Append(T data) {
		// case: array out of bounds
		Reallocate();
		// append data
		array[size] = data;
		size++;
	}
	void Prepend(T data) {
		// case: array out of bounds
		Reallocate();
		// for every element from the tail+1 of the array
		// (excluding element 0)
		for (unsigned int i = size; i > 0; i--) {
			// set it to the element before it
			array[i] = array[i - 1];
		}
		// prepend data
		array[0] = data;
		size++;
	}
	void InsertAfter(T data, unsigned int index) {
		// case: index out of bounds
		if (index >= size) {
			return;
		}
		// case: array out of bounds
		Reallocate();
		// shift elements after the index to the right
		// for every element from the tail+1 to the index+2 of the array
		for (unsigned int i = size; i > index + 1; i--) {
			// set it to the element before it
			array[i] = array[i - 1];
		}
		// insert data at the index
		array[index + 1] = data;
		size += 1	;
	}
	void RemoveAt(unsigned int index) {
		// case: index out of bounds
		if (index >= size) {
			return;
		}
		// for every element from the index to the tail of the array
		// (excluding the last element)
		for (unsigned int i = index; i < size - 1; i++) {
			// set it to the elment after it
			array[i] = array[i + 1];
		}
		size -= 1;
	}
	T& operator[](unsigned int index) {
		return array[index];
	}
	friend std::ostream& operator<<(std::ostream& os, const ArrayList& list) {
		// case: list is empty
		if (list.size == 0) {
			return os;
		}
		// for every element except the tail
		for (unsigned int i = 0; i < list.size - 1; i++) {
			// output it & a whitespace
			os << list.array[i] << ' ';
		}
		// output the tail
		return os << list.array[list.size - 1];
	}
};

int main() {
	// Declare list
	ArrayList<int> list;

	while(true) {
		// Print menu
		std::cout << "ARRAY LIST\n";
		std::cout << "---\n";
		std::cout << "0: quit\n";
		std::cout << "1: append\n";
		std::cout << "2: prepend\n";
		std::cout << "3: insert after\n";
		std::cout << "4: remove at\n";
		std::cout << "\n";
		std::cout << "Choice: ";

		// get input
		std::string input;
		std::getline(std::cin, input);
		// remove leading whitespace
		for (unsigned int i = 0; i < input.size() && input[i] == ' '; i++) {
			input.erase(0, 1);
		}
		// parse input
		if (input[0] == '0' || input[0] == 'Q' || input[0] == 'q') {
			// QUIT
			std::cout << "Quitting...\n";
			break;
		} else if (input[0] == '1' || input[0] == 'A' || input[0] == 'a') {
			// APPEND DATA
			std::cout << "Data: ";
			std::getline(std::cin, input);
			list.Append(std::stoi(input));
		} else if (input[0] == '2' || input[0] == 'P' || input[0] == 'p') {
			// PREPEND DATA
			std::cout << "Data: ";
			std::getline(std::cin, input);
			list.Prepend(std::stoi(input));
		} else if (input[0] == '3' || input[0] == 'I' || input[0] == 'i') {
			// INSERT DATA AFTER INDEX
			std::cout << "Data: ";
			std::getline(std::cin, input);
			int data = std::stoi(input);
			std::cout << "Index: ";
			std::getline(std::cin, input);
			list.InsertAfter(data, std::stoi(input));
		} else if (input[0] == '4' || input[0] == 'R' || input[0] == 'r') {
			// REMOVE DATA AT INDEX
			std::cout << "Index: ";
			std::getline(std::cin, input);
			list.RemoveAt(std::stoi(input));
		} else {
			std::cout << "Input not recognized. Please try again.\n";
		}

		// Print list
		std::cout << "\nList: " << list << "\n";
	}
	// Exit
	return 0;
}