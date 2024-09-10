The 155th problem on LeetCode, titled **Min Stack**, is a classic problem that involves designing a stack data structure with an additional operation to retrieve the minimum element efficiently. Here's a detailed breakdown of the problem:

## Problem Description

Design a stack that supports the following operations:

- `push(x)`: Push element `x` onto the stack.
- `pop()`: Remove the element on the top of the stack.
- `top()`: Get the top element of the stack.
- `getMin()`: Retrieve the minimum element in the stack.

All the above operations should be performed in constant time complexity.

## Topics Covered

- **Stack Data Structure**: The problem requires implementing a stack with additional functionality.
- **Space-Time Trade-off**: The solution involves using extra space to optimize time complexity.
- **Auxiliary Data Structures**: An additional data structure is used alongside the stack to keep track of the minimum elements.

## Constraints

- The number of operations will not exceed 3 * 10^4.
- All the values will be in the range of 32-bit signed integer.

## Examples

1. **Example 1**:
    - **Input**:
        - `push(-2)`
        - `push(0)`
        - `push(-3)`
        - `getMin()`
        - `pop()`
        - `top()`
        - `getMin()`
    - **Output**: `[-3, -2, 0, -3]`
    - **Explanation**:
        - `push(-2)`, `push(0)`, `push(-3)`: Stack becomes `[-2, 0, -3]`.
        - `getMin()`: Returns `-3`.
        - `pop()`: Removes `-3` from the stack. Stack becomes `[-2, 0]`.
        - `top()`: Returns `0`.
        - `getMin()`: Returns `-2`.

## Solution Overview

The solution involves using an additional stack to keep track of the minimum elements. Whenever a new element is pushed onto the main stack, we compare it with the top element of the minimum stack. If the new element is less than or equal to the top element of the minimum stack, we push it onto the minimum stack as well. This ensures that the top element of the minimum stack always represents the minimum element in the main stack.

## Complexities

- **Time Complexity**: `O(1)` for all operations (`push`, `pop`, `top`, `getMin`).
- **Space Complexity**: `O(n)`, where `n` is the number of elements in the stack, as we are using an additional stack to store the minimum elements.

## Key Insights

- The key insight is to use an additional stack to keep track of the minimum elements, which allows us to retrieve the minimum element in constant time.
- The minimum stack is updated in a way that ensures its top element always represents the minimum element in the main stack.

## Algorithm

1. **Initialization**: Create two stacks: `mainStack` to store the elements and `minStack` to keep track of the minimum elements.
2. **Push Operation**: When pushing an element `x` onto the `mainStack`:
    - Push `x` onto the `mainStack`.
    - If `minStack` is empty or `x` is less than or equal to the top element of `minStack`, push `x` onto the `minStack`.
3. **Pop Operation**: When popping an element from the `mainStack`:
    - Pop the top element from the `mainStack`.
    - If the popped element is equal to the top element of `minStack`, pop the top element from the `minStack`.
4. **Top Operation**: Return the top element of the `mainStack`.
5. **GetMin Operation**: Return the top element of the `minStack`.

## Special Cases

- **Empty Stack**: If the stack is empty, the `top()` and `getMin()` operations should return `-1` or throw an exception, depending on the implementation.

## Example Explanation

Let's consider the example given in the problem statement:

1. **Push Operations**:
    - `push(-2)`: Push `-2` onto `mainStack` and `minStack`.
    - `push(0)`: Push `0` onto `mainStack` and `minStack`.
    - `push(-3)`: Push `-3` onto `mainStack` and `minStack`.
2. **GetMin Operation**: Return the top element of `minStack`, which is `-3`.
3. **Pop Operation**: Pop the top element from `mainStack`, which is `-3`. Since `-3` is equal to the top element of `minStack`, pop the top element from `minStack` as well.
4. **Top Operation**: Return the top element of `mainStack`, which is `0`.
5. **GetMin Operation**: Return the top element of `minStack`, which is `-2`.

This solution ensures that the `getMin()` operation can be performed in constant time while maintaining the time complexity of `push()`, `pop()`, and `top()` operations at `O(1)`.
