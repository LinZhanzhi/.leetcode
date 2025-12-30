/*
 * @lc app=leetcode id=3318 lang=cpp
 *
 * [3318] Find X-Sum of All K-Long Subarrays I
 */

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  // Helper to count frequencies of elements in nums[l..r-1]
  unordered_map<int, int> countFrequencies(const vector<int> &nums, int l,
                                           int r) {
    unordered_map<int, int> freq;
    for (int j = l; j < r; ++j) {
      freq[nums[j]]++;
    }
    return freq;
  }

  // Helper to create a sorted vector of (num, freq) pairs
  vector<pair<int, int>> getSortedFreqVec(const unordered_map<int, int> &freq) {
    vector<pair<int, int>> freq_vec;
    for (const auto &p : freq) {
      freq_vec.push_back({p.first, p.second});
    }
    // Sort by freq descending, then by num descending
    sort(freq_vec.begin(), freq_vec.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           if (a.second != b.second)
             return a.second > b.second;
           return a.first > b.first;
         });
    return freq_vec;
  }

  // Helper to collect the top x elements by frequency (and value)
  unordered_set<int> collectTopX(const vector<pair<int, int>> &freq_vec,
                                 int x) {
    unordered_set<int> keep;
    for (int t = 0; t < freq_vec.size() && t < x; ++t) {
      keep.insert(freq_vec[t].first);
    }
    return keep;
  }

  // Helper to compute the sum for the current window
  int computeWindowSum(const vector<int> &nums, int l, int r,
                       const vector<pair<int, int>> &freq_vec,
                       const unordered_set<int> &keep, int x) {
    int sum = 0;
    if (freq_vec.size() <= x) {
      for (int j = l; j < r; ++j) {
        sum += nums[j];
      }
    } else {
      for (int j = l; j < r; ++j) {
        if (keep.count(nums[j]))
          sum += nums[j];
      }
    }
    return sum;
  }

  vector<int> findXSum(vector<int> &nums, int k, int x) {
    vector<int> answer;
    int n = nums.size();
    for (int i = 0; i <= n - k; ++i) {
      auto freq = countFrequencies(nums, i, i + k);
      auto freq_vec = getSortedFreqVec(freq);
      auto keep = collectTopX(freq_vec, x);
      int sum = computeWindowSum(nums, i, i + k, freq_vec, keep, x);
      answer.push_back(sum);
    }
    return answer;
  }
};
// @lc code=end
