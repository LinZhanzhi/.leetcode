/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
  double average(vector<int> &salary) {
    int n = salary.size();
    int min_salary = salary[0], max_salary = salary[0];
    int sum = 0;
    for (int s : salary) {
      sum += s;
      if (s < min_salary)
        min_salary = s;
      if (s > max_salary)
        max_salary = s;
    }
    sum -= (min_salary + max_salary);
    return (double)sum / (n - 2);
  }
};
// @lc code=end
