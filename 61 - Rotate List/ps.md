## Problem Description

The 61st problem on LeetCode, titled **Rotate List**, involves rotating a linked list to the right by a given number of places. The task is to rotate the list to the right by `k` places, where `k` is less than or equal to the length of the list[1].

## Topics Covered

- **Linked Lists**: The problem requires understanding and manipulating linked list data structures.
- **Two-Pointer Technique**: The solution involves using two pointers to find the new head and the new end of the rotated list.
- **Modular Arithmetic**: The problem requires using modular arithmetic to handle cases where `k` is greater than the length of the list.

## Constraints

- The number of nodes in the list will be in the range `[0, 500]`.
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 10^9`

## Examples

1. **Example 1**:
    - **Input**: `head = [1,2,3,4,5], k = 2`
    - **Output**: `[4,5,1,2,3]`
    - **Explanation**: Rotate the list 2 places to the right, the list becomes `[4,5,1,2,3]`.

2. **Example 2**:
    - **Input**: `head = [0,1,2], k = 4`
    - **Output**: `[2,0,1]`
    - **Explanation**: Rotate the list 4 places to the right, the list becomes `[2,0,1]`.

## Solution Overview

The solution involves finding the length of the linked list and then normalizing `k` to avoid unnecessary rotations. It then uses two pointers, `newEnd` and `newHead`, to find the new end and new head of the rotated list. Finally, it connects the old end to the old head and sets the `next` pointer of the new end to `nullptr` to break the list into two parts[2].

## Complexities

- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the linked list. The function traverses the list a couple of times.
- **Space Complexity**: `O(1)`, as the rotation is performed in place without using additional data structures.

## Key Insights

- The problem can be efficiently solved using a single pass through the list to find the new head and new end.
- Normalizing `k` using modular arithmetic ensures that the function works correctly even when `k` is greater than the length of the list.

## Algorithm

1. **Calculate the Length of the List**: Traverse the list to find the length of the list.
2. **Normalize `k`**: Use modular arithmetic to normalize `k` to avoid unnecessary rotations.
3. **Find the New End**: Traverse the list `n - k - 1` steps from the head to find the new end.
4. **Find the New Head**: The new head is the node after the new end.
5. **Break the List**: Set the `next` pointer of the new end to `nullptr`.
6. **Connect the Old End to the Old Head**: Set the `next` pointer of the old end to the old head.

## Special Cases

- **Empty List**: If the list is empty, return the head.
- **Single Node List**: If the list has only one node, return the head.

## Example Explanation

Consider the input `head = [1,2,3,4,5]` and `k = 2`:

1. **Calculate the Length**: The length of the list is `5`.
2. **Normalize `k`**: `k = 2 % 5 = 2`.
3. **Find the New End**: The new end is found by iterating `5 - 2 - 1 = 2` steps from the head, which lands on the node with value `3`.
4. **Find the New Head**: The new head is the node after the new end, which is `4`.
5. **Break the List**: Set the `next` pointer of the new end (`3`) to `nullptr`.
6. **Connect the Old End to the Old Head**: Set the `next` pointer of the old end (`5`) to the old head (`1`).

**Output**: The rotated list is `[4,5,1,2,3]`.

This structured approach effectively rotates the linked list to the right by `k` places while handling various edge cases and ensuring the correct output.
