//
// Created by Vijay Ganesh on 10-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOp(string t) {
        return t == "+" || t == "-" || t == "*" || t == "/";
    }

    int afterOp(string op, int op1, int op2) {
        if(op == "+")
            return op1 + op2;
        else if(op == "-")
            return op1 - op2;
        else if(op == "*")
            return op1 * op2;
        else
            return op1 / op2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int op1, op2, tmpAns, num;

        for(string t : tokens) {
            if(isOp(t)) {
                op2 = nums.top();   nums.pop();
                op1 = nums.top();   nums.pop();
                tmpAns = afterOp(t, op1, op2);
                nums.push(tmpAns);
            } else {
                num = stoi(t);
                nums.push(num);
            }
        }

        return nums.top();
    }
};