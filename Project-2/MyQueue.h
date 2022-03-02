//
//  MyQueue.h
//  ProjectTwoCSCI251
//
//  Created by Hongbiao Zeng on 3/12/19.
//  Copyright © 2019 Hongbiao Zeng. All rights reserved.
//

#ifndef MyQueue_h
#define MyQueue_h

#include <list>

template<class T>
class MyQueue {
private:
    std::list<T> q;
public:
    MyQueue();
    void push(T item);
    T pop();
    T peek() const;
    int size() const;
    bool isEmpty() const;
};

#endif /* MyQueue_h */
