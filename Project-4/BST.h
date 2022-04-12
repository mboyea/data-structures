//
//  BST.h
//  CSCI251Proj4
//
//  Created by Hongbiao Zeng on 4/27/19.
//  Copyright © 2019 Hongbiao Zeng. All rights reserved.
//

#ifndef BST_h 
#define BST_h
#include <string>
#include <cmath>
using namespace std;

template <class T>
struct TreeNode;

template <class T>
ostream& operator << (ostream& os, const TreeNode<T>& node);

template <class T>
class BST;

template <class T>
ostream& operator << (ostream& os, const BST<T>& tree);


template <class T>
class TreeNode{
public:
    T data;
    TreeNode<T>* parent;
    TreeNode<T>* left;
    TreeNode<T>* right;
	TreeNode(T data, TreeNode<T>* parent = nullptr, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr)
		: data(data), parent(parent), left(left), right(right) {}
    friend ostream& operator << (ostream& os, const TreeNode<T>& node){
        os << node.data << "(";
        if(node.left != NULL)
            os << *(node.left);
        else os << "_";
        os << ", ";
        if(node.right != NULL)
            os << *(node.right);
        else os <<"_";
        os << ")";
        return os;
    }
};

// ******** the following help function is for
//          class TreeNode object ************
template <class T>
bool isLeaf(TreeNode<T>* node){
    if(node == NULL) return false;
    return (node->left == NULL && node->right == NULL);
}

template <class T>
bool isRight(TreeNode<T>* node){
    if(node == NULL || node->parent == NULL) return false;
    return node == node->parent->right;
}

template <class T>
bool isLeft(TreeNode<T>* node){
    if(node == NULL || node->parent == NULL) return false;
    return node == node->parent->left;
}

template <class T>
bool isRoot(TreeNode<T>* node){
    if(node == NULL) return false;
    return node->parent == NULL;
}

template <class T>
int treeHeight(TreeNode<T>* node){
    if(node == NULL) return -1;
    return 1 + max(treeHeight(node->left), treeHeight(node->right));
}

template <class T>
int treeSize(TreeNode<T>* node){
    if(node == NULL)
        return 0;
    return 1 + treeSize(node->left) + treeSize(node->right);
}

template <class T>
class BST{
private:
    TreeNode<T>* root;
    bool remove(TreeNode<T>* node) {
		// case: no node given
		if (node == nullptr) {
			return false;
		}
		// case: node has no children
		if (node->left == nullptr && node->right == nullptr) {
			// case: node is the root
			if (root == node) {
				root = nullptr;
				delete node;
				return true;
			}
			// case: node is a left child
			if (node->parent->left == node) {
				node->parent->left = nullptr;
				delete node;
				return true;
			}
			// case: node is a right child
			node->parent->right = nullptr;
			delete node;
			return true;
		}
		// case: node has only left child
		if (node->right == nullptr) {
			// case: node is the root
			if (root == node) {
				root = node->left;
				delete node;
				return true;
			}
			// case: node is a left child
			if (node->parent->left == node) {
				node->parent->left = node->left;
				delete node;
				return true;
			}
			// case: node is a right child
			if (node->parent->right == node) {
				node->parent->right = node->left;
				delete node;
				return true;
			}
		}
		// case: node has only right child
		if (node->left == nullptr) {
			// case: node is the root
			if (root == node) {
				root = node->right;
				delete node;
				return true;
			}
			// case: node is a left child
			if (node->parent->left == node) {
				node->parent->left = node->right;
				delete node;
                return true;
			}
			// case: node is a right child
			node->parent->right = node->right;
			delete node;
            return true;
		}
		// case: node has both children
		// get smallest child of right subtree
		TreeNode<T>* smallest = node->right;
		while (smallest->left != nullptr) {
			smallest = smallest->left;
		}
		node->data = smallest->data;
		remove(smallest);
        return true;
    }
public:
    friend ostream& operator << (ostream& os, const BST<T>& tree){
        os << *(tree.root);
        return os;
    }
    BST() : root(nullptr) {}
    TreeNode<T>* search(const T& data) const {
		// search for data from the root
		TreeNode<T>* target = root;
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
    void insert(T data) {
        TreeNode<T>* newNode = new TreeNode<T>(data);
		// case: no root in tree
		if (root == nullptr) {
			// put data into the root
			root = newNode;
			return;
		}
		// search for empty location from the root
		TreeNode<T>* target = root;
		while (true) {
			// if newNode's data < target's data, it will be a descendent of target->left
			if (newNode->data < target->data) {
				// if target->left is empty
				if (target->left == nullptr) {
					// put newNode in target->left
			        target->left = newNode;
				    newNode->parent = target;
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
					target->right = newNode;
                    newNode->parent = target;
					break;
				}
				// otherwise continue searching on the right of target
				else target = target->right;
			}
		}
    }
    TreeNode<T>* successor(TreeNode<T>* node) const {
        // case: no node given
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode<T>* target = node->right;
        // case: 
        if (target != nullptr) {
            while (target->left != nullptr) {
                target = target->left;
            }
            return target;
        }
        target = node->parent;
        while (target != nullptr) {

        }
        // case: 
        return nullptr;
    }
    bool remove(T& data) {
        return remove(search(data));
    }
    bool isEmpty() const {
        return root == nullptr;
    }
    int height() const {
        return treeHeight(root);
    }
    int size() const {
        return treeSize(root);
    }
    TreeNode<T>* getRoot() const {
        return root;
    }
};

#endif /* BST_h */
