#include "LinkedList.h"
#include <iostream>
#include <stdexcept>

template <typename T>
T LinkedList<T>::get(int index) const {
    if (index < 0 || index >= listSize) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current->getData();
}

template <typename T>
int LinkedList<T>::find(T val) const {
    Node<T>* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->getData() == val) {
            return index;
        }
        current = current->getNext();
        ++index;
    }
    // Si no se encuentra nada:
    return -1;
}

template <typename T>
void LinkedList<T>::insert(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        // newNode.setNext(current->getNext());
        current->setNext(newNode);
    }
    this->listSize++;
}

template <typename T>
void LinkedList<T>::insertAt(T val, int index) {
    if (index < 0 || index > listSize) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* newNode = new Node<T>(val);
    if (index == 0) {
        newNode->setNext(head);
        head = newNode;
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index-1; i++) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
    this->listSize++;
}

template <typename T>
T LinkedList<T>::remove(int index) {
    if (index < 0 || index >= listSize) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* toDelete;
    if (index == 0) {
        toDelete = head;
        head = head->getNext();
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index-1; i++) {
            current = current->getNext();
        }
        toDelete = current->getNext();
        current->setNext(toDelete->getNext());
    }
    T data = toDelete->getData();
    delete toDelete;
    this->listSize--;
    return data;
}

template <typename T>
void LinkedList<T>::toString() const {
    Node<T>* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->getData();
        current = current->getNext();
        if (current != nullptr) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
