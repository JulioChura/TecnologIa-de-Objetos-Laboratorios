#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    
    private:
        T data;
        Node* next;

    public:
        Node(T val) : data(val), next(nullptr) {}
        inline T getData() const { return data; }
        inline void setData(T val) { data = val; }
        inline Node* getNext() const { return next; }
        inline void setNext(Node* nextNode) { next = nextNode; }
        
};

#endif