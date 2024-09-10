//
// Created by Vijay Ganesh on 10-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    int minNum;
    multiset<int> minSet;
    stack<int> s;

public:
    MinStack() {
    }

    void push(int val) {
        s.push(val);
        minSet.insert(val);
        minNum = *minSet.begin();
    }

    void pop() {
        auto itr = minSet.find(s.top());
        minSet.erase(itr);
        s.pop();
        minNum = *minSet.begin();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */