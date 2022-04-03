/* ASSIGNMENT:
 * Create a binary search tree with the following methods.
 * Insert(Data target)
 * Search(Data target)
 * Remove(Data target)
 * OrderedPrint()
 * operator<<(std::ostream os, BST)
 * GetHeight()
 * 
 * Date: 3/30/2022
 * Author: Matthew Boyea
 */

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

// Binary Search Tree ADT
template<typename T>
class BST {
public:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node* parent;
		Node(T data, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr)
			: data(data), left(left), right(right), parent(parent) {}
		friend std::ostream& operator<<(std::ostream& os, const Node& node) {
			// if left has node, print it first
			if (node.left != nullptr) {
				os << *node.left << ' ';
			}
			// print this node's data
			os << node.data;
			// if right has node, print it last
			if (node.right != nullptr) {
				os << ' ' << *node.right;
			}
			return os;
		}
	};
protected:
	Node* root;
public:
	BST() : root(nullptr) {}
	Node* Search(T data) const {
		// search for data from the root
		Node* target = root;
		while (true) {
			// if target == nullptr, data not found
			if (target == nullptr) {
				return nullptr;
			}
			// if data == target's data, return target
			if (data == target->data) {
				return target;
			}
			// if data < target's data, search left
			if (data < target->data) {
				target = target->left;
				continue;
			}
			// data > target's data; search right
			target = target->right;
			continue;
		}
	}
	Node* Insert(T data) {
		// case: no root in tree
		if (root == nullptr) {
			// put data into the root
			root = new Node(data);
			return root;
		}
		// search for empty location from the root
		Node* target = root;
		while (true) {
			// if data < target's data, it is placed to the left
			if (data < target->data) {
				if (target->left == nullptr) {
					// put data on the left of target
					target->left = new Node(data);
					return target->left;
				}
				// continue searching on the left of target
				target = target->left;
				continue;
			}
			// otherwise it is placed to the right
			else {
				if (target->right == nullptr) {
					// put data on the right of target
					target->right = new Node(data);
					return target->right;
				}
				// continue searching on the right of target
				target = target->right;
			}
		}
	}
	void Remove(T data) {
		Node parent = nullptr;
		Node target = root;
		while (target != nullptr) {
			return;
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const BST& tree) {
		// case: no root in tree
		if (tree.root == nullptr) {
			return os;
		}
		return os << *tree.root;
	}
};

int main() {
	// Declare container
	BST<int> container;

	while(true) {
		// Print container
		std::cout << "Container: " << container << "\n";
		// Print menu
		std::cout << "BINARY SEARCH TREE\n";
		std::cout << "---\n";
		std::cout << "0: quit\n";
		std::cout << "1: insert\n";
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
			container.Insert(std::stoi(input));
		} else {
			std::cout << "Input not recognized. Please try again.\n";
		}
		std::cout << "\n";
	}
	// exit program
	return 0;
}