//
//  stacks_prac_default_linkedList.cpp
//  stacks_prac
//
//  Created by Brandon Johns on 4/5/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include "stacks_prac_default_linkedList.hpp"
#include <iostream>
using namespace std;


template <class elemType>
const linkedlistStack<elemType>& linkedlistStack<elemType>:: operator=(const linkedlistStack<elemType> & other)
{
    if(this!= &other)
        copyStack(other);
    return *this;
}

template <class elemType>
bool linkedlistStack<elemType>:: isEmptyStack() const
{
    return (stackTop==NULL);
}

template <class elemType>
bool linkedlistStack<elemType>:: isFullStack() const
{
    return false;
}

template <class elemType>
void linkedlistStack<elemType>:: initializedStack()
{
    nodeType<elemType> *temp;
    
    while(stackTop!=NULL)
    {
        temp=stackTop;
        stackTop=stackTop->link;
        delete temp;
    }
}

template <class elemType>
void linkedlistStack<elemType>:: push(const elemType& element)
{
    nodeType<elemType> *newNode;
    newNode= new nodeType<elemType>;
    newNode->info=element;
    newNode->link=stackTop;
    stackTop=newNode;
}

template <class elemType>
elemType linkedlistStack<elemType>:: top() const
{
    assert(stackTop!=NULL);
    return stackTop->info;
}

template <class elemType>
void linkedlistStack<elemType>:: pop()
{
    nodeType<elemType>*temp;
    if(stackTop!=NULL)
    {
        temp=stackTop;
        stackTop=stackTop->link;
        delete temp;
    }
    else
        cout<<"ccanot remove from empty stack"<<endl;
}
template <class elemType>
linkedlistStack<elemType>:: linkedlistStack()
{
    stackTop=NULL;
}

template <class elemType>
linkedlistStack<elemType>:: linkedlistStack(const linkedlistStack<elemType>& other)
{
    stackTop=NULL;
    copyStack(other);
}
template <class elemType>
linkedlistStack<elemType>:: ~linkedlistStack()
{
    initializedStack();
}

template <class elemType>
void linkedlistStack<elemType>:: copyStack(const linkedlistStack<elemType>& other)
{
    nodeType<elemType> *newNode, *current, *last;
    if (stackTop!= NULL)
        initializedStack();
    if(other.stackTop==NULL)
        stackTop=NULL;
    else
    {
        current= other.stackTop;
        
        stackTop= new nodeType<elemType>;
        stackTop->info=current->info;
        stackTop->link=NULL;
        last=stackTop;
        current=current->link;
        
        while(current!=NULL)
        {
            newNode= new nodeType<elemType>;
            
            newNode->info= current->info;
            newNode->link=NULL;
            last->link = newNode;
            last=newNode;
            current=current->link;
        }
    }
}
