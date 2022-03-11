/* ASSIGNMENT:
 * Implement a linked list class with the following methods.
 * Append(node)
 * Prepend(node)
 * InsertAfter(node, target)
 * RemoveAfter(target)
 * 
 * Date: 2/22/2022
 * Author: Matthew Boyea
 */

#include <iostream>
#include <string>
#include <sstream>

template <class T>
struct Node {
public:
	T data;
	Node<T>* next = nullptr;
	Node(T data) : data(data) {}
	Node operator=(T data) {
		this->data = data;
	}
};

template <class T>
class LinkedList {
private:
	Node<T>* LinearSearch(T key) {
		// for every node
		for (Node<T>* target = head; target != nullptr; target = target->next) {
			// return the node if its data matches key
			if (key == target->data) return target;
		}
		// key not found
		return nullptr;
	}
	void SelectionSort() {
		// case: list has 0 or 1 elements
		if (head == nullptr || head->next == nullptr) {
			return;
		}
		T temp;
		// i ranges from the first to second-to-last element
		for (Node<T>* i = head; i->next != nullptr; i = i->next) {
			// FIND SMALLEST NODE WITHIN [i->next, tail]
			Node<T>* nodeSmallest = i;
			// j ranges from i->next to the tail
			for (Node<T>* j = i->next; j != nullptr; j = j->next) {
				// if j is smaller than the current known smallest node
				if (j->data < nodeSmallest->data) {
					// set the smallest known node to j
					nodeSmallest = j;
				}
			}
			// SWAP THE SMALLEST NODE WITH i
			temp = i->data;
			i->data = nodeSmallest->data;
			nodeSmallest->data = temp;
		}
	}
public:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;

	// insert node at the end of the list
	void Append(Node<T>* node) {
		// case: no elements are in list
		if (head == nullptr) {
			head = node;
			tail = node;
			return;
		}
		// insert node after tail
		tail->next = node;
		tail = node;
	}
	// insert node at the beginning of the list
	void Prepend(Node<T>* node) {
		// case: no elements are in list
		if (head == nullptr) {
			head = node;
			tail = node;
			return;
		}
		// insert node before head
		node->next = head;
		head = node;
	}
	// insert node into the list after the target
	// if no target is given, Prepend the node
	void InsertAfter(Node<T>* node, Node<T>* target) {
		// case: no target given (Prepend node)
		if (target == nullptr) {
			Prepend(node);
			return;
		}
		// case: node goes after tail (Append node)
		if (target == tail) {
			tail->next = node;
			tail = node;
			return;
		}
		// insert node after target
		node->next = target->next;
		target->next = node;
	}
	// remove the node after the target from the list
	// if no target is given, remove the head
	void RemoveAfter(Node<T>* target) {
		Node<T>* successor;
		// case: no target given & list isn't empty
		if (target == nullptr && head != nullptr) {
			successor = head->next;
			head = successor;
			// case: head is the last element
			if (successor == nullptr) {
				tail = nullptr;
			}
			return;
		}
		// case: a node follows target
		if (target->next != nullptr) {
			successor = target->next->next;
			target->next = successor;
			// case: removed the tail
			if (successor == nullptr) {
				tail = target;
			}
			return;
		}
	}
	void Sort() {
		SelectionSort();
	}
	// return the address of the node that has a value equal to key
	// if key is not found in the list, return nullptr
	Node<T>* Search(T key) {
		return LinearSearch(key);
	}
	// print the list to os
	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
		// case: list is empty
		if (list.head == nullptr) {
			return os;
		}
		// for every node except the tail
		for (Node<T>* target = list.head; target->next != nullptr; target = target->next) {
				// output the node's data and a whitespace
				os << target->data << ' ';
		}
		// output the tail
		return os << list.tail->data;
	}
	void PrintList() {
		std::cout << *this;
	}
	void PrintListReversely() {
		// NOTE: This is a quick and dirty solution.
		// There is likely a much better algorithm.
		std::string output = "";
		std::stringstream os;
		// case: list is empty
		if (head == nullptr) {
			return;
		}
		// for every node except the tail
		for (Node<T>* target = head; target->next != nullptr; target = target->next) {
				// output a whitespace and the node's data
				os << ' ' << target->data;
				output.insert(0, os.str());
				os.str(std::string());
				os.clear();
		}
		// output the tail
		os << tail->data;
		output.insert(0, os.str());
		std::cout << output;
	}
	unsigned int GetLength() {
		unsigned int sum = 0;
		// for every node
		for (Node<T>* target = head; target != nullptr; target = target->next) {
			// increment sum
			sum++;
		}
		return sum;
	}
};

int main() {
	// Declare list
	LinkedList<int> list;

	while(true) {
		// Print menu
		std::cout << "SINGLY LINKED LIST\n";
		std::cout << "---\n";
		std::cout << "0: quit\n";
		std::cout << "1: append\n";
		std::cout << "2: prepend\n";
		std::cout << "3: insert after\n";
		std::cout << "4: remove after\n";
		std::cout << "5: sort\n";
		std::cout << "\n";
		std::cout << "Choice: ";

		std::string input;
		std::getline(std::cin, input);

		if (input[0] == '0' || input[0] == 'q' || input[0] == 'Q') {
			std::cout << "Quitting...\n";
			break;
		} else if (input[0] == '1' || input[0] == 'a' || input[0] == 'A') {
			std::cout << "Data to append: ";
			std::getline(std::cin, input);
			Node<int>* node = new Node<int>(std::stoi(input));
			list.Append(node);
		} else if (input[0] == '2' || input[0] == 'p' || input[0] == 'P') {
			std::cout << "Data to prepend: ";
			std::getline(std::cin, input);
			Node<int>* node = new Node<int>(std::stoi(input));
			list.Prepend(node);
		} else if (input[0] == '3' || input[0] == 'i' || input[0] == 'I') {
			std::cout << "Data to insert: ";
			std::getline(std::cin, input);
			Node<int>* node = new Node<int>(std::stoi(input));
			std::cout << "Target data to place it after: ";
			std::getline(std::cin, input);
			Node<int>* target = list.Search(std::stoi(input));
			if (target == nullptr) {
				std::cout << "Target data not found; placing new data at the front of list.\n";
			}
			list.InsertAfter(node, target);
		} else if (input[0] == '4' || input[0] == 'r' || input[0] == 'R') {
			std::cout << "Data before the target data to remove: ";
			std::getline(std::cin, input);
			Node<int>* target = list.Search(std::stoi(input));
			if (target == nullptr) {
				std::cout << "Target data not found; deleting data at the front of list.\n";
			}
			list.RemoveAfter(target);
		} else if (input[0] == '5' || input[0] == 's' || input[0] == 'S') {
			list.Sort();
		} else {
			std::cout << "Input not recognized. Please try again.\n";
		}

		// Print list
		std::cout << "\nList: ";//  << list << "\n"
		list.PrintListReversely();
		std::cout << "\n";
		// Pause
		system("pause");
		std::cout << "\n";
	}
	// Exit
	return 0;
}