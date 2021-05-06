//
//  main.cpp
//  LinkedList
//
//  Created by Luca Greco on 05/05/21.
//  Copyright © 2021 Luca Greco. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T> class LinkedList;
template <typename T> ostream& operator<<(ostream&, const LinkedList<T>&);

template <typename T>
class LinkedList {
private:
    class Node;
    Node * head;
public:
    LinkedList ();
    ~LinkedList ();
    Node * begin () const;
    Node * end () const;
    unsigned int size () const;
    bool empty () const;
    T& operator[](int);
    const T& operator[](int) const;
    T front () const;
    T back () const;
    void push_back (T);
    void pop_back ();
    Node erase (int);
    const Node insert (int, T);
    void clear();
    friend ostream& operator<< <T>(ostream&, const LinkedList<T>&) ;
};

template <typename T>
class LinkedList<T>::Node {
private:
    Node * prev;
    Node * next;
    T key;
    friend class LinkedList<T>;
};

template <typename T>
LinkedList<T>::LinkedList (){
    head = new Node;
    head->prev = head;
    head->next = head;
    head->key = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList (){
    clear();
    delete head;
}

template <typename T>
typename LinkedList<T>::Node * LinkedList<T>::begin () const { return this->head->next; }

template <typename T>
typename LinkedList<T>::Node * LinkedList<T>::end () const { return this->head; }

template <typename T>
unsigned int LinkedList<T>::size () const {
    unsigned int size = 0;
    for (auto it = begin(); it != end(); it=it->next)
        size++;
    return size;
}

template <typename T>
bool LinkedList<T>::empty () const { return size() == 0; }

template <typename T>
T& LinkedList<T>::operator[](int index) {
    auto it = begin();
    for (int i = 0; i < index; i++)
        it++;
    return it->key;
}

template <typename T>
const T& LinkedList<T>::operator[](int index) const {
    auto it = begin();
    for (int i = 0; i < index; i++)
        it=it->next;
    return it->key;
}

template <typename T>
T LinkedList<T>::front () const { return head->next->key; }

template <typename T>
T LinkedList<T>::back () const { return head->prev->key; }

template <typename T>
void LinkedList<T>::push_back(T val){
    Node * newNode = new Node;
    newNode->prev = head->prev;
    newNode->next = head;
    newNode->key = val;
    head->prev->next = newNode;
    head->prev = newNode;
}

template <typename T>
void LinkedList<T>::pop_back(){
    Node * toDelete = head->prev;
    head->prev->prev->next = head;
    head->prev = head->prev->prev;
    delete toDelete;
}

template <typename T>
typename LinkedList<T>::Node LinkedList<T>::erase(int index){
    auto it = begin();
    for (int i = 0; i < index; i++){
        it=it->next;
    }
    Node * toDelete = it;
    it->prev->next = it->next;
    it->next->prev = it->prev;
    delete toDelete;
    return *toDelete;
}

template <typename T>
const typename LinkedList<T>::Node LinkedList<T>::insert(int index, T val){
    auto it = begin();
    for (int i = 0; i < index; i++){
        it=it->next;
    }
    Node * newNode = new Node;
    newNode->key = val;
    it->prev->next = newNode;
    newNode->prev = it->prev;
    it->prev = newNode;
    newNode->next = it;
    return *newNode;
}

template <typename T>
void LinkedList<T>::clear() {
    for (auto it = this->begin(); it != this->end(); it=it->next){
        delete it;
    }
    head->prev = head;
    head->next = head;
}
template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T> & list) {
    out << (list.end()==list.head ? "HEAD" : "ERROR") << " ";
    for (auto it = list.begin(); it != list.end(); it=it->next){
        out << it->key << " ";
    }
    out << "| " << list.size();
    return out;
}

int main () {
    LinkedList<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    cout << list << endl;
    return 0;
}
