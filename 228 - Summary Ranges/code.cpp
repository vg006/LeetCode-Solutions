//
// Created by Vijay Ganesh on 10-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int n = nums.size();

        if(n == 0)  return ranges;
        if(n == 1)  return { to_string(nums[0]) };

        int start = 0;

        for(int end = 1; end <= n; end++) {
            if(end == n || nums[end - 1] != nums[end] - 1) {
                if(start == end - 1) {
                    ranges.push_back(to_string(nums[start]));
                } else {
                    ranges.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
                }
                start = end;
            }
        }

        return ranges;
    }
};