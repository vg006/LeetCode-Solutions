## Problem Description

The 141st problem on LeetCode, titled **Linked List Cycle**, is a classic problem that involves detecting if a linked list contains a cycle. The task is to determine if the given linked list has a cycle in it.

---
## Topics Covered

- **Linked Lists**: The problem requires understanding and traversing linked list data structures.
- **Two-Pointer Technique**: The solution involves using two pointers that traverse the list at different speeds to detect a cycle.
- **Hash Tables**: An alternative solution uses a hash table to keep track of visited nodes.

---
## Constraints

- The number of nodes in the list can range from `0` to `10^4`.
- The values of the nodes in the list range from `-10^6` to `10^6`.
- `pos` is `-1` if there is no cycle, indicating that the list is not cyclic.

---
## Examples

1. **Example 1**:
    - **Input**: `head = [3,2,0,-4], pos = 1`
    - **Output**: `true`
    - **Explanation**: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

2. **Example 2**:
    - **Input**: `head = [1,2], pos = 0`
    - **Output**: `true`
    - **Explanation**: There is a cycle in the linked list, where the tail connects to the 0th node.

3. **Example 3**:
    - **Input**: `head = [1], pos = -1`
    - **Output**: `false`
    - **Explanation**: There is no cycle in the linked list.

---
## Solution Overview

The most efficient solution to this problem uses the **Floyd's Cycle-Finding Algorithm**, also known as the **tortoise and hare algorithm**. It involves using two pointers, one moving at a slower pace and the other moving at a faster pace. If there is a cycle, the two pointers will eventually meet. If there is no cycle, the faster pointer will reach the end of the list.

---
## Complexities

- **Time Complexity**: `O(n)`, where  n is the number of nodes in the linked list. The algorithm visits each node at most once.
- **Space Complexity**: `O(1)`, as the algorithm uses only a constant amount of extra space.

---
## Key Insights

- The **Floyd's Cycle-Finding Algorithm** is an efficient way to detect cycles in linked lists using only two pointers.
- The algorithm works by moving the faster pointer twice as fast as the slower pointer. If there is a cycle, the two pointers will eventually meet.

---
## Algorithm

1. **Initialize two pointers**: `slow` and `fast`, both pointing to the head of the linked list.
2. **Move the pointers**: Move the `slow` pointer one step at a time and the `fast` pointer two steps at a time.
3. **Check for cycle**: If there is a cycle, the `slow` and `fast` pointers will eventually meet. If there is no cycle, the `fast` pointer will reach the end of the list (i.e., `fast` or `fast->next` becomes `NULL`).
4. **Return the result**: If a cycle is detected, return `true`. Otherwise, return `false`.

---
## Special Cases

- **Empty list**: If the linked list is empty (i.e., `head` is `NULL`), there is no cycle, so return `false`.
- **Single-node list**: If the linked list consists of a single node, there is no cycle, so return `false`.

---
## Example Explanation

Let's consider the example `head = [3,2,0,-4], pos = 1`:

1. **Initialize**: `slow` and `fast` both point to the head of the list, which is the node with value `3`.
2. **Move the pointers**:
    - On the first iteration, `slow` moves to `2`, and `fast` moves to `0`.
    - On the second iteration, `slow` moves to `0`, and `fast` moves to `-4`.
    - On the third iteration, `slow` moves to `-4`, and `fast` moves to `2`.
3. **Cycle detection**: On the fourth iteration, `slow` moves to `2`, and `fast` moves to `0`. Since `slow` and `fast` meet, a cycle is detected.
4. **Return**: Since a cycle is detected, the function returns `true`.

This example demonstrates how the **Floyd's Cycle-Finding Algorithm** efficiently detects the cycle in the linked list by using the two-pointer technique.

---