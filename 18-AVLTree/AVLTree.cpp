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
class AVLT {
public:
	struct Node {
		T data;
		int height;
		Node* left;
		Node* right;
		Node* parent;
		Node(T data, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr)
			: data(data), left(left), right(right), parent(parent) {}
		void UpdateHeight() {
			int leftHeight = -1;
			int rightHeight = -1;
			if (left != nullptr) {
				leftHeight = left->height;
			}
			if (right != nullptr) {
				rightHeight = right->height;
			}
			height = std::max(leftHeight, rightHeight) + 1;
		}
		int GetBalanceFactor() {
			int leftHeight = -1;
			int rightHeight = -1;
			if (left != nullptr) {
				leftHeight = left->height;
			}
			if (right != nullptr) {
				rightHeight = right->height;
			}
			height = leftHeight - rightHeight;
		}
		void SetLeftChild(Node* newChild) {
			left = newChild;
			UpdateHeight();
		}
		void SetRightChild(Node* newChild) {
			right = newChild;
			UpdateHeight();
		}
		int ReplaceChild(Node* currentChild, Node* newChild) {
			if (left == currentChild) {
				SetLeftChild(newChild);
				return 1
			}
			if (right == currentChild) {
				SetRightChild(newChild);
				return -1;
			}
			return 0;
		}
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
	AVLT() : root(nullptr) {}
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
	void RotateLeft(Node* node) {
		Node* rightLeftChild = node->right->left;
		if (node->parent != nullptr) {
			node->parent->ReplaceChild(node, node->right)
		} else {
			root = node->right;
			root->parent = nullptr;
		}
		node->right->SetLeftChild(node);
		node->SetRightChild(rightLeftChild);
	}
	void RotateRight(Node* node) {
		Node* leftRightChild = node->left->right;
		if (node->parent != nullptr) {
			node->parent->ReplaceChild(node, node->left);
		} else {
			root = node->left;
			root->parent = nullptr;
		}
		node->left->SetRightChild(node);
		node->SetLeftChild(leftRightChild);
	}
	void Rebalance(Node* node) {
		node->UpdateHeight();
		int balanceFactor = node->GetBalanceFactor();
		// case: node has more right children
		if (balanceFactor == -2) {
			// case: node's right child has more left children
			if (node->right->GetBalanceFactor() == 1) {
				RotateRight(node->right);
			}
			RotateLeft(node);
		}
		// case: node has more left children
		else if (balanceFactor == 2) {
			// case: node's left child has more right children
			if (node->left->GetBalanceFactor() == -1) {
				RotateLeft(node);
			}
			RotateRight(node);
		}
	}
	Node* Insert(Node* newNode) {
		// case: no root in tree
		if (root == nullptr) {
			// put data into the root
			root = newNode;
			return root;
		}
		// search for empty location from the root
		Node* target = root;
		while (true) {
			// if newNode's data < target's data, it is placed in target->left
			if (newNode->data < target->data) {
				// if target->left is empty
				if (target->left == nullptr) {
					// put data in target->left
					target->left = newNode;
					newNode->parent = target;
					break;
				}
				// otherwise continue searching on the left of target
				else target = target->left;
			}
			// otherwise newNode is placed in target->right
			else {
				// if target->right is empty
				if (target->right == nullptr) {
					// put data in target->right
					target->right = newNode;
					newNode->parent = target;
					break;
				}
				// otherwise continue searching on the right of target
				else target = target->right;
			}
		}
		while (target != nullptr) {
			Rebalance(target);
			target = target->parent;
		}
		return newNode;
	}
	Node* Insert(T data) {
		return Insert(new Node(data));
	}
	void Remove(T data) {
		Node parent = nullptr;
		Node target = root;
		while (target != nullptr) {
			return;
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const AVLT& tree) {
		// case: no root in tree
		if (tree.root == nullptr) {
			return os;
		}
		return os << *tree.root;
	}
};

int main() {
	// Declare container
	AVLT<int> container;

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