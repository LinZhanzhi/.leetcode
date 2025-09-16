/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /*
    Proof of correctness:

    - The input array 'numbers' is sorted in non-decreasing order.
    - We use two pointers: 'left' starting at the beginning, 'right' at the end.
    - At each step, we check the sum of numbers[left] + numbers[right]:
        * If the sum equals the target, we have found the unique solution
    (guaranteed by the problem).
        * If the sum is less than the target, we want a larger sum. Since the
    array is sorted in non-decreasing order, increasing 'left' (moving it
    rightward) will increase numbers[left] and thus the sum. Increasing 'right'
    would move it out of bounds or keep it the same (since it's already at the
    end), and decreasing 'right' would only decrease the sum. Therefore, we move
    'left' rightward to try to reach the target.
        * If the sum is greater than the target, decreasing 'right' decreases
    the sum, so we move 'right' leftward.
    - This process eliminates impossible pairs at each step:
        * If numbers[left] + numbers[right] < target, then for any k < right,
    numbers[left] + numbers[k] < target (since numbers[k] <= numbers[right]), so
    increasing left is the only way to possibly reach the target.
        * If numbers[left] + numbers[right] > target, then for any k > left,
    numbers[k] + numbers[right] > target (since numbers[k] >= numbers[left]), so
    decreasing right is the only way to possibly reach the target.
    - Since the problem guarantees exactly one solution, the loop will always
    find and return it.
    - The algorithm runs in O(n) time, scanning each element at most once.


    at the beginning, 0 = left <= ansleft <= ansright <= right = numbers.size()
    - 1

    as left and right move towards middle, one of this two conditions will be
    met:
        1. left get to ansleft
            in this condition, since ansright <= right, current sum will be >=
    target, so right will decrease until right = ansright and when right =
    ansright, current sum = target, so we return the answer
        2. right get to ansright
            in this condition, since left <= ansleft, current sum will be <=
    target, so left will increase until left = ansleft and when left = ansleft,
    current sum = target, so we return the answer


    This two-pointer approach is correct and optimal for a sorted array.
  */
  vector<int> twoSum(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target) {
        // Return 1-based indices
        return {left + 1, right + 1};
      } else if (sum < target) {
        ++left;
      } else {
        --right;
      }
    }
    // The problem guarantees exactly one solution, so this will never be
    // reached.
    return {};
  }
};
// @lc code=end
