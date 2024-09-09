//
// Created by Vijay Ganesh on 09-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingHere = nums[0];
        int maxSoFar = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            maxEndingHere = max(nums[i], nums[i] + maxEndingHere);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};