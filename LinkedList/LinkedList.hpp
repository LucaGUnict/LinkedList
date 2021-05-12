//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Luca Greco on 12/05/21.
//  Copyright © 2021 Luca Greco. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>

template <typename T> class LinkedList;
template <typename T> std::ostream& operator<<(std::ostream&, const LinkedList<T>&);

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
    friend std::ostream& operator<< <T>(std::ostream&, const LinkedList<T>&);
};

#endif /* LinkedList_hpp */
