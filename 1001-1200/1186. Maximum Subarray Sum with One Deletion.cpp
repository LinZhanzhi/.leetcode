/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.



Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.


Constraints:

1 <= arr.length <= 105
-104 <= arr[i] <= 104
*/
/*
Hint 1
How to solve this problem if no deletions are allowed ?
Hint 2
Try deleting each element and find the maximum subarray sum to both sides of that element.
Hint 3
To do that efficiently, use the idea of Kadane's algorithm.
*/
class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n), right(n);
        // left[i] is the maximum subarray sum for arr[0..i] that ends in arr[i] without deletion
        // right[i] is the maximum subarray sum for arr[i..n-1] that ends in arr[i] without deletion
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1] + arr[i], arr[i]);
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1] + arr[i], arr[i]);
        int ans = *max_element(left.begin(), left.end());
        for (int i = 1; i < n - 1; i++)
            ans = max(ans, left[i - 1] + right[i + 1]);
        return ans;
    }
};