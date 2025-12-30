/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */

// @lc code=start
class Solution {
public:
  vector<int> decode(vector<int> &encoded, int first) {
    vector<int> arr;
    arr.push_back(first);
    for (int i = 0; i < encoded.size(); ++i) {
      arr.push_back(arr.back() ^ encoded[i]);
    }
    return arr;
  }
};
// @lc code=end
