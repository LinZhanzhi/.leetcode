/*
 * @lc app=leetcode id=2614 lang=cpp
 *
 * [2614] Prime In Diagonal
 */

// @lc code=start
class Solution {
public:
  int diagonalPrime(vector<vector<int>> &nums) {
    int n = nums.size();
    int maxPrime = 0;

    // Helper function to check if a number is prime
    auto isPrime = [](int x) -> bool {
      if (x < 2)
        return false;
      if (x == 2 || x == 3)
        return true;
      if (x % 2 == 0 || x % 3 == 0)
        return false;
      for (int i = 5; i * 1LL * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0)
          return false;
      }
      return true;
    };

    for (int i = 0; i < n; ++i) {
      int val1 = nums[i][i];
      int val2 = nums[i][n - i - 1];
      if (isPrime(val1))
        maxPrime = std::max(maxPrime, val1);
      if (isPrime(val2))
        maxPrime = std::max(maxPrime, val2);
    }
    return maxPrime;
  }
};
// @lc code=end
