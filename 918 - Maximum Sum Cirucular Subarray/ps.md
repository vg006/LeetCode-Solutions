## Problem Description

LeetCode Problem 918, titled **Maximum Sum Circular Subarray**, requires finding the maximum possible sum of a contiguous subarray within a circular array. The circular nature of the array means that the last element is connected to the first element, allowing for subarrays that wrap around.

---
## Problem Statement

Given a circular integer array `nums` of length `n`, return the maximum possible sum of a non-empty subarray.

---
### Topics Covered

- `Arrays`
- `Dynamic Programming`
- `Kadane's Algorithm`
- `Circular Arrays`

---
### Constraints

- $$ 1 \leq \text{nums.length} \leq 3,000 $$
- $$ -10^6 \leq \text{nums[i]} \leq 10^6 $$

---
## Examples

1. **Example 1:**
    - **Input:** `nums = [1, -2, 3, -2]`
    - **Output:** `3`
    - **Explanation:** The maximum sum subarray is `[3]`.

2. **Example 2:**
    - **Input:** `nums = [5, -3, 5]`
    - **Output:** `10`
    - **Explanation:** The maximum sum subarray is `[5, -3, 5]`.

3. **Example 3:**
    - **Input:** `nums = [3, -1, 2, -1]`
    - **Output:** `4`
    - **Explanation:** The maximum sum subarray is `[3, -1, 2]`.

4. **Example 4:**
    - **Input:** `nums = [3, -2, 2, -3]`
    - **Output:** `3`
    - **Explanation:** The maximum sum subarray is `[3]`.

5. **Example 5:**
    - **Input:** `nums = [-2, -3, -1]`
    - **Output:** `-1`
    - **Explanation:** The maximum sum subarray is `[-1]`.

---
## Solution Overview

To solve the problem, we can utilize Kadane's algorithm to find both the maximum subarray sum and the minimum subarray sum. The final result will be the maximum of these two values: either the maximum subarray sum found using Kadane's algorithm or the total sum of the array minus the minimum subarray sum. This approach effectively handles the circular nature of the array.

---
## Complexity Analysis

- **Time Complexity:** `O(n)` , where n is the length of the input array. This is due to the linear scan of the array to compute the maximum and minimum subarray sums.

- **Space Complexity:** `O(1)` , as we are using a fixed amount of extra space for variables and not using any data structures that grow with the input size.
---
## Key Insights

1. **Kadane’s Algorithm**: This algorithm helps find the maximum sum of a contiguous subarray in linear time. We can extend it to find both the maximum and minimum sums.

2. **Circular Array Handling**: The maximum circular subarray sum can be computed by taking the total sum of the array and subtracting the minimum subarray sum. This effectively considers the elements that are wrapped around.

3. **Edge Case**: If all elements are negative, the maximum sum will simply be the largest single element.
---
## Special Cases

- If the array has only one element, the maximum sum is that element itself.
- If all elements are negative, the result will be the maximum single element (which is the least negative).
---
## Algorithm

1. **Calculate Total Sum**: Compute the total sum of the array.

2. **Find Maximum Subarray Sum**: Use Kadane's algorithm to find the maximum subarray sum.

3. **Find Minimum Subarray Sum**: Again, use a variation of Kadane's algorithm to find the minimum subarray sum.

4. **Compute the Result**: The result will be the maximum of the maximum subarray sum and the total sum minus the minimum subarray sum.

5. **Handle Edge Cases**: If the maximum subarray sum is equal to the total sum of the array, it indicates that all elements are negative, and we should return the maximum subarray sum directly.
---
## Example Explanation

Let's walk through the example with `nums = [1, -2, 3, -2]`.

1. **Calculate Total Sum**:
    - Total sum = 1 + (-2) + 3 + (-2) = 0


2. **Find Maximum Subarray Sum**:
    - Using Kadane's algorithm:
        - Start with `max_ending_here = 1`, `max_so_far = 1`.
        - Update for `-2`: `max_ending_here = max(-2, 1 - 2) = -1`, `max_so_far = 1`.
        - Update for `3`: `max_ending_here = max(3, -1 + 3) = 3`, `max_so_far = 3`.
        - Update for `-2`: `max_ending_here = max(-2, 3 - 2) = 1`, `max_so_far = 3`.
    - Maximum subarray sum is `3`.


3. **Find Minimum Subarray Sum**:
    - Using a similar approach:
        - Start with `min_ending_here = 1`, `min_so_far = 1`.
        - Update for `-2`: `min_ending_here = min(-2, 1 - 2) = -2`, `min_so_far = -2`.
        - Update for `3`: `min_ending_here = min(3, -2 + 3) = 1`, `min_so_far = -2`.
        - Update for `-2`: `min_ending_here = min(-2, 1 - 2) = -2`, `min_so_far = -2`.
    - Minimum subarray sum is `-2`.


4. **Compute the Result**:
    - The result is `max(max_so_far, total_sum - min_so_far) = max(3, 0 - (-2)) = max(3, 2) = 3`.


5. **Final Output**: The maximum sum of a circular subarray is `3`.

---
