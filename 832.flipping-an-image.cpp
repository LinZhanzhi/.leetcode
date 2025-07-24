/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
    int n = image.size();
    for (int i = 0; i < n; ++i) {
      int left = 0, right = n - 1;
      while (left <= right) {
        // Swap and invert at the same time
        if (left == right) {
          image[i][left] ^= 1;
        } else {
          int temp = image[i][left] ^ 1;
          image[i][left] = image[i][right] ^ 1;
          image[i][right] = temp;
        }
        ++left;
        --right;
      }
    }
    return image;
  }
};
// @lc code=end
