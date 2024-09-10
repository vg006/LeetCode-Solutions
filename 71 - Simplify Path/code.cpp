//
// Created by Vijay Ganesh on 10-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        stringstream ss(path);
        string s, resultPath = "", singlePath = "";

        while(getline(ss, s, '/')) {
            if(s == "." || s == "")
                continue;
            else if(s == "..") {
                if(!paths.empty())
                    paths.pop();
            }
            else
                paths.push(s);
        }

        while(!paths.empty()) {
            resultPath = '/' + paths.top() + resultPath;
            paths.pop();
        }

        return resultPath == "" ? "/" : resultPath;
    }
};