LeetCode Problem 918, titled **Maximum Sum Circular Subarray**, requires finding the maximum possible sum of a contiguous subarray within a circular array. This problem is a variation of the classic maximum subarray problem, which can be solved using Kadane's algorithm.

## Problem Statement

Given a circular integer array `nums` of length `n`, the task is to return the maximum possible sum of a non-empty subarray. The circular nature of the array means that the end of the array wraps around to the beginning.

## Key Concepts

1. **Kadane's Algorithm**: This algorithm helps find the maximum sum of a contiguous subarray in linear time. It maintains two variables:
    - `max_ending_here`: The maximum sum of the subarray ending at the current position.
    - `max_so_far`: The maximum sum found so far.

2. **Circular Array Handling**: To handle the circular aspect of the array, the maximum sum can either be:
    - The maximum subarray sum found using Kadane's algorithm in the normal way.
    - The total sum of the array minus the minimum subarray sum (which effectively wraps around).

## Steps to Solve the Problem

1. **Find the Maximum Subarray Sum**: Use Kadane's algorithm to find the maximum sum of a non-circular subarray.

2. **Find the Minimum Subarray Sum**: Again, use a variation of Kadane's algorithm to find the minimum sum of a non-circular subarray.

3. **Calculate Total Sum**: Compute the total sum of the array.

4. **Determine the Maximum Circular Subarray Sum**: The maximum circular subarray sum can be calculated as:
    - `max(max_sum, total_sum - min_sum)`
    - However, if all numbers are negative (i.e., `max_sum` equals `total_sum - min_sum`), return `max_sum` directly.

5. **Return the Result**: The result will be the maximum of the two calculated values.

## Example Walkthrough

Consider the array `nums = [1, -2, 3, -2]`.

1. **Maximum Subarray Sum**:
    - Applying Kadane's algorithm:
        - Start with `max_ending_here = 1`, `max_so_far = 1`.
        - Update for `-2`: `max_ending_here = max(-2, 1 - 2) = -1`, `max_so_far = 1`.
        - Update for `3`: `max_ending_here = max(3, -1 + 3) = 3`, `max_so_far = 3`.
        - Update for `-2`: `max_ending_here = max(-2, 3 - 2) = 1`, `max_so_far = 3`.
    - Maximum subarray sum is `3`.

2. **Minimum Subarray Sum**:
    - Applying a similar approach:
        - Start with `min_ending_here = 1`, `min_so_far = 1`.
        - Update for `-2`: `min_ending_here = min(-2, 1 - 2) = -2`, `min_so_far = -2`.
        - Update for `3`: `min_ending_here = min(3, -2 + 3) = 1`, `min_so_far = -2`.
        - Update for `-2`: `min_ending_here = min(-2, 1 - 2) = -2`, `min_so_far = -2`.
    - Minimum subarray sum is `-2`.

3. **Total Sum**:
    - `total_sum = 1 + (-2) + 3 + (-2) = 0`.

4. **Maximum Circular Subarray Sum**:
    - Calculate: `max(max_sum, total_sum - min_sum) = max(3, 0 - (-2)) = max(3, 2) = 3`.

5. **Final Result**:
    - The maximum sum of a circular subarray is `3`.

## Conclusion

The solution to LeetCode Problem 918 efficiently combines the results of Kadane's algorithm for both maximum and minimum subarrays, allowing for the handling of circular arrays. The overall time complexity is $$ O(n) $$, making it suitable for large input sizes.