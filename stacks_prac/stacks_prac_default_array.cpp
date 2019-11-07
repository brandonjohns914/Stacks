//
//  stacks_prac_default_array.cpp
//  stacks_prac
//
//  Created by Brandon Johns on 4/5/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include "stacks_prac_default_array.hpp"
#include <iostream>
using namespace std;

template <class elemType>
stackArray<elemType>:: stackArray()
{
    stackTop=0;
    maxStack=100;
    list=new elemType[maxStack];
}

template <class elemType>
stackArray<elemType>:: stackArray(int stackSize)
{
    if(stackSize<=0)
    {
        cout<<"creating default array max of 100"<<endl;
        maxStack=100;
    }
    else
    {
        stackTop=0;
        list=new elemType[maxStack];
    }
}
template <class elemType>
stackArray<elemType>:: ~stackArray()
{
    delete [] list;
}

template <class elemType>
int stackArray<elemType>:: size()
{
    return stackTop;
}

template <class elemType>
int  stackArray<elemType>:: maxStackSize()
{
    return maxStack;
}

template <class elemType>
void stackArray<elemType>:: initializeStack()
{
    stackTop=0;
}

template <class elemType>
bool stackArray<elemType>:: isEmptyStack()  const
{
    
    return(stackTop==0);
}

template <class elemType>
bool stackArray<elemType>:: isFullStack() const
{
    return (stackTop==maxStack);
}

template <class elemType>
void stackArray<elemType>:: push(const elemType& element)
{
    if(!isFullStack())
    {
        list[stackTop]=element;
        stackTop++;
    }
    else
        cout<< "cannot add to a full stack" <<endl;
}

template <class elemType>
elemType stackArray<elemType>:: top() const
{
    assert(stackTop!=0);
    return list[stackTop-1];
}

template <class elemType>
void stackArray<elemType>:: pop()
{
    if(!isEmptyStack())
        stackTop--;
    else
        cout<<"cannot remove from an empty stack "<<endl;
}
template <class elemType>
stackArray<elemType>::
stackArray(const stackArray<elemType>& other)
{
    list=NULL;
    copyStack(other);
}

template <class elemType>
const  stackArray<elemType>& stackArray<elemType>:: operator =(const stackArray<elemType>& other)
{
    if(this!=&other)
        copyStack(other);
    
    return *this;
}

template <class elemType>
void stackArray<elemType>:: copyStack(const stackArray<elemType>& other)
{
    delete [] list;
    maxStack=other.maxStack;
    stackTop=other.stackTop;
    
    list=new elemType[maxStack];
    
    for(int i=0; i<stackTop; i++)
    {
        list[i]=other.list[i];
    }
}
