/* ASSIGNMENT:
 * Create a hash table with the following methods.
 * Insert(data)
 * Search(data)
 * operator<<(os, list)
 * operator[](index)
 * 
 * Date: 3/8/2022
 * Author: Matthew Boyea
 */

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

class HashTable {
private:
	int* array;
	unsigned int bucketCount;
	unsigned int Hash(int data) const {
		return data % bucketCount;
	}
public:
	HashTable(unsigned int bucketCount = 10)
		: array(new int[bucketCount]), bucketCount(bucketCount) {
			std::fill(array, array + bucketCount, -1);
		}
	void Insert(int data) {
		unsigned int bucket = Hash(data);
		// for every bucket
		for (unsigned int bucketsChecked = 0; bucketsChecked < bucketCount; bucketsChecked++) {
			// if bucket is empty
			if (array[bucket] < 0) {
				// put the data in the bucket
				array[bucket] = data;
				return;
			}
			bucket = (bucket + 1) % bucketCount;
		}
		return;
	}
	int Search(int data) const {
		unsigned int bucket = Hash(data);
		// for every bucket
		for (unsigned int bucketsChecked = 0; bucketsChecked < bucketCount; bucketsChecked++) {
			// if bucket contains the data
			if (array[bucket] == data) {
				// return the index
				return bucket;
			}
			bucket = (bucket + 1) % bucketCount;
		}
		return -1;
	}
	int& operator[](unsigned int index) {
		return array[index];
	}
	friend std::ostream& operator<<(std::ostream& os, const HashTable& list) {
		// for every bucket except the last
		for (unsigned int i = 0; i < list.bucketCount; i++) {
			// case: bucket empty
			if (list.array[i] < 0) {
				os << 'X';
			} else {
				// output data
				os << list.array[i];
			}
			// output a whitespace
			os << ' ';
		}
		// output the last bucket
		// case: bucket empty
		if (list.array[list.bucketCount - 1] < 0) {
			os << 'X';
		} else {
			// output data
			os << list.array[list.bucketCount - 1];
		}
		return os;
	}
};

int main() {
	// Declare list
	HashTable table;

	while(true) {
		// Print list
		std::cout << "Table: " << table << "\n";
		// Print menu
		std::cout << "HASH TABLE\n";
		std::cout << "---\n";
		std::cout << "0: quit\n";
		std::cout << "1: insert\n";
		std::cout << "2: search\n";
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
			system("pause");
			break;
		} else if (input[0] == '1' || input[0] == 'I' || input[0] == 'i') {
			// INSERT DATA
			std::cout << "Data: ";
			std::getline(std::cin, input);
			table.Insert(std::stoi(input));
		} else if (input[0] == '2' || input[0] == 'S' || input[0] == 's') {
			// SEARCH FOR DATA
			std::cout << "Data: ";
			std::getline(std::cin, input);
			int index = table.Search(std::stoi(input));
			if (index < 0) {
				std::cout << "Data not found in array.\n";
			} else {
				std::cout << "Data found at index " << index << ".\n";
			}
			system("pause");
		} else {
			std::cout << "Input not recognized. Please try again.\n";
		}
		std::cout << "\n";
	}
	// exit program
	return 0;
}