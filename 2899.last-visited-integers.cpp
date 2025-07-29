/*
 * @lc app=leetcode id=2899 lang=cpp
 *
 * [2899] Last Visited Integers
 */

// @lc code=start
class Solution {
public:
  vector<int> lastVisitedIntegers(vector<int> &nums) {
    vector<int> seen;
    vector<int> ans;
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == -1) {
        k++;
        if (k <= seen.size()) {
          ans.push_back(seen[k - 1]);
        } else {
          ans.push_back(-1);
        }
      } else {
        seen.insert(seen.begin(), nums[i]);
        k = 0;
      }
    }
    return ans;
  }
};
// @lc code=end
