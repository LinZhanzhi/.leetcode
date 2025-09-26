/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem gives us a nested list of integers, where each element can be
 * either a single integer or another list (which can itself contain integers or
 * lists, and so on). Our goal is to create an iterator that "flattens" this
 * structure, so that we can retrieve all the integers in the correct order, one
 * by one, as if the nested structure was a simple flat list.
 *
 * High-Level Summary:
 * ----
 * The solution uses a stack to simulate the recursive flattening of the nested
 * list. The stack keeps track of where we are in each nested list. We always
 * make sure that the top of the stack points to the next integer to return.
 * When hasNext() is called, we traverse down the nested structure (using the
 * stack) until we find an integer at the top. The next() function then returns
 * this integer and advances the iterator. This approach avoids flattening the
 * entire list up front, so it is efficient in both time and space for large or
 * deeply nested lists.
 *
 * Time Complexity:
 *   - Each integer and list is visited at most once, so the total time for all
 * calls is O(N), where N is the total number of integers and lists.
 *   - Each call to hasNext() and next() is O(1) amortized.
 *
 * Space Complexity:
 *   - O(D), where D is the maximum depth of the nested list, due to the stack.
 */

#include <vector>
using std::vector;

// The NestedIterator class implements an iterator over a nested list of
// integers.
class NestedIterator {
private:
  // The stack stores pairs of iterators: (current position, end position) for
  // each nested list. This allows us to traverse the nested structure in a
  // controlled, iterative way.
  vector<std::pair<vector<NestedInteger>::iterator,
                   vector<NestedInteger>::iterator>>
      stack;

public:
  // Constructor: initializes the stack with the iterators for the top-level
  // nestedList.
  NestedIterator(vector<NestedInteger> &nestedList) {
    // Push the begin and end iterators of the input list onto the stack.
    stack.emplace_back(nestedList.begin(), nestedList.end());
  }

  // Returns the next integer in the nested list.
  int next() {
    // hasNext() ensures that the top of the stack is an integer.
    // We can safely return it and advance the iterator.
    int result = stack.back().first->getInteger();
    ++stack.back().first; // Move to the next element in the current list.
    return result;
  }

  // Returns true if there are more integers to return, false otherwise.
  bool hasNext() {
    // Loop until we find an integer at the top of the stack, or the stack is
    // empty.
    while (!stack.empty()) {
      // If we've reached the end of the current list, pop it off the stack.
      if (stack.back().first == stack.back().second) {
        stack.pop_back();
        continue;
      }
      // If the current element is an integer, we're ready to return it.
      if (stack.back().first->isInteger()) {
        return true;
      }
      // Otherwise, it's a nested list. Drill down: push its iterators onto the
      // stack.
      auto &nestedList = stack.back().first->getList();
      ++stack.back().first; // Advance the parent iterator before descending.
      stack.emplace_back(nestedList.begin(), nestedList.end());
    }
    // If the stack is empty, there are no more integers.
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
