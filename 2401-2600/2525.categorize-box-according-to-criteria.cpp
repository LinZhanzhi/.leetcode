/*
 * @lc app=leetcode id=2525 lang=cpp
 *
 * [2525] Categorize Box According to Criteria
 */

// @lc code=start
class Solution {
public:
  string categorizeBox(int length, int width, int height, int mass) {
    bool bulky = false, heavy = false;
    // Check for bulky
    if (length >= 10000 || width >= 10000 || height >= 10000) {
      bulky = true;
    } else {
      long long volume = 1LL * length * width * height;
      if (volume >= 1000000000LL) {
        bulky = true;
      }
    }
    // Check for heavy
    if (mass >= 100) {
      heavy = true;
    }
    // Return category
    if (bulky && heavy)
      return "Both";
    if (bulky)
      return "Bulky";
    if (heavy)
      return "Heavy";
    return "Neither";
  }
};
// @lc code=end
