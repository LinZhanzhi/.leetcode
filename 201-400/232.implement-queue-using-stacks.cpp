/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <stack>
using namespace std;

// @lc code=start
class MyQueue {
public:
  MyQueue() {
    // No initialization needed
  }

  void push(int x) {
    // push to inStack
    inStack.push(x);
  }

  int pop() {
    // move all elements from inStack to outStack
    moveInToOut();
    // pop from outStack
    int val = outStack.top();
    outStack.pop();
    return val;
  }

  int peek() {
    // move all elements from inStack to outStack
    moveInToOut();
    // return top of outStack
    return outStack.top();
  }

  // return true if both stacks are empty
  bool empty() { return inStack.empty() && outStack.empty(); }

private:
  stack<int> inStack, outStack;
  // move all elements from inStack to outStack
  void moveInToOut() {
    // if outStack is empty, move all elements from inStack to outStack
    if (outStack.empty()) {
      while (!inStack.empty()) {
        outStack.push(inStack.top());
        inStack.pop();
      }
    }
    // if outStack is not empty, do nothing
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
