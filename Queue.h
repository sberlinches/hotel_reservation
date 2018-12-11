#ifndef QUEUE_H
#define QUEUE_H

#include "CLL.h"

/**
 * Queue class
 * @tparam T The type of the data
 */
template<typename T>
class Queue {
private:
    CLL<T> list;
public:
    Queue();
    int getSize() const;
    bool isEmpty() const;
    const T front() const;
    void enqueue(const T);
    void dequeue();
    void moveForward();
};

/**
 * Creates an empty queue
 * @tparam T The type of the data
 */
template<typename T>
Queue<T>::Queue() {}

/**
 * Returns the numbers of elements in the queue.
 * @tparam T The type of the data
 * @return The numbers of elements in the queue
 */
template<typename T>
int Queue<T>::getSize() const {
    return list.getSize();
}

/**
 * Checks and returns whether the queue is empty or not.
 * @tparam T The type of the data
 * @return Whether the queue is empty or not
 */
template<typename T>
bool Queue<T>::isEmpty() const {
    return list.isEmpty();
}

/**
 * Returns a reference to the item at the top of the stack.
 * @tparam T The type of the data
 * @return A reference to the item at the top of the stack
 */
template<typename T>
const T Queue<T>::front() const {
    return list.getFirst();
}

/**
 * Enqueue an element at rear of the queue
 * @tparam T The type of the data
 */
template<typename T>
void Queue<T>::enqueue(const T data) {
    list.addLast(data);
}

/**
 *
 * @tparam T The type of the data
 */
template<typename T>
void Queue<T>::dequeue() {
    list.removeFirst();
}

/**
 * Helper function. Goes to the next node.
 * @tparam T The type of the data
 */
template<typename T>
void Queue<T>::moveForward() {
    list.moveForward();
}

#endif
