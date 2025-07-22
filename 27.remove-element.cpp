/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Use two pointers: one for writing non-val elements,
        // and one for scanning through the array
        int writeIndex = 0;
        
        // Scan through the array
        for (int readIndex = 0; readIndex < nums.size(); readIndex++) {
            // If current element is not equal to val, write it to the result
            if (nums[readIndex] != val) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        // Return the number of elements not equal to val
        return writeIndex;
    }
};
// @lc code=end

