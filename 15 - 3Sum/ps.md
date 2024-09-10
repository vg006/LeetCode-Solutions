## Problem Description

The LeetCode problem **3Sum** (Problem 15) requires finding all unique triplets in a given integer array `nums` that sum to zero. The goal is to return all triplets `[nums[i], nums[j], nums[k]]` such that:

- The indices `i`, `j`, and `k` are all different.
- The sum of the triplet equals zero: $$ nums[i] + nums[j] + nums[k] = 0 $$.
- The solution set must not contain duplicate triplets.


### Topics Covered

- Array manipulation
- Sorting
- Two-pointer technique
- Handling duplicates


### Constraints

- The input array `nums` can contain between 0 and 3000 elements.
- Each element in `nums` can range from -10^9 to 10^9.


## Examples

1. **Example 1:**
   - **Input:** `nums = [-1, 0, 1, 2, -1, -4]`
   - **Output:** `[[-1, -1, 2], [-1, 0, 1]]`
   - **Explanation:** The valid triplets that sum to zero are `[-1, -1, 2]` and `[-1, 0, 1]`.

2. **Example 2:**
   - **Input:** `nums = []`
   - **Output:** `[]`
   - **Explanation:** No triplets can be formed from an empty array.

3. **Example 3:**
   - **Input:** `nums = [0, 1, 1]`
   - **Output:** `[]`
   - **Explanation:** No triplet sums to zero since all numbers are non-negative.


## Solution Overview

The solution to the 3Sum problem typically involves the following steps:

1. **Sort the Input Array:** Sorting the array helps in efficiently finding triplets and managing duplicates.

2. **Iterate with a Fixed Element:** Loop through the array, fixing one element at a time and using a two-pointer approach to find pairs that sum to the negative of the fixed element.

3. **Using Two Pointers:** For each fixed element, initialize two pointers—one at the beginning of the remaining elements and one at the end. Adjust these pointers based on the sum of the triplet until all possible pairs are checked.

4. **Avoiding Duplicates:** After finding a valid triplet, move the pointers past any duplicate elements to ensure that the same triplet is not counted multiple times.


## Time and Space Complexity

- **Time Complexity:** The overall time complexity is `O(n^2)` due to the nested iteration (one for fixing the element and another for the two-pointer search).

- **Space Complexity:** The space complexity is `O(1)`  if we ignore the space used for the output list, as the algorithm primarily operates in-place.


## Key Insights

- **Sorting is Crucial:** Sorting the array simplifies the process of finding pairs and managing duplicates.

- **Two-Pointer Technique:** This method is efficient for reducing the time complexity compared to a brute-force approach.

- **Handling Duplicates:** Careful management of duplicate entries ensures that the solution set contains only unique triplets.


## Algorithm Steps

1. **Sort the Array:** Start by sorting the array to facilitate the two-pointer method and to easily skip duplicates.

2. **Fix One Element:** Iterate through the sorted array. For each element, treat it as the fixed element.

3. **Initialize Two Pointers:** Set one pointer to the next element after the fixed element and the other pointer to the end of the array.

4. **Calculate the Sum:**
   - If the sum of the fixed element and the two pointers equals zero, record the triplet.
   - If the sum is less than zero, move the left pointer to the right to increase the sum.
   - If the sum is greater than zero, move the right pointer to the left to decrease the sum.

5. **Skip Duplicates:** After finding a valid triplet, increment or decrement the pointers to skip over any duplicate values.

6. **Repeat:** Continue this process until all elements have been considered as a fixed element.


## Special Cases

- An empty array or an array with fewer than three elements should return an empty list.

- Arrays with all positive or all negative numbers cannot yield any triplets that sum to zero.


## Example Explanation

Consider the array `nums = [-1, 0, 1, 2, -1, -4]`.

1. **Sort the Array:** After sorting, `nums` becomes `[-4, -1, -1, 0, 1, 2]`.

2. **Iterate through the Array:** Fix the first element at index `0` which is `-4`. Use two pointers:
   - Left pointer starts at index `1` (value `-1`).
   - Right pointer starts at index `5` (value `2`).

3. **Calculate the Sum:**
   - Sum =  -4 + (-1) + 2 = -3  (move left pointer right).
   - Sum =  -4 + 0 + 2 = -2  (move left pointer right).
   - Sum =  -4 + 1 + 2 = -1  (move left pointer right).
   - Since the left pointer exceeds the right pointer, move to the next fixed element.

4. **Continue for Other Fixed Elements:** Repeat the process for `-1` at index `1`:
   - Left pointer starts at index `2` (value `-1`).
   - Right pointer starts at index `5` (value `2`).
   - Sum =  -1 + (-1) + 2 = 0  (valid triplet found: `[-1, -1, 2]`).
   - Move pointers to avoid duplicates and continue checking.

5. **Collect Unique Triplets:** The valid triplets found are `[-1, -1, 2]` and `[-1, 0, 1]`.

By following this approach, all unique triplets that sum to zero can be efficiently found.

