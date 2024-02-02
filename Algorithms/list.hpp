//
//  list.hpp
//  Algorithms
//
//  Created by Manish Patidar on 21/01/24.
//

#ifndef list_hpp
#define list_hpp

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <class T>
class List {
    Node<T> *head;
    Node<T> *tail;
    
    Node<T>* createNode() {
        return new Node<T>;
    }
    
public:
    List(): head(nullptr), tail(nullptr) {}
    
    //O(1)
    void addAtFirst(T info) {
        Node<T> *newNode = createNode();
        newNode->data = info;
        if (head == NULL) {
            head = newNode;
            newNode->next = NULL;
        } else {
            newNode->next = head;
            head = newNode;
        }
        tail = newNode;
    }
    
    //Without using tail- O(N)
    void addAtLast(T info) {
        Node<T> *newNode = createNode();
        newNode->data = info;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            //reaching to the current last node ?
            Node<T>* temp = head;
            while( temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        tail = newNode;
    }
    
    //with Tail-> O(1)
    void pushBack(T info) {
        Node<T> *newNode = createNode();
        newNode->data = info;
        newNode->next = NULL;
        tail->next = newNode;
    }
    
    //O(N)
    void iterateList() {
        for (Node<T>* it = head; it != NULL; it = it->next) {
            cout<<it->data<<endl;
        }
    }
    
    //Linear Search - O(N)
    bool search(T info) {
        for (Node<T>* it = head; it != NULL; it = it->next) {
            if (it->data == info) {
                return true;
            }
        }
        return false;
    }
    
    //sort-
    void sort();
    
    //deleteAtLast- using tail- O(1)
    void deleteAtLast() {
        //TODO: delte last node
    }
    
    //O(1)
    void deleteAtFirst() {
        //TODO:
    }
    
    void insertAtPosition(int position) {
        //TODO: Insert at Position!
    }
    
    //O(n)
    void deleteAtPosition(int position) {
        //TODO: delete at Position
    }
    
    class Iterator {
    private:
        Node<T>* current;
        
    public:
        Iterator(Node<T>* startNode) : current(startNode) {}
        
        // Overload the * operator to get the value of the current node
        T& operator*() {
            return current->data;
        }
        
        // Overload the ++ operator to move to the next node
        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }
        
        // Overload the != operator to check for inequality
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    
    // Function to get the iterator pointing to the beginning of the linked list
    Iterator begin() const {
        return Iterator(head);
    }
    
    // Function to get the iterator pointing to the end of the linked list
    Iterator end() const {
        return Iterator(nullptr);
    }
};

template <typename T>
void List<T>::sort() {
    cout<<"sort"<<endl;
}

#endif /* list_hpp */
