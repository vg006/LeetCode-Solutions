//
// Created by Vijay Ganesh on 11-09-2024.
//

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        int n = 1;
        ListNode *newHead = nullptr, *newEnd = head, *end = head;

        while(end -> next) {
            end = end -> next;
            n++;
        }


        int t = k % n;
        for(int i = 0; i < n - t - 1; i++) {
            newEnd = newEnd -> next;
        }

        newHead = newEnd -> next;
        end -> next = head;
        newEnd -> next = nullptr;

        return newHead ? newHead : head;
    }
};