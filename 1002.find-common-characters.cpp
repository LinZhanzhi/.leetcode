/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    // Initialize minFreq to store the minimum frequency of each character
    // across all words
    vector<int> minFreq(26, INT_MAX);
    // Iterate through each word in the input
    for (const string &word : words) {
      // Count the frequency of each character in the current word
      vector<int> freq(26, 0);
      for (char c : word) {
        freq[c - 'a']++;
      }
      // Update minFreq to keep the minimum frequency for each character
      // If minFreq[i] == 0 after this update, it means that the character ('a'
      // + i) does not appear in at least one of the words, so it should not be
      // included in the result.
      for (int i = 0; i < 26; ++i) {
        minFreq[i] = min(minFreq[i], freq[i]);
      }
    }
    // Prepare the result vector to store common characters
    vector<string> res;
    // For each character, add it to the result as many times as its minimum
    // frequency
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < minFreq[i]; ++j) {
        res.push_back(string(1, 'a' + i));
      }
    }
    // Return the list of common characters
    return res;
  }
};
// @lc code=end
