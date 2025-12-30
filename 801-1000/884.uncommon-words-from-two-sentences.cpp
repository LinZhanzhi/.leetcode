/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution {
public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> res;
    unordered_map<string, int> freq;
    istringstream iss1(s1), iss2(s2);
    string word;
    while (iss1 >> word) {
      freq[word]++;
    }
    while (iss2 >> word) {
      freq[word]++;
    }
    istringstream iss1_check(s1), iss2_check(s2);
    // Check words in s1
    while (iss1_check >> word) {
      if (freq[word] == 1)
        res.push_back(word);
    }
    // Check words in s2
    while (iss2_check >> word) {
      if (freq[word] == 1)
        res.push_back(word);
    }
    return res;
  }
};
// @lc code=end
