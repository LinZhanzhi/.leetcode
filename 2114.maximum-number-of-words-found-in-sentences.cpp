/*
 * @lc app=leetcode id=2114 lang=cpp
 *
 * [2114] Maximum Number of Words Found in Sentences
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int mostWordsFound(vector<string> &sentences) {
    int maxWords = 0;
    for (const string &sentence : sentences) {
      int wordCount = countWords(sentence);
      if (wordCount > maxWords) {
        maxWords = wordCount;
      }
    }
    return maxWords;
  }

private:
  // Helper function to count words in a sentence
  int countWords(const string &sentence) {
    int wordCount = 1; // At least one word in each sentence
    for (char c : sentence) {
      if (c == ' ') {
        wordCount++;
      }
    }
    return wordCount;
  }
};
// @lc code=end
