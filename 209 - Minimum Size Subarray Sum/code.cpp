//
// Created by Vijay Ganesh on 09-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, minLen = INT_MAX;
        int start = 0, end = 0;

        while(end < nums.size()) {
            sum += nums[end];
            while(sum >= target) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};