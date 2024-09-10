//
// Created by Vijay Ganesh on 10-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n, currStreak, maxStreak = 0;
        set<int> numSet(nums.begin(), nums.end());

        for(int num : numSet) {
            if(numSet.find(num - 1) == numSet.end()) {
                n = num;
                currStreak = 1;
                while(numSet.find(n + 1) != numSet.end()){
                    currStreak++;
                    n++;
                }
                maxStreak = max(maxStreak, currStreak);
            }
        }

        return maxStreak;
    }
};