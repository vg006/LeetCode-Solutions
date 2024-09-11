The 134th problem on LeetCode, titled **Gas Station**, is a well-known problem that involves determining if you can complete a circular route around gas stations given specific constraints on gas availability and consumption. Below is a detailed breakdown of the problem, including its description, topics covered, constraints, examples, solution overview, complexities, key insights, algorithm, special cases, and an example explanation.

## Problem Description

You are given two integer arrays:
- `gas`: an array where `gas[i]` represents the amount of gas available at the `i-th` gas station.
- `cost`: an array where `cost[i]` represents the amount of gas required to travel from the `i-th` gas station to the next gas station.

The goal is to determine the starting gas station index from which you can travel around the circuit once without running out of gas. If there is no such starting index, return `-1`.

## Topics Covered

- **Greedy Algorithms**: The problem can be solved using a greedy approach by evaluating the gas stations in a single pass.
- **Array Manipulation**: Understanding how to manipulate and traverse arrays effectively.
- **Mathematical Insight**: The problem requires understanding the relationship between gas available and gas required.

## Constraints

- The number of gas stations, `n`, will be between `1` and `10^5`.
- The values for `gas[i]` and `cost[i]` will be non-negative integers.

## Examples

1. **Example 1**:
    - **Input**: `gas = [1, 2, 3, 4, 5]`, `cost = [3, 4, 5, 1, 2]`
    - **Output**: `3`
    - **Explanation**: Starting at index `3`, you can complete the circuit.

2. **Example 2**:
    - **Input**: `gas = [2, 3, 4]`, `cost = [3, 4, 3]`
    - **Output**: `-1`
    - **Explanation**: There is no starting index that allows you to complete the circuit.

3. **Example 3**:
    - **Input**: `gas = [5, 1, 2, 3, 4]`, `cost = [4, 4, 1, 5, 1]`
    - **Output**: `0`
    - **Explanation**: Starting at index `0`, you can complete the circuit.

## Solution Overview

The solution involves iterating through the gas stations while maintaining a running total of gas and cost. If at any point the total gas available becomes less than the total cost incurred, it indicates that the circuit cannot be completed from the current starting point. The algorithm then resets the starting point to the next station and continues checking.

## Complexities

- **Time Complexity**: `O(n)`, where `n` is the number of gas stations. Each gas station is processed once.
- **Space Complexity**: `O(1)`, as only a constant amount of extra space is used.

## Key Insights

- If the total amount of gas is less than the total cost to travel around the circuit, it is impossible to complete the circuit from any starting point.
- The problem can be solved in a single pass by leveraging the greedy approach to track the current gas balance.

## Algorithm

1. **Initialization**: Initialize variables to keep track of the total gas and total cost, as well as the current gas balance and a starting index.
2. **Iterate Through Gas Stations**:
    - For each gas station, update the total gas and total cost.
    - Update the current gas balance by adding the gas available and subtracting the cost to the next station.
    - If the current gas balance becomes negative, reset the starting index to the next station and reset the current gas balance.
3. **Final Check**: After the loop, check if the total gas is greater than or equal to the total cost. If so, return the starting index; otherwise, return `-1`.

## Special Cases

- **Single Station**: If there is only one gas station, check if the gas available is greater than or equal to the cost to travel (which is 0 in this case).
- **All Gas Stations Insufficient**: If all gas stations have insufficient gas to cover the cost, the output should be `-1`.

## Example Explanation

Consider the input `gas = [1, 2, 3, 4, 5]` and `cost = [3, 4, 5, 1, 2]`:

1. **Initialization**: Start with `total_gas = 0`, `total_cost = 0`, `current_gas = 0`, and `start_index = 0`.
2. **Iterate**:
    - At index `0`: `total_gas += 1`, `total_cost += 3`, `current_gas = 1 - 3 = -2`. Since `current_gas` is negative, reset `start_index` to `1` and `current_gas` to `0`.
    - At index `1`: `total_gas += 2`, `total_cost += 4`, `current_gas = 0 + 2 - 4 = -2`. Reset `start_index` to `2`.
    - At index `2`: `total_gas += 3`, `total_cost += 5`, `current_gas = 0 + 3 - 5 = -2`. Reset `start_index` to `3`.
    - At index `3`: `total_gas += 4`, `total_cost += 1`, `current_gas = 0 + 4 - 1 = 3`. `current_gas` is positive.
    - At index `4`: `total_gas += 5`, `total_cost += 2`, `current_gas = 3 + 5 - 2 = 6`. `current_gas` remains positive.
3. **Final Check**: After the loop, `total_gas = 15` and `total_cost = 15`, indicating that starting at index `3` allows completing the circuit.

**Output**: `3`

This structured approach effectively determines the starting gas station index from which the circuit can be completed, ensuring all edge cases and constraints are handled appropriately.
