//
//  MyStack.h
//  ProjectTwoCSCI251
//
//  Created by Hongbiao Zeng on 3/12/19.
//  Copyright © 2019 Hongbiao Zeng. All rights reserved.
//

#ifndef MyStack_h
#define MyStack_h

#include <vector>

template<class T>
class MyStack {
private:
    std::vector<T> v;
public:
    MyStack();
    void push(T item);
    T pop();
    T peek() const;
    int size() const;
    bool isEmpty() const;
};

#endif /* MyStack_h */
