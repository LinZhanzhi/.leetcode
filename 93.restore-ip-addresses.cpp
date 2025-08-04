/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    int n = s.size();
    // Helper lambda to check if a segment is valid
    auto isValid = [](const string &seg) -> bool {
      // If the segment is empty or has more than 3 digits, it is invalid.
      if (seg.empty() || seg.size() > 3)
        return false;
      // If the segment starts with '0' and has more than 1 digit, it is
      // invalid.
      if (seg[0] == '0' && seg.size() > 1)
        return false;
      int val = stoi(seg);
      // If the segment is greater than 255, it is invalid.
      return val >= 0 && val <= 255;
    };
    // Try all possible splits for the first three segments.
    for (int i = 1; i < min(4, n); ++i) {
      for (int j = i + 1; j < i + min(4, n - i); ++j) {
        for (int k = j + 1; k < j + min(4, n - j); ++k) {
          if (k >= n)
            continue;
          // Get the four segments.
          string s1 = s.substr(0, i);     // first segment is s[0:i)
          string s2 = s.substr(i, j - i); // second segment is s[i:j)
          string s3 = s.substr(j, k - j); // third segment is s[j:k)
          string s4 = s.substr(k);        // fourth segment is s[k:n)
          if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
            res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
