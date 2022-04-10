/* ASSIGNMENT:
 * Create an AVL Tree with the following public methods.
 * GetHeight() const
 * Search(Data data) const
 * Insert(Data data)
 * Remove(Data data)
 * operator<<(std::ostream& os, const BST& container)
 * 
 * AVL Tree Keywords:
 * node, tree, subtree, root, parent, child, left, right, ancestor,
 * descendant, depth, height, balance factor, balanced, unbalanced
 * 
 * Date: 4/10/2022
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
    // the largest depth of all descendants of this node
		int height;
		Node* parent;
		Node* left;
		Node* right;
		Node(T data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
			: data(data), parent(parent), left(left), right(right) {
			UpdateHeight();
    }
		// return the number of ancestors of this node
		// O(n)
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
		// return the balance factor of this node
		// O(1)
		// Ω(1)
		int GetBalanceFactor() {
			int leftHeight = -1;
			int rightHeight = -1;
			if (left != nullptr) {
				leftHeight = left->height;
			}
			if (right != nullptr) {
				rightHeight = right->height;
			}
			return leftHeight - rightHeight;
		}
		// update the height of this node
		// O(1)
		// Ω(1)
		void UpdateHeight() {
			int leftHeight = -1;
			int rightHeight = -1;
			if (left != nullptr) {
				leftHeight = left->height;
			}
			if (right != nullptr) {
				rightHeight = right->height;
			}
			height = 1 + std::max(leftHeight, rightHeight);
		}
		// replace the left child of this node with newNode and update the height
		// O(1)
		// Ω(1)
		void SetLeft(Node* newNode) {
			left = newNode;
			if (newNode != nullptr) {
				newNode->parent = this;
			}
			UpdateHeight();
		}
		// replace the right child of this node with newNode and update the height
		// O(1)
		// Ω(1)
		void SetRight(Node* newNode) {
			right = newNode;
			if (newNode != nullptr) {
				newNode->parent = this;
			}
			UpdateHeight();
		}
		// replace the given child of this node with newNode and update the height
		// return 0 if successful; return less than 0 if failed
		// O(1)
		// Ω(1)
		int ReplaceChild(Node* child, Node* newNode) {
			if (left == child) {
				SetLeft(newNode);
				return 0;
			}
			if (right == child) {
				SetRight(newNode);
				return 0;
			}
			return -1;
		}
		// print the data of this node & all of its descendants in order, separated by ' '
		// O(n)
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
  // swap the location of the node and its right child
	// O(1)
	// Ω(1)
	void RotateLeft(Node* node) {
		Node* rightLeftChild = node->right->left;
		// put right in the node's spot under parent
		if (node != root) {
			node->parent->ReplaceChild(node, node->right);
		} else {
			root = node->right;
			root->parent = nullptr;
		}
		// put the node as the left child of right
		node->right->SetLeft(node);
		// put the right's left child as the right child of node
		node->SetRight(rightLeftChild);
	}
  // swap the locations of the node and its left child
	// O(1)
	// Ω(1)
	void RotateRight(Node* node) {
		Node* leftRightChild = node->left->right;
		// put left in the node's spot under parent
		if (node != root) {
			node->parent->ReplaceChild(node, node->left);
		} else {
			root = node->left;
			root->parent = nullptr;
		}
		// put the node as the right child of left
		node->left->SetRight(node);
		// put the left's right child as the left child of node
		node->SetLeft(leftRightChild);
	}
  // if the node is unbalanced, and rotate it to balance it
	// O(1)
	// Ω(1)
  void Rebalance(Node* node) {
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
				RotateLeft(node->left);
			}
			RotateRight(node);
		}
  }
public:
	AVLT() : root(nullptr) {}
	// return the largest depth of all nodes in the tree
	// O(1)
	// Ω(1)
	int GetHeight() const {
		if (root == nullptr) {
			return -1;
		}
		return root->height;
	}
	// return a pointer to the first node in the tree which contains the given data
	// O(log_2(n))
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
	// insert the given node into the tree
	// return a pointer to the node
	// O(log_2(n))
	// Ω(1)
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
			// if newNode's data < target's data, it will be a descendent of target->left
			if (newNode->data < target->data) {
				// if target->left is empty
				if (target->left == nullptr) {
					// put newNode in target->left
					target->SetLeft(newNode);
					break;
				}
				// otherwise continue searching on the left of target
				else target = target->left;
			}
			// otherwise newNode will be a descendent of target->right
			else {
				// if target->right is empty
				if (target->right == nullptr) {
					// put newNode in target->right
					target->SetRight(newNode);
					break;
				}
				// otherwise continue searching on the right of target
				else target = target->right;
			}
		}
    // rebalance all ancestors of newNode
    while (target != nullptr) {
			target->UpdateHeight();
      Rebalance(target);
      target = target->parent;
    }
    return newNode;
	}
	// insert the given data into the tree within a new node
	// return a pointer to the new node
	// O(log_2(n))
	// Ω(1)
	Node* Insert(T data) {
		return Insert(new Node(data));
	}
	// remove the node from the tree
	// delete the node & its data
	// return 0 if successful; return less than 0 if failed
	// O(1)
	// Ω(1)
	int Remove(Node* node) {
		// *case | doesn't change the balance of the tree

		// *case: no node given
		if (node == nullptr) {
			return -1;
		}
		// *case: node has both children
		if (node->left != nullptr && node->right != nullptr) {
			// get the smallest child of right subtree
			Node* smallest = node->right;
			while (smallest->left != nullptr) {
				smallest = smallest->left;
			}
			// set node data to the data of the next smallest
			node->data = smallest->data;
			// delete the next smallest data from the tree
			Remove(smallest);
			return 0;
		}
    Node* parent = node->parent;
		// case: node has a left child
		if (node->left != nullptr) {
			// *case: node is root & node has only left child
			if (node == root) {
				root = node->left;
				root->parent = nullptr;
				return 0;
			}
			// case: node has parent & node has only left child
			else parent->ReplaceChild(node, node->left);
		}
		// case: node only has right child
		else if (node->right != nullptr) {
			// *case: node is root & node has only right child
			if (node == root) {
				root = node->right;
				root->parent = nullptr;
				return 0;
			}
			// case: node has parent & node has only right child
			else parent->ReplaceChild(node, node->right);
		}
		// case: node has no children
		else {
			// *case: node is root
			if (node == root) {
				root = nullptr;
				return 0;
			}
			// case: node is a left child
			else if (parent->left == node)
				parent->left = nullptr;
			// case: node is a right child
			else parent->right = nullptr;
		}
		// delete the node
		delete node;
    // rebalance all ancestors of node
    while (parent != nullptr) {
			parent->UpdateHeight();
      Rebalance(parent);
      parent = parent->parent;
    }
		return 0;
	}
	// remove & delete the first node in the tree which contains the given data
	// return 0 if successful; return less than 0 if failed
	// O(log_2(n))
	// Ω(1)
	int Remove(T data) {
		return Remove(Search(data));
	}
	// print data within the tree in order, separated by ' '
	// O(n)
	// Ω(n)
	friend std::ostream& operator<<(std::ostream& os, const AVLT& container) {
		// case: no root in tree
		if (container.root == nullptr) {
			return os;
		}
		return os << *container.root;
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
			AVLT<int>::Node* node = container.Search(std::stoi(input));
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