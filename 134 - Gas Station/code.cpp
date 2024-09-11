//
// Created by Vijay Ganesh on 11-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g, c, start, tot;
        g = c = start = tot = 0;

        for(int i = 0; i < gas.size(); i++) {
            g += gas[i];
            c += cost[i];
            tot += gas[i] - cost[i];

            if(tot < 0) {
                start = i + 1;
                tot = 0;
            }
        }

        return (g >= c ? start : -1);
    }
};