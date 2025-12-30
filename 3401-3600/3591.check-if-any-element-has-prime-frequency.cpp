/*
 * @lc app=leetcode id=3591 lang=cpp
 *
 * [3591] Check if Any Element Has Prime Frequency
 */

// @lc code=start
class Solution {
public:
  bool checkPrimeFrequency(vector<int> &nums) {
    // INSERT_YOUR_CODE
    unordered_map<int, int> freq;
    for (int n : nums) {
      freq[n]++;
    }
    auto isPrime = [](int n) {
      if (n <= 1)
        return false;
      if (n == 2)
        return true;
      if (n % 2 == 0)
        return false;
      for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
          return false;
      }
      return true;
    };
    for (const auto &[num, f] : freq) {
      if (isPrime(f))
        return true;
    }
    return false;
  }
};
// @lc code=end
