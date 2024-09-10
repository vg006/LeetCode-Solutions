
## Problem Description

The 128th problem on LeetCode, titled **Longest Consecutive Sequence**, challenges users to find the length of the longest sequence of consecutive integers in an unsorted array. The problem is a popular interview question and is categorized under the topics of **Arrays** and **Hash Tables**.
Given an unsorted array of integers `nums`, the goal is to return the length of the longest consecutive elements sequence. The order of elements in the array does not matter; what matters is the presence of consecutive integers.


## Topics Covered

- Arrays
- Hash Tables
- Sorting
- Set operations


## Constraints

- The input array can contain both positive and negative integers.
- The array can have duplicates, which should be ignored in the count of the sequence.
- The algorithm must run in O(n) time complexity, where n is the number of elements in the array.


### Example

For the input array `[100, 4, 200, 1, 3, 2]`, the longest consecutive sequence is `[1, 2, 3, 4]`, and thus the output should be `4`.


## Solution Overview

The optimal solution involves using a **HashSet** to store the unique elements of the array. This allows for efficient checking of consecutive numbers in constant time.


## Complexity Analysis

- **Time Complexity**: O(n) - Each element is processed at most twice (once when added to the set and once when checking for consecutive sequences).
- **Space Complexity**: O(n) - The space used by the HashSet to store unique elements.


## Key Insights

1. **Use of HashSet**: By storing the elements in a HashSet, we can quickly check if a number exists, which is crucial for identifying consecutive sequences.

2. **Identifying Sequence Start**: To find the start of a sequence, check if the previous number (i.e., `num - 1`) is not in the set. If it isn't, then `num` is the start of a new sequence.

3. **Counting Consecutives**: Once a starting point is found, incrementally check for the next consecutive number (`num + 1`, `num + 2`, etc.) until no further consecutive numbers are found.


## Algorithm

1. Create a HashSet and add all elements from the input array to it.
2. Initialize a variable to keep track of the longest streak found.
3. Iterate through each number in the original array:
    - If the number minus one does not exist in the set, it indicates the start of a new sequence.
    - Count how many consecutive numbers follow this starting number.
    - Update the longest streak if the current streak exceeds the previously recorded longest streak.
4. Return the length of the longest streak.


## Special Cases

- If the input array is empty, the output should be `0`.
- If all elements are the same (e.g., `[1, 1, 1]`), the longest consecutive sequence is `1`.


## Example Explanation

For the input `[100, 4, 200, 1, 3, 2]`:

1. Convert to a set: `{100, 4, 200, 1, 3, 2}`.
2. Start with `1`: Check for `0` (not found), so start counting.
3. Find `2`, `3`, and `4` consecutively.
4. Count is `4` for the sequence `[1, 2, 3, 4]`.
5. Other numbers (`100`, `200`) do not contribute to a longer sequence.
6. Return `4` as the result.

This problem effectively tests the understanding of data structures and the ability to optimize algorithms for performance, making it a valuable challenge for coding interviews.

