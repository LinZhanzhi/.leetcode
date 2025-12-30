/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

#include <queue>
using namespace std;

// @lc code=start
class MyStack {
public:
  MyStack() {
    // No initialization needed
  }

  void push(int x) {
    q2.push(x);
    // Move all elements from q1 to q2
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    // Swap q1 and q2
    swap(q1, q2);
  }

  int pop() {
    int val = q1.front();
    q1.pop();
    return val;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }

private:
  queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
