/*
 * @lc app=leetcode id=2423 lang=cpp
 *
 * [2423] Remove Letter To Equalize Frequency
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // Helper function to count frequencies of each letter, skipping the character
  // at skipIdx
  vector<int> countFrequencies(const string &word, int skipIdx) {
    vector<int> freq(26, 0);
    for (int j = 0; j < word.size(); ++j) {
      if (j == skipIdx)
        continue;
      freq[word[j] - 'a']++;
    }
    return freq;
  }

  // Helper function to check if all non-zero frequencies are equal
  bool allFrequenciesEqual(const vector<int> &freq) {
    int f = 0;
    for (int k = 0; k < 26; ++k) {
      if (freq[k] == 0)
        continue;
      if (f == 0)
        f = freq[k];
      else if (freq[k] != f)
        return false;
    }
    return true;
  }

  bool equalFrequency(string word) {
    // Try removing each character one by one
    for (int i = 0; i < word.size(); ++i) {
      vector<int> freq = countFrequencies(word, i);
      if (allFrequenciesEqual(freq))
        return true; // Found a valid removal that equalizes frequency
    }
    return false; // No valid removal found
  }
};
// @lc code=end
