/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    static const vector<string> morse = {
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
    unordered_set<string> transformations;
    for (const string &word : words) {
      string code;
      for (char c : word) {
        code += morse[c - 'a'];
      }
      transformations.insert(code);
    }
    return transformations.size();
  }
};
// @lc code=end
