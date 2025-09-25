/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given an array of n+1 integers where each integer is between 1 and n
 * (inclusive). There is exactly one number that appears more than once, and we
 * need to find it. We cannot modify the input array and must use only constant
 * extra space. The challenge is to find the duplicate efficiently, ideally in
 * linear time.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses Floyd's Tortoise and Hare (Cycle Detection) algorithm.
 * By treating the array as a linked list where each index points to
 * nums[index], the duplicate number forms a cycle. The entry point of the cycle
 * is the duplicate. The algorithm works in two phases:
 *   1. Detect a cycle using two pointers moving at different speeds.
 *   2. Find the entry point of the cycle, which is the duplicate number.
 * This approach does not modify the array and uses only constant extra space.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    // Phase 1: Use Floyd's Tortoise and Hare to find the intersection point in
    // the cycle
    int slow = nums[0]; // Start slow pointer at the first element
    int fast = nums[0]; // Start fast pointer at the first element

    // Move slow by one step and fast by two steps until they meet
    do {
      slow = nums[slow];       // Move slow pointer by one step
      fast = nums[nums[fast]]; // Move fast pointer by two steps
    } while (slow != fast); // Loop until both pointers meet

    // Phase 2: Find the entrance to the cycle (duplicate number)
    slow = nums[0]; // Reset slow pointer to the start
    // Move both pointers at the same speed; the point they meet is the
    // duplicate
    while (slow != fast) {
      slow = nums[slow]; // Move slow by one step
      fast = nums[fast]; // Move fast by one step
    }

    // Both pointers now point to the duplicate number
    return slow;
  }
};
// @lc code=end
