/* ASSIGNMENT:
 * Create an AVL Tree with the following public methods.
 * BreadthFirstSearch(Data data, Node* startingNode) const
 * DepthFirstSearch(Data data, Node* startingNode) const
 * DijkstraShortestPath(Data data, Node* startingNode) const
 * BellmanFordShortestPath(Data data, Node* startingNode) const
 * BellmanFordMooreShortestPath(Data data, Node* startingNode) const
 * Insert(Data data)
 * Remove(Node* node)
 * TopologicalSort()
 * operator<<(std::ostream& os, const BST& container)
 * 
 * Date: 4/22/2022
 * Author: Matthew Boyea
 */

#include <iostream>
#include <string>
// singly linked list for adjacency list
#include <forward_list>
// queue and set for search/path/sort algorithms
#include <queue>
#include <set>

template<typename T>
class Graph {
public:
	struct Node {
		T data;
		std::forward_list<Node*> adjacentNodes;
		Node(T data)
			: data(data) {}
		// TODO: label function
		friend bool operator<(const Node& lhs, const Node& rhs) {
			return lhs.data < rhs.data;
		}
		// TODO: label function
		friend std::ostream& operator<<(std::ostream& os, const Node& node) {
			// print this node's data and the opening bracket
			os << node.data << '[';
			// iterate from the beginning of the adjacentNodes
			auto it = node.adjacentNodes.begin();
			// if adjacentNodes has an element
			if (it != node.adjacentNodes.end()) {
				// print the first adjacent node's data
				os << (*it)->data;
				it++;
				// while adjacentNodes has another element
				while (it != node.adjacentNodes.end()) {
					// print a space, followed by the next adjacent node's data
					os << ' ' << (*it)->data;
					it++;
				}
			}
			// print the closing bracket
			os << ']';
			return os;
		}
	};
private:
	Node* root;
	std::forward_list<Node*> adjacencyList;
public:
	Graph() : root(nullptr) {
		// insert a dummy node
		adjacencyList.push_front(nullptr);
	}
	// TODO: label function
	Node* BreadthFirstSearch(T data, Node* startingNode) const {
		// case: no starting node given
		if (startingNode == nullptr) {
			return nullptr;
		}
		// insert startingNode into searchQueue
		std::queue<Node*> searchQueue;
		searchQueue.push(startingNode);
		// insert startingNode into discoveredNodes
		std::set<Node*> discoveredNodes;
		discoveredNodes.insert(startingNode);
		// while searchQueue has remaining nodes
		Node* targetNode;
		while (!searchQueue.empty()) {
			// get the next targetNode
			targetNode = searchQueue.front();
			searchQueue.pop();
			// if targetNode has data which is being searched for
			if (targetNode->data == data) {
				// return the targetNode
				return targetNode;
			}
			// iterate over every adjacent node of targetNode
			auto it = targetNode->adjacentNodes.begin(); 
			while (it != targetNode->adjacentNodes.end()) {
				// if the adjacent node is not in discoveredNodes
				if (discoveredNodes.find(*it) == discoveredNodes.end()) {
					// insert the adjacent node into searchQueue & discoveredNodes
					searchQueue.push(*it);
					discoveredNodes.insert(*it);
				}
				it++;
			}
		}
		return nullptr;
	}
	// TODO: label function
	Node* BreadthFirstSearch(T data) const {
		return BreadthFirstSearch(data, root);
	}
	// TODO: label function
	Node* DepthFirstSearch(T data, Node* startingNode) const {
		// case: no starting node given
		if (startingNode == nullptr) {
			return nullptr;
		}
		// TODO: implement depth search from startingNode
		return nullptr;
	}
	// TODO: label function
	Node* DepthFirstSearch(T data) const {
		return DepthFirstSearch(data, root);
	}
	// TODO: label function
	std::queue<Node*> DijkstraShortestPath(T data, Node* startingNode) const {
		// case: no starting node given
		if (startingNode == nullptr) {
			return nullptr;
		}
		// TODO: dijkstra's shortest path from startingNode
		return nullptr;
	}
	// TODO: label function
	std::queue<Node*> DijkstraShortestPath(T data) const {
		return DijkstraShortestPath(data, root);
	}
	// TODO: label function
	Node* Insert(T data, Node* adjacentNode) {
		Node* newNode = new Node(data);
		// if adjacentNode isn't given
		if (adjacentNode == nullptr) {
			// if root is empty, insert newNode into root
			if (root == nullptr) {
				root = newNode;
			}
			// otherwise node is in root; return nothing
			else {
				delete newNode;
				return nullptr;
			}
		}
		// otherwise set newNode as adjacent to adjacentNode
		else adjacentNode->adjacentNodes.push_front(newNode);
		// insert newNode into adjacencyList
		adjacencyList.push_front(newNode);
		return newNode;
	}
	// TODO: label function
	Node* Insert(T data) {
		return Insert(data, root);
	}
	// TODO: label function
	char Remove(Node* node) {
		// case: no node given
		if (node == nullptr) {
			return -1;
		}
		// iterate over every element in adjacencyList
		for (auto it = adjacencyList.before_begin(); *std::next(it) != nullptr; it++) {
			// delete every occurance of the removed node in the element
			(*std::next(it))->adjacentNodes.remove(node);
		}
		return 0;
	}
	// TODO: label function
	friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
		std::cout << graph.root << '\n';
		// iterate from the beginning of adjacencyList
		auto it = graph.adjacencyList.begin();
		// if the graph has a node
		if (*it != nullptr) {
			// print the first node
			os << **it;
			it++;
			// while the graph has another node
			while (*it != nullptr) {
				// print a newline, followed by the next node
				os << std::endl << **it;
				it++;
			}
		}
		return os;
	}
};

int main() {
	// declare container
	Graph<int> container;
	// print title
	std::cout << "GRAPH\n";
	std::cout << "---\n";
	while(true) {
		// print container
		std::cout << "CONTAINER:\n";
		std::cout << container << "\n";
		// print commands
		std::cout << "COMMANDS:\n";
		std::cout << " 0: quit\n";
		std::cout << " 1: insert\n";
		std::cout << " 2: remove\n";
		std::cout << " 3: depth search\n";
		std::cout << " 4: breadth search\n";
		std::cout << " 5: dijkstra's shortest path\n";
		std::cout << " 6: bellman-ford shortest path\n";
		// print input request
		std::cout << "Insert command: ";
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
			std::cout << "Insert data(int): ";
			std::getline(std::cin, input);
			std::cout << "Data inserted at memory address " << container.Insert(std::stoi(input)) << "\n";
		} else if (input[0] == '2' || input[0] == 'R' || input[0] == 'r') {
			// REMOVE DATA
			std::cout << "Insert data(int): ";
			std::getline(std::cin, input);
			if (container.Remove(container.BreadthFirstSearch(std::stoi(input))) < 0)
				std::cout << "Data not found; the data could not be removed\n";
			else
				std::cout << "Data removed\n";
		} else if (input[0] == '3' || input[0] == 'D' || input[0] == 'd') {
			// DEPTH SEARCH FOR DATA
			std::cout << "Insert data(int): ";
			std::getline(std::cin, input);
			Graph<int>::Node* node = container.DepthFirstSearch(std::stoi(input));
			if (node == nullptr)
				std::cout << "Data not found\n";
			else
				std::cout << "Data found at memory address " << node << "\n";
		} else if (input[0] == '4' || input[0] == 'B' || input[0] == 'b') {
			// BREADTH SEARCH FOR DATA
			std::cout << "Insert data(int): ";
			std::getline(std::cin, input);
			Graph<int>::Node* node = container.BreadthFirstSearch(std::stoi(input));
			if (node == nullptr)
				std::cout << "Data not found\n";
			else
				std::cout << "Data found at memory address " << node << "\n";
		} else if (input[0] == '5' || input[0] == 'D' || input[0] == 'd') {
			// DIJKSTRA'S SHORTEST PATH
			std::cout << "Insert data(int): ";
			std::getline(std::cin, input);
			std::queue<Graph<int>::Node*> path = container.DijkstraShortestPath(std::stoi(input));
			if (path.empty())
				std::cout << "Data not found\n";
			else {
				std::cout << "Path found:\n";
				while (!path.empty()) {
					std::cout << path.front() << ':' << path.front()->data << '\n';
					path.pop();
				}
			}
		} else {
			std::cout << "Input not recognized. Please try again.\n";
		}
		// print spacer
		std::cout << "\n";
	}
	// exit program
	return 0;
}