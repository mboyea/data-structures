/* ASSIGNMENT:
 * Create a binary search tree with the following methods.
 * GetHeight() const
 * Search(Data data) const
 * Insert(Data data)
 * Remove(Data data)
 * operator<<(std::ostream& os, const BST& container)
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
		Node* parent;
		Node* left;
		Node* right;
		Node(T data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
			: data(data), parent(parent), left(left), right(right) {}
		// return the largest depth of all child nodes
		// O(n)
		// Θ(1)
		// Ω(1)
		int GetHeight() const {
			int leftHeight = -1;
			int rightHeight = -1;
			if (left != nullptr) {
				leftHeight = left->GetHeight();
			}
			if (right != nullptr) {
				rightHeight = right->GetHeight();
			}
			return 1 + std::max(leftHeight, rightHeight);
		}
		// return the number of parent nodes
		// O(n)
		// Θ(1)
		// Ω(1)
		int GetDepth() const {
			int depth = 0;
			Node* target = parent;
			while (target != nullptr) {
				depth++;
				target = target->parent;
			}
			return depth;
		}
		// print the data of this node & all of its children in order, separated by ' '
		// O(n)
		// Θ(n)
		// Ω(n)
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
	// return the largest depth of all nodes in the tree
	// O(n)
	// Θ(n)
	// Ω(n)
	int GetHeight() const {
		if (root == nullptr) {
			return -1;
		}
		return root->GetHeight();
	}
	// return a pointer to the first node in the tree which contains the given data
	// O(n)
	// Θ(log_2(n))
	// Ω(1)
	Node* Search(T data) const {
		// search for data from the root
		Node* target = root;
		while (target != nullptr) {
			// if data == target's data, node found
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
		// node not found
		return nullptr;
	}
	// insert the given data into the tree within a new node
	// return a pointer to the new node
	// O(n)
	// Θ(log_2(n))
	// Ω(1)
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
					target->left = new Node(data, target);
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
					target->right = new Node(data, target);
					return target->right;
				}
				// continue searching on the right of target
				target = target->right;
			}
		}
	}
	// remove the node from the tree
	// delete the node & its data
	// return 0 if successful; return less than 0 if failed
	// O(1)
	// Θ(1)
	// Ω(1)
	int Remove(Node* node) {
		// case: no node given
		if (node == nullptr) {
			return -1;
		}
		// case: node has no children
		if (node->left == nullptr && node->right == nullptr) {
			// case: node is the root
			if (root == node) {
				root = nullptr;
				delete node;
				return 0;
			}
			// case: node is a left child
			if (node->parent->left == node) {
				node->parent->left = nullptr;
				delete node;
				return 0;
			}
			// case: node is a right child
			node->parent->right = nullptr;
			delete node;
			return 0;
		}
		// case: node has only left child
		if (node->right == nullptr) {
			// case: node is the root
			if (root == node) {
				root = node->left;
				delete node;
				return 0;
			}
			// case: node is a left child
			if (node->parent->left == node) {
				node->parent->left = node->left;
				delete node;
				return 0;
			}
			// case: node is a right child
			if (node->parent->right == node) {
				node->parent->right = node->left;
				delete node;
				return 0;
			}
		}
		// case: node has only right child
		if (node->left == nullptr) {
			// case: node is the root
			if (root == node) {
				root = node->right;
				delete node;
				return 0;
			}
			// case: node is a left child
			if (node->parent->left == node) {
				node->parent->left = node->right;
				delete node;
				return 0;
			}
			// case: node is a right child
			node->parent->right = node->right;
			delete node;
			return 0;
		}
		// case: node has both children
		// get smallest child of right subtree
		Node* smallest = node->right;
		while (smallest->left != nullptr) {
			smallest = smallest->left;
		}
		node->data = smallest->data;
		Remove(smallest);
		return 0;
	}
	// remove & delete the first node in the tree which contains the given data
	// return 0 if successful; return less than 0 if failed
	// O(n)
	// Θ(log_2(n))
	// Ω(1)
	int Remove(T data) {
		return Remove(Search(data));
	}
	// print data within the tree in order, separated by ' '
	// O(n)
	// Θ(n)
	// Ω(n)
	friend std::ostream& operator<<(std::ostream& os, const BST& container) {
		// case: no root in tree
		if (container.root == nullptr) {
			return os;
		}
		return os << *container.root;
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
		std::cout << "2: remove\n";
		std::cout << "3: search\n";
		std::cout << "4: height (print)\n";
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
			std::cout << "Data(int): ";
			std::getline(std::cin, input);
			container.Insert(std::stoi(input));
			std::cout << "Data inserted.\n";
		} else if (input[0] == '2' || input[0] == 'R' || input[0] == 'r') {
			// REMOVE DATA
			std::cout << "Data(int): ";
			std::getline(std::cin, input);
			if (container.Remove(std::stoi(input)) < 0)
				std::cout << "Data not found; the data could not be removed.\n";
			else
				std::cout << "Data removed.\n";
		} else if (input[0] == '3' || input[0] == 'S' || input[0] == 's') {
			// SEARCH FOR DATA
			std::cout << "Data(int): ";
			std::getline(std::cin, input);
			BST<int>::Node* node = container.Search(std::stoi(input));
			if (node == nullptr)
				std::cout << "Data not found.\n";
			else
				std::cout << "Data found at memory address " << node << ".\n";
		} else if (input[0] == '4' || input[0] == 'H' || input[0] == 'h') {
			// HEIGHT
			std::cout << "The height of the tree is: " << container.GetHeight() << "\n";
			system("pause");
		} else {
			std::cout << "Input not recognized. Please try again.\n";
		}
		std::cout << "\n";
	}
	// exit program
	return 0;
}