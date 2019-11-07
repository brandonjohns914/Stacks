//
//  stacks_prac_default_array.hpp
//  stacks_prac
//
//  Created by Brandon Johns on 4/5/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#ifndef stacks_prac_default_array_hpp
#define stacks_prac_default_array_hpp

#include <stdio.h>
template <class elemType>
class stackArray
{
public:
    stackArray();
    stackArray(const stackArray<elemType>& other);
    stackArray(int stackSize);
    ~stackArray();
    int size();
    int maxStackSize();
   void initializeStack();
    bool isEmptyStack()  const;
    bool isFullStack() const;
    void push(const elemType& element);
    elemType top() const;
    void pop();
    const stackArray<elemType>& operator =(const stackArray<elemType>& other);
    
private:
    int maxStack;
    int stackTop;
    elemType *list;
    void copyStack(const stackArray<elemType>& other);
    
};

#endif /* stacks_prac_default_array_hpp */
