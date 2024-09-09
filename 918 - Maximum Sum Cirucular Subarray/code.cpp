//
// Created by Vijay Ganesh on 09-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum, minSum, totSum;
        int maxEnd, maxNow, minEnd, minNow;

        maxEnd = maxNow = minEnd = minNow = totSum = nums[0];
        int neg = (nums[0] < 0) ? 1 : 0;

        for(int num = 0, i = 1; i < nums.size(); i++) {
            num = nums[i];
            maxEnd = max(num, num + maxEnd);
            maxNow = max(maxNow, maxEnd);

            minEnd = min(num, num + minEnd);
            minNow = min(minNow, minEnd);

            totSum += num;
            if(num < 0)
                neg++;
        }

        maxSum = maxNow;
        minSum = minNow;
        return (neg == nums.size() ? maxSum : max(maxSum, totSum - minSum));
    }
};
