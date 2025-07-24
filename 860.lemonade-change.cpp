/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
      if (bill == 5) {
        five++;
      } else if (bill == 10) {
        if (five == 0)
          return false;
        five--;
        ten++;
      } else { // bill == 20
        // When a customer pays with a $20 bill, it's best to give one $10 and
        // one $5 as change if possible. This is because $10 bills are less
        // common (can only be received from $10 payments), so using them first
        // preserves more $5 bills for future transactions. If we use three $5
        // bills instead, we may run out of $5 bills sooner and be unable to
        // give change for $10 bills later.
        if (ten > 0 && five > 0) {
          ten--;
          five--;
        } else if (five >= 3) {
          five -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
