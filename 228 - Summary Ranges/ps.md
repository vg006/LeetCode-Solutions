The 228th problem on LeetCode, titled **Summary Ranges**, is a straightforward yet insightful problem that involves processing a sorted array of unique integers to generate a list of ranges. Below is a detailed breakdown of the problem, including its description, topics covered, constraints, examples, solution overview, complexities, key insights, algorithm, special cases, and a specific example explanation.

## Problem Description

You are given a sorted unique integer array `nums`. The goal is to return the smallest sorted list of ranges that cover all the numbers in the array exactly. A range `[a,b]` is defined as a set of all integers from `a` to `b`, inclusive. Each element in `nums` must be covered by exactly one of the ranges, and there should be no integer `x` such that `a <= x <= b` that is not in `nums`.

---
## Topics Covered

- **Array Manipulation**: The problem requires iterating through an array and manipulating data based on conditions.
- **String Formatting**: The output requires formatting integers into a specific string representation for ranges.
- **Greedy Algorithms**: The approach to forming ranges can be viewed as a greedy method, where we try to extend ranges as much as possible.


## Constraints

- The input array `nums` is sorted and contains unique integers.
- The values in `nums` can range from `-2^31` to `2^31 - 1`.
- The length of `nums` can be between `0` and `10^4`.


## Examples

1. **Example 1**:
    - **Input**: `nums = [0, 1, 2, 4, 5, 7]`
    - **Output**: `["0->2", "4->5", "7"]`
    - **Explanation**: The ranges cover all integers in `nums`, with `0` to `2` forming one range, `4` to `5` forming another, and `7` being a single number.

2. **Example 2**:
    - **Input**: `nums = [1, 3, 4, 5, 7]`
    - **Output**: `["1", "3->5", "7"]`
    - **Explanation**: The number `1` is standalone, `3` to `5` forms a range, and `7` is standalone.

3. **Example 3**:
    - **Input**: `nums = []`
    - **Output**: `[]`
    - **Explanation**: An empty input results in an empty output.


## Solution Overview

The solution involves iterating through the `nums` array while maintaining a start index for the current range. The algorithm checks for consecutive numbers and forms ranges accordingly. If a break in the sequence is found, the current range is finalized and added to the result.


## Complexities

- **Time Complexity**: O(n), where n is the number of elements in the input array. The algorithm processes each element exactly once.
- **Space Complexity**: O(k), where k is the number of ranges produced. This accounts for the space needed to store the output.


## Key Insights

- The problem can be efficiently solved using a single pass through the array, leveraging the sorted property of `nums`.
- The output format requires careful string manipulation to ensure ranges are represented correctly.


## Algorithm

1. **Initialization**: Start by checking if the input array is empty. If it is, return an empty list.
2. **Iterate through the Array**: Use a loop to traverse the array:
    - Keep track of the starting index of the current range.
    - Whenever a gap between consecutive numbers is detected, finalize the current range and prepare to start a new one.
3. **Finalizing the Last Range**: After the loop, ensure that the last range is added to the result.
4. **Return the Result**: The list of ranges is returned as the output.


## Special Cases

- **Empty Input**: If `nums` is empty, the output should also be an empty list.
- **Single Element**: If `nums` contains only one element, the output should be that element as a string.
- **Consecutive Numbers**: If all numbers are consecutive, they should be combined into a single range.


## Example Explanation

For the input `nums = [0, 1, 2, 4, 5, 7]`:

1. **Initialization**: Start with `start = 0`.
2. **Iterate**:
    - At index `1`, the number `1` is consecutive to `0`.
    - At index `2`, the number `2` is consecutive to `1`.
    - At index `3`, the number `4` is not consecutive to `2`. Thus, the range `0->2` is finalized and added to the result.
    - Update `start` to `3` (the index of `4`).
    - At index `4`, the number `5` is consecutive to `4`.
    - At index `5`, the number `7` is not consecutive to `5`. Thus, the range `4->5` is finalized and added to the result.
    - Finally, `7` is standalone and added to the result as `"7"`.
3. **Output**: The final output is `["0->2", "4->5", "7"]`.

This structured approach effectively captures all ranges in the input array while adhering to the problem's constraints and requirements.

