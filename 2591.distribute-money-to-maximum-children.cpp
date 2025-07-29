/*
 * @lc app=leetcode id=2591 lang=cpp
 *
 * [2591] Distribute Money to Maximum Children
 */

// @lc code=start
class Solution {
public:
  int distMoney(int money, int children) {
    // first give every one a dollar
    money -= children;
    // if not enough money to give each child at least 1 dollar, impossible
    if (money < 0) {
      return -1;
    }
    // if only one child, must not give 4 dollars
    if (money == 3 && children == 1) {
      return -1;
    }
    // now try to give 7 dollars to each child
    int count = 0;
    while (money >= 7 && count < children) {
      money -= 7;
      count++;
    }
    // if there is still money left, give it to the last child
    if (count == children) {
      if (money > 0)
        count--;
      return count;
    }
    // now we have less than 7 dollars and some children having one dollar
    int left_children = children - count;
    if (left_children == 1 && money == 3) {
      return count - 1;
    }
    return count;
  }
};
// @lc code=end
