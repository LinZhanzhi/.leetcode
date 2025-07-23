/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
  int calPoints(vector<string> &operations) {
    vector<int> record;
    for (const string &op : operations) {
      if (op == "C") {
        record.pop_back();
      } else if (op == "D") {
        record.push_back(2 * record.back());
      } else if (op == "+") {
        record.push_back(record[record.size() - 1] + record[record.size() - 2]);
      } else {
        record.push_back(stoi(op));
      }
    }
    int sum = 0;
    for (int score : record) {
      sum += score;
    }
    return sum;
  }
};
// @lc code=end
