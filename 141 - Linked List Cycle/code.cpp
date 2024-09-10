//
// Created by Vijay Ganesh on 10-09-2024.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || head -> next == nullptr)
            return false;

        ListNode *fast = head, *slow = head;

        // Using Floyd's Cycle-Finding Algorithm
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = (fast -> next) -> next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};