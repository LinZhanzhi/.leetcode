/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Use three pointers: one for the end of nums1, one for the end of nums2,
        // and one for the position to write in the merged array
        int p1 = m - 1;      // Last valid element in nums1
        int p2 = n - 1;      // Last element in nums2
        int p = m + n - 1;   // Last position in nums1
        
        // Merge from the end to avoid overwriting elements in nums1
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
        // If there are remaining elements in nums2, copy them
        // (remaining elements in nums1 are already in their correct positions)
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
// @lc code=end

