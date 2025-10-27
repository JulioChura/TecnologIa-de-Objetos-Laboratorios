#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
    
    private:
        Node<T>* head;
        int listSize;
    
    public:
        LinkedList() : head(nullptr), listSize(0) {}
        ~LinkedList() {
            Node<T>* current = head;
            while (current != nullptr) {
                Node<T>* nextNode = current->getNext();
                delete current;
                current = nextNode;
            }
        }

        inline int size() const { return listSize; }
        inline bool isEmpty() const { return listSize == 0; }

        T get(int index) const;
        int find(T val) const;
        void insert(T val);
        void insertAt(T val, int index);
        T remove(int index);
        void toString() const;
};

#include "../src/LinkedList.tpp"
#endif