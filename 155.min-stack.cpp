/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>

/*
  MinStack is a stack data structure that supports push, pop, top, and
  retrieving the minimum element in constant time.

  How it works:
  - It uses two stacks:
      1. 's' stores all the values pushed onto the stack.
      2. 'min_s' keeps track of the minimum value at each level of the stack.
  - When pushing a value, we also push the new minimum (either the new value or
  the previous minimum) onto 'min_s'.
  - When popping, we pop from both stacks to keep them in sync.
  - The current minimum is always at the top of 'min_s'.
*/

class MinStack {
private:
  std::stack<int> s;     // Main stack to store all values
  std::stack<int> min_s; // Auxiliary stack to store current minimums

public:
  MinStack() {
    // No initialization needed
  }

  // Pushes a value onto the stack and updates the minimum stack
  void push(int val) {
    s.push(val);
    // If min_s is empty or val is less than or equal to current min, push val;
    // otherwise, repeat the current min
    if (min_s.empty() || val <= min_s.top()) {
      min_s.push(val);
    } else {
      min_s.push(min_s.top());
    }
  }

  // Removes the top element from both stacks
  void pop() {
    s.pop();
    min_s.pop();
  }

  // Returns the top element of the main stack
  int top() { return s.top(); }

  // Returns the current minimum element in the stack
  int getMin() { return min_s.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
