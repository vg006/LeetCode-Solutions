## Problem Description

The LeetCode problem **Maximum Subarray** (Problem 53) requires finding the contiguous subarray within a one-dimensional array of numbers, `nums`, which has the largest sum. The goal is to return the sum of this subarray.


### Topics Covered

- Dynamic Programming
- Array Manipulation
- Prefix Sums
- Greedy Algorithms


### Constraints

- The input array `nums` will have at least one element.
- Each element in `nums` can be negative, zero, or positive.
- The length of `nums` can be up to `10^4`.


## Examples

1. **Example 1:**
    - **Input:** `nums = [-2,1,-3,4,-1,2,1,-5,4]`
    - **Output:** `6`
    - **Explanation:** The contiguous subarray `[4,-1,2,1]` has the largest sum of 6.

2. **Example 2:**
    - **Input:** `nums = [1]`
    - **Output:** `1`
    - **Explanation:** The only element is 1, which is the maximum subarray.

3. **Example 3:**
    - **Input:** `nums = [5,4,-1,7,8]`
    - **Output:** `23`
    - **Explanation:** The contiguous subarray `[5,4,-1,7,8]` has the largest sum of 23.

4. **Example 4:**
    - **Input:** `nums = [-1,-2,-3,-4]`
    - **Output:** `-1`
    - **Explanation:** The maximum subarray is just the single element `-1`.


## Solution Overview

The solution to the Maximum Subarray problem can be efficiently achieved using a dynamic programming approach known as Kadane's Algorithm. The algorithm iteratively computes the maximum sum of subarrays ending at each position in the array while maintaining the overall maximum found so far.

### Steps Involved

1. **Initialization:** Start with two variables, `max_current` (the maximum sum of the subarray ending at the current position) and `max_global` (the overall maximum sum found).

2. **Iterate Through the Array:** For each element in the array:
    - Update `max_current` to be the maximum of the current element itself or the sum of `max_current` and the current element. This decision checks whether to start a new subarray at the current element or to continue the existing subarray.
    - Update `max_global` if `max_current` is greater than `max_global`.

3. **Return Result:** At the end of the iteration, `max_global` will contain the maximum sum of any contiguous subarray.


## Time and Space Complexity

- **Time Complexity:** The time complexity is O(n), where n is the number of elements in the input array. This is because we make a single pass through the array.

- **Space Complexity:** The space complexity is O(1) since we are only using a constant amount of space for the variables.


## Key Insights

- **Kadane's Algorithm** is optimal for this problem as it efficiently finds the maximum subarray sum in linear time.
- The approach works well even for arrays with all negative numbers since it will still return the largest single element.
- The solution leverages the idea of maintaining a running total and updating the maximum sum found so far.


## Special Cases

- An array with only one element should return that element as the maximum subarray sum.
- Arrays with all negative numbers will return the largest single element, as it is the least negative sum possible.


## Example Explanation

Consider the input array `nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`.

1. **Initialization:** Set `max_current` to `-2` (the first element) and `max_global` to `-2`.

2. **Iterate Through the Array:**
    - For `1`: `max_current` becomes `max(1, -2 + 1) = 1`, update `max_global` to `1`.
    - For `-3`: `max_current` becomes `max(-3, 1 - 3) = -2`, `max_global` remains `1`.
    - For `4`: `max_current` becomes `max(4, -2 + 4) = 4`, update `max_global` to `4`.
    - For `-1`: `max_current` becomes `max(-1, 4 - 1) = 3`, `max_global` remains `4`.
    - For `2`: `max_current` becomes `max(2, 3 + 2) = 5`, update `max_global` to `5`.
    - For `1`: `max_current` becomes `max(1, 5 + 1) = 6`, update `max_global` to `6`.
    - For `-5`: `max_current` becomes `max(-5, 6 - 5) = 1`, `max_global` remains `6`.
    - For `4`: `max_current` becomes `max(4, 1 + 4) = 5`, `max_global` remains `6`.

3. **Final Result:** The maximum subarray sum is `6`, corresponding to the subarray `[4, -1, 2, 1]`.

This example illustrates how Kadane's Algorithm efficiently computes the maximum subarray sum by dynamically updating the current and global maximums.

