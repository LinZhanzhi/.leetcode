/*
 * @lc app=leetcode id=2032 lang=cpp
 *
 * [2032] Two Out of Three
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                            vector<int> &nums3) {
    unordered_map<int, int> count;
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());
    unordered_set<int> s3(nums3.begin(), nums3.end());

    for (int n : s1)
      count[n]++;
    for (int n : s2)
      count[n]++;
    for (int n : s3)
      count[n]++;

    vector<int> res;
    for (const auto &p : count) {
      if (p.second >= 2)
        res.push_back(p.first);
    }
    return res;
  }
};
// @lc code=end
