//
//  main.cpp
//  LinkedList
//
//  Created by Luca Greco on 05/05/21.
//  Copyright © 2021 Luca Greco. All rights reserved.
//

#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main () {
    LinkedList<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    cout << list[5] << endl;
    list[0] = 6;
    return 0;
}
