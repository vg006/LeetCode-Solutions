The 150th problem on LeetCode, titled **Evaluate Reverse Polish Notation**, involves evaluating expressions written in Reverse Polish Notation (RPN). This notation is a mathematical notation in which every operator follows all of its operands, eliminating the need for parentheses to indicate the order of operations.

## Problem Description

You are given an array of strings, `tokens`, that represent an expression in Reverse Polish Notation. Your task is to evaluate the expression and return the result as an integer. The valid operators are `+`, `-`, `*`, and `/`, which correspond to addition, subtraction, multiplication, and integer division, respectively. Integer division should truncate toward zero.

## Topics Covered

- **Stack Data Structure**: The problem requires the use of a stack to evaluate the RPN expression.
- **Mathematical Operations**: Understanding how to perform basic arithmetic operations and handle integer division.
- **String Manipulation**: Parsing the input tokens to identify operators and operands.

## Constraints

- The input tokens array will have at least one token.
- The number of tokens will not exceed 10,000.
- Each token is either an operator or a valid integer in the range of a 32-bit signed integer.

## Examples

1. **Example 1**:
    - **Input**: `tokens = ["2", "1", "+", "3", "*"]`
    - **Output**: `9`
    - **Explanation**: The expression evaluates as follows: `((2 + 1) * 3) = 9`.

2. **Example 2**:
    - **Input**: `tokens = ["4", "13", "5", "/", "+"]`
    - **Output**: `6`
    - **Explanation**: The expression evaluates as follows: `4 + (13 / 5) = 4 + 2 = 6`.

3. **Example 3**:
    - **Input**: `tokens = ["10", "6", "9", "3", "/", "-11", "*", "/", "*"]`
    - **Output**: `-1`
    - **Explanation**: The expression evaluates step by step to `10 * (6 / (9 / -11)) = -1`.

## Solution Overview

The solution involves iterating through the `tokens` array and using a stack to keep track of operands. When an operator is encountered, the top two operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack. At the end of the iteration, the stack will contain one element, which is the result of the expression.

## Complexities

- **Time Complexity**: `O(n)`, where `n` is the number of tokens. Each token is processed once.
- **Space Complexity**: `O(n)` in the worst case, where all tokens are operands and stored in the stack.

## Key Insights

- The stack is a natural fit for evaluating RPN expressions because it allows for easy access to the most recent operands.
- Handling integer division correctly is crucial, especially in languages where division can yield different results for negative numbers.

## Algorithm

1. **Initialize a Stack**: Create an empty stack to hold operands.
2. **Iterate Through Tokens**:
    - For each token:
        - If it is a number, convert it to an integer and push it onto the stack.
        - If it is an operator, pop the top two numbers from the stack, perform the operation, and push the result back onto the stack.
3. **Return the Result**: After processing all tokens, the top of the stack contains the result of the RPN expression.

## Special Cases

- **Division by Zero**: The problem guarantees valid input, so division by zero should not occur.
- **Negative Numbers**: Ensure that the integer division truncates towards zero, which may require special handling depending on the language.

## Example Explanation

Consider the input `tokens = ["2", "1", "+", "3", "*"]`:

1. **Initialization**: Start with an empty stack.
2. **Processing Tokens**:
    - Push `2` onto the stack: Stack is now `[2]`.
    - Push `1` onto the stack: Stack is now `[2, 1]`.
    - Encounter `+`: Pop `1` and `2`, calculate `2 + 1 = 3`, and push the result: Stack is now `[3]`.
    - Push `3` onto the stack: Stack is now `[3, 3]`.
    - Encounter `*`: Pop `3` and `3`, calculate `3 * 3 = 9`, and push the result: Stack is now ``.
3. **Final Result**: The stack contains one element, `9`, which is the result of the expression.

This structured approach effectively evaluates the RPN expression while ensuring that all operations are performed correctly and efficiently.
