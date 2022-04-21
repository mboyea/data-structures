/* ASSIGNMENT:
 * Create an AVL Tree with the following public methods.
 * DepthFirstSearch(Data data, Node* startingNode) const
 * BreadthFirstSearch(Data data, Node* startingNode) const
 * DijkstraShortestPath(Node* startingNode) const
 * TropologicalSort()
 * Insert(Data data)
 * Remove(Node* node)
 * operator<<(std::ostream& os, const BST& container)
 * 
 * Date: 4/22/2022
 * Author: Matthew Boyea
 */

#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <map>
#include <vector>

template<typename T>
class Graph {
public:
	struct Node {
		T data;
		std::forward_list<Node*> adjacentNodes;
		Node(T data)
			: data(data) {}
		friend bool operator<(const Node& lhs, const Node& rhs) {
			return lhs.data < rhs.data;
		}
		friend std::ostream& operator<<(std::ostream& os, const Node& node) {
			// print this node's data and the opening bracket
			os << node->data << '[';
			// iterate from the beginning of the adjacentNodes
			auto it = node->adjacentNodes.begin();
			// if adjacentNodes has an element
			if (it != node->adjacentNodes.end()) {
				// print the first adjacent node's data
				os << *it->data;
				it++;
				// while adjacentNodes has another element
				while (it != node->adjacentNodes.end()) {
					// print a space, followed by the next adjacent node's data
					os << ' ' << *it->data;
					it++;
				}
			}
			// print the closing bracket
			os << ']';
			return os;
		}
	};
private:
	std::forward_list<Node*> nodes;
public:
	Graph() {}
	Node* DepthFirstSearch(T data, Node* startingNode) const {
		// TODO: implement depth search from startingNode
		return nullptr;
	}
	Node* DepthFirstSearch(T data) const {
		return DepthFirstSearch(data, nodes.front());
	}
	Node* BreadthFirstSearch(T data, Node* startingNode) const {
		// TODO: implement breadth search from startingNode
		return nullptr;
	}
	Node* BreadthFirstSearch(T data) const {
		return BreadthFirstSearch(data, nodes.front());
	}
	Node* Insert(T data) {
		// TODO: implement insert function
		return nullptr;
	}
	int Remove(Node* node) {
		// TODO: implement remove function
		return -1;
	}
	friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
		// iterate from the beginning of nodes
		auto it = graph.nodes.begin();
		// if the graph has a node
		if (it != graph.nodes.end()) {
			// print the first node
			os << *it;
			it++;
			// while the graph has another node
			while (it != graph.nodes.end()) {
				// print a newline, followed by the next node
				os << std::endl << *it;
				it++;
			}
		}
		// otherwise the graph is empty
		else {
			os << "empty";
		}
		return os;
	}
};

int main() {
	// Declare container
	Graph<int> container;

	while(true) {
		// Print container
		std::cout << "Container: " << container << "\n";
		// Print menu
		std::cout << "BINARY SEARCH TREE\n";
		std::cout << "---\n";
		std::cout << "0: quit\n";
		std::cout << "1: insert\n";
		std::cout << "2: remove\n";
		std::cout << "3: depth search\n";
		std::cout << "4: breadth search\n";
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
			if (container.Remove(container.BreadthFirstSearch(std::stoi(input))) < 0)
				std::cout << "Data not found; the data could not be removed.\n";
			else
				std::cout << "Data removed.\n";
		} else if (input[0] == '3' || input[0] == 'D' || input[0] == 'd') {
			// DEPTH SEARCH FOR DATA
			std::cout << "Data(int): ";
			std::getline(std::cin, input);
			Graph<int>::Node* node = container.DepthFirstSearch(std::stoi(input));
			if (node == nullptr)
				std::cout << "Data not found.\n";
			else
				std::cout << "Data found at memory address " << node << ".\n";
		} else if (input[0] == '4' || input[0] == 'B' || input[0] == 'b') {
			// BREADTH SEARCH FOR DATA
			std::cout << "Data(int): ";
			std::getline(std::cin, input);
			Graph<int>::Node* node = container.BreadthFirstSearch(std::stoi(input));
			if (node == nullptr)
				std::cout << "Data not found.\n";
			else
				std::cout << "Data found at memory address " << node << ".\n";
		} else {
			std::cout << "Input not recognized. Please try again.\n";
		}
		std::cout << "\n";
	}
	// exit program
	return 0;
}