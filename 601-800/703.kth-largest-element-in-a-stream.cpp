/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class KthLargest {
  int k_;
  priority_queue<int, vector<int>, greater<int>> minHeap;

public:
  KthLargest(int k, vector<int> &nums) {
    k_ = k;
    for (int num : nums) {
      minHeap.push(num);
      if (minHeap.size() > k_) {
        minHeap.pop();
      }
    }
  }

  int add(int val) {
    minHeap.push(val);
    if (minHeap.size() > k_) {
      minHeap.pop();
    }
    return minHeap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
