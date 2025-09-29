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

/*
/*
* Brief, Digested Understanding:
* ----
* The NestedIterator class allows us to flatten a nested list of integers (where
* each element can be either an integer or another list) and iterate through all
* the integers in order, as if the list was fully flattened. The iterator uses a
* stack to keep track of where we are in each nested list, so we can efficiently
* move through the structure without flattening everything up front.
*
* High-Level Summary:
* ----
* The iterator maintains a stack of pairs of iterators, each representing our
* current position in a nested list. The hasNext() method ensures that the top
* of the stack always points to an integer (not a sublist), drilling down into
* sublists as needed. The next() method then returns this integer and advances
* the iterator. This approach is efficient, using O(d) space where d is the
* maximum depth of nesting, and each integer is visited exactly once.
*
* Time Complexity: O(1) amortized per call to next() and hasNext().
* Space Complexity: O(d), where d is the maximum nesting depth.
*/

/*
 * Step-by-step Example: Input: nestedList = [[1,1],2,[1,1]]
 *
 * Let's walk through how the NestedIterator processes this input:
 *
 * Initial nestedList: [[1,1], 2, [1,1]]
 *
 * 1. Construction:
 *    - The stack is initialized with iterators pointing to the beginning and
 * end of the top-level list: stack = [{begin, end}]
 *
 * 2. First hasNext():
 *    - Top of stack points to [[1,1]] (a list, not an integer).
 *    - Drill down: push iterators for [1,1] onto the stack.
 *    - Now, stack = [{top-level begin, end}, {begin of [1,1], end of [1,1]}]
 *    - Top now points to 1 (an integer), so hasNext() returns true.
 *
 * 3. First next():
 *    - Returns 1 (from the innermost [1,1]).
 *    - Advances the innermost iterator to the next element (still in [1,1]).
 *
 * 4. Second hasNext():
 *    - Top of stack points to 1 (still an integer).
 *    - hasNext() returns true.
 *
 * 5. Second next():
 *    - Returns 1 (second element of [1,1]).
 *    - Advances the innermost iterator to the end of [1,1].
 *    - Since we've reached the end, pop this level off the stack.
 *
 * 6. Third hasNext():
 *    - Now, top of stack points to 2 (an integer).
 *    - hasNext() returns true.
 *
 * 7. Third next():
 *    - Returns 2.
 *    - Advances the top-level iterator to the next element ([1,1]).
 *
 * 8. Fourth hasNext():
 *    - Top of stack points to [1,1] (a list).
 *    - Drill down: push iterators for this [1,1] onto the stack.
 *    - Now, top points to 1 (an integer).
 *    - hasNext() returns true.
 *
 * 9. Fourth next():
 *    - Returns 1 (from the second [1,1]).
 *    - Advances the innermost iterator.
 *
 * 10. Fifth hasNext():
 *     - Top of stack points to 1 (second element of [1,1]).
 *     - hasNext() returns true.
 *
 * 11. Fifth next():
 *     - Returns 1.
 *     - Advances the innermost iterator to the end of [1,1].
 *     - Pop this level off the stack.
 *
 * 12. Sixth hasNext():
 *     - Top-level iterator is now at the end.
 *     - Pop this level off the stack.
 *     - Stack is empty, so hasNext() returns false.
 *
 * Output sequence: 1, 1, 2, 1, 1
 *
 * This step-by-step shows how the stack is used to traverse the nested
 * structure in order, always drilling down into lists and returning integers in
 * the correct sequence.
 */
*/
    // @lc code=end
