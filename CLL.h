#ifndef CLL_H
#define CLL_H

#include <iostream>

using namespace std;

/**
 * Node class
 * @tparam T The type of the data
 */
template<typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node();
    Node(T);
    Node(T, Node<T>*);
    T getData() const;
    Node<T>* getNext() const;
    void setData(T);
    void setNext(Node<T>*);
    template<typename> friend class CLL;
};

/**
 * Creates an empty node
 * @tparam T The type of the data
 */
template<typename T>
Node<T>::Node() {
    next = nullptr;
}

/**
 * Creates an empty node
 * @tparam T The type of the data
 * @param data The data to be stored
 */
template<typename T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr;
}

/**
 * Creates an empty node
 * @tparam T The type of the data
 * @param data The data to be stored
 * @param next The pointer to te next node
 */
template<typename T>
Node<T>::Node(T data, Node<T> *next) {
    this->data = data;
    this->next = next;
}

/**
 * Returns the data of the node.
 * @tparam T The type of the data
 * @return The data of the node
 */
template<typename T>
T Node<T>::getData() const {
    return data;
};

/**
 * Returns the next node.
 * @tparam T The type of the data
 * @return The next node
 */
template<typename T>
Node<T>* Node<T>::getNext() const {
    return next;
};

/**
 * Sets the data of the node
 * @tparam T The type of the data
 * @param data the data of the node
 */
template<typename T>
void Node<T>::setData(T data) {
    this->data = data;
};

/**
 * Sets the pointer to the next element.
 * @tparam T The type of the data
 * @param next The pointer to the next element
 */
template<typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
};

/**
 * Circular liked list class
 * @tparam T The type of the data
 */
template<typename T>
class CLL {
private:
    int size;
    Node<T>* tail;
public:
    CLL();
    int getSize() const;
    bool isEmpty() const;
    T getFirst() const;
    void addLast(T data);
    void removeFirst();
    void moveForward();
};

/**
 * Creates an empty circular linked list
 * @tparam T
 */
template<typename T>
CLL<T>::CLL() {
    size = 0;
}

/**
 * Returns the number of nodes in the list.
 * @tparam T The type of the data
 * @return The number of nodes in the list
 */
template<typename T>
int CLL<T>::getSize() const {
    return size;
}

/**
 * Returns whether the list is empty or not.
 * @tparam T The type of the data
 * @return Whether the list is empty or not
 */
template<typename T>
bool CLL<T>::isEmpty() const {
    return (size <= 0);
}

/**
 * Returns the first value on the list.
 * @tparam T The type of the data
 * @return The first value on the list
 */
template<typename T>
T CLL<T>::getFirst() const {
    if (tail == nullptr)
        throw runtime_error("CLL.getHead: The List is empty");

    return tail->next->data;
}

/**
 * Inserts a node at the end of the list.
 * @tparam T The type of the data
 * @param data The data to be stored
 */
template<typename T>
void CLL<T>::addLast(T data) {

    if(isEmpty()) {
        tail = new Node<T>(data);
        tail->next = tail;
    } else {
        tail->next = new Node<T>(data, tail->next);
        tail = tail->next;
    }

    size++;
}

/**
 * Inserts a node at the end of the list.
 * @tparam T The type of the data
 * @param data The data to be stored
 */
template<typename T>
void CLL<T>::removeFirst() {
    if (tail == nullptr)
        throw runtime_error("CLL.removeFromHead: The List is empty");

    Node<T>* first = tail->next;
    tail->next = tail->next->next;
    delete first;
    size--;
}

/**
 * Helper function. Goes to the next node.
 * @tparam T The type of the data
 */
template<typename T>
void CLL<T>::moveForward() {
    tail = tail->next;
}


#endif
