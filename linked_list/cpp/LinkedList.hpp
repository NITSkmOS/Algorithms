#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <ostream>

using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node *nextNode = nullptr;

        explicit Node(T data) : data(data) {}
        Node(T data, Node *nextNode) : data(data), nextNode(nextNode) {}
    };

    Node *head = nullptr;

    /**
     * Given some 'data', search through linked list and if a node containing requested data is found
     * then return the pointer to the node containing that data. If such a node is not found, it will
     * return nullptr. Additionally a 'prevNode' argument may be supplied, it will be set to the last
     * checked element before return (i.e. the previous element)
     */
    Node *findInList(const T &data, Node **prevNode = nullptr) const {
        if (prevNode != nullptr) {
            *prevNode = nullptr;
        }

        for (Node *thisNode = head; thisNode != nullptr; thisNode = thisNode->nextNode) {
            if (thisNode->data == data) {
                return thisNode;
            }

            if (prevNode != nullptr) {
                *prevNode = thisNode;
            }
        }

        return nullptr;
    }

    /**
     * Returns the Node* of the tail of the linked list
     */
    Node *getTail() const {
        Node *thisNode = head;
        while (thisNode != nullptr) {
            if (thisNode->nextNode == nullptr) {
                return thisNode;
            }

            thisNode = thisNode->nextNode;
        }

        return nullptr;
    }

public:
    LinkedList() = default;
    virtual ~LinkedList() {
        clear();
    }

    /**
     * Inserts the data 'value' in a node before the head of the list (ie index 0)
     */
    bool insertHead(T value) {
        if (findInList(value) != nullptr) {
            return false;
        }

        head = new Node(value, head);
        return true;
    }

    /**
     * Inserts the data 'value' in a node after the tail of the list (ie append)
     */
    bool insertTail(T value) {
        if (findInList(value) != nullptr) {
            return false;
        }

        Node *lastNode = getTail();
        if (lastNode == nullptr) {
            head = new Node(value);
        } else {
            lastNode->nextNode = new Node(value);
        }

        return true;
    }

    /**
     * Insert the data 'newValue' in a node after the node containing the data 'match', if no node
     * exists that contains 'match' then no nodes will be inserted
     */
    bool insertAfter(T match, T newValue) {
        if (findInList(newValue) != nullptr) {
            return false;
        }

        Node *node = findInList(match);
        if (node == nullptr) {
            return false;
        }

        node->nextNode = new Node(newValue, node->nextNode);
        return true;
    }

    /**
     * Search through the linked list, and if a node containing data 'value' is
     * found, remove said node from the list
     */
    bool remove(T value) {
        Node *prevNode;
        Node *thisNode = findInList(value, &prevNode);
        if (thisNode == nullptr) {
            return false;
        }

        if (prevNode == nullptr) {
            // We're deleting head
            head = thisNode->nextNode;
        } else {
            prevNode->nextNode = prevNode->nextNode->nextNode;
        }
        delete thisNode;
        return true;
    }

    /**
     * Remove all nodes from the list, leaving it empty
     */
    bool clear() {
        if (head == nullptr) { // Nothing to clear
            return true;
        }

        Node *lastNode = nullptr;
        for (Node *thisNode = head; thisNode != nullptr; thisNode = thisNode->nextNode) {
            if (lastNode != nullptr) {
                delete lastNode;
            }

            lastNode = thisNode;
        }

        if (lastNode != nullptr) {
            delete lastNode;
        }

        head = nullptr;

        return true;
    }

    /**
     * Retrieve the data stored in node 'index', the function returns whether or not it found data, and
     * the data will be stored in 'value'. If the list nodes store a type other than string, they will
     * be coerced to a string via std::to_string or object.toString(), in respective order. If no data
     * is found, value will remain unchanged.
     */
    bool at(int index, string &value) {
        if (index < 0) {
            return false;
        }

        Node *thisNode = head;
        for (; thisNode != nullptr && index > 0;
               thisNode = thisNode->nextNode, index--) {}

        if (thisNode == nullptr) { // Index went outside of list
            return false;
        }

        if constexpr (is_same<T, string>::value) {
            value = thisNode->data;
        } else if constexpr (is_same<T, int>::value) {
            value = to_string(thisNode->data);
        } else {
            value = thisNode->data.toString();
        }

        return true;
    }

    /**
     * Returns the count of nodes in the linked list
     */
    int size() const {
        int index = 0;
        for (Node *thisNode = head; thisNode != nullptr; thisNode = thisNode->nextNode, index++) {}

        return index;
    }

    class Iterator {
    private:
        Node *currentNode;

    public:
        explicit Iterator(Node *node) : currentNode(node) {}

        bool operator!=(const Iterator &rhs) const {
            return currentNode != rhs.currentNode;
        }

        Iterator operator++() {
            currentNode = currentNode->nextNode;
            return *this;
        }

        T operator*() const {
            return currentNode->data;
        }

        string toString() const {
            return "LinkedList::Iterator(" + to_string((size_t) currentNode) + ")";
        }

        friend ostream &operator<<(ostream &os, const Iterator &iterator) {
            os << iterator.toString();
            return os;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};


#endif //LINKEDLIST_H

