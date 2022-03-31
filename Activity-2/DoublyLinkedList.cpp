template <class T>
struct Node {
public:
	T data;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
	Node(T data) : data(data) {}
	Node operator=(T data) {
		this->data = data;
	}
};

template <class T>
class DoublyLinkedList {
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
		node->prev = tail;
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
		head->prev = node;
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
			node->prev = tail;
			tail = node;
			return;
		}
		// insert node after target
		node->next = target->next;
		node->prev = target;
		target->next->prev = node;
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
			} else successor->prev = nullptr;
			return;
		}
		// case: a node follows target
		if (target->next != nullptr) {
			successor = target->next->next;
			target->next = successor;
			successor->prev = target;
			// case: removed the tail
			if (successor == nullptr) {
				tail = target;
			}
			return;
		}
	}
};