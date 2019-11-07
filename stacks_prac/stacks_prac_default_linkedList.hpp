//
//  stacks_prac_default_linkedList.hpp
//  stacks_prac
//
//  Created by Brandon Johns on 4/5/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#ifndef stacks_prac_default_linkedList_hpp
#define stacks_prac_default_linkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *link;
};

template <class elemType>
class linkedlistStack
{
public:
    const linkedlistStack<elemType>& operator=(const linkedlistStack<elemType> & other);
    bool isEmptyStack() const;
    bool isFullStack() const;
    void initializedStack();
    void push(const elemType& element);
    elemType top() const;
    void pop();
    linkedlistStack();
    linkedlistStack(const linkedlistStack<elemType>& other);
    ~linkedlistStack();
private:
    nodeType<elemType> *stackTop;
    
    void copyStack(const linkedlistStack<elemType>& other);
};


#endif /* stacks_prac_default_linkedList_hpp */
