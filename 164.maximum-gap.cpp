/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

/*
  This solution finds the maximum difference between successive elements in the
  sorted form of an array, without actually sorting the array (which would be
  O(n log n)). It uses a bucket-based approach to achieve O(n) time.

  --- Algorithm Explanation ---

  1. Find the minimum and maximum values in the array.
  2. Divide the range [min, max] into buckets. Each bucket will hold the min and
  max value of the numbers assigned to it.
  3. For each number, put it into its corresponding bucket.
  4. The maximum gap will be the maximum difference between the minimum of the
  current bucket and the maximum of the previous non-empty bucket.

  --- Example ---

  Let's use the input: nums = [3, 6, 9, 1]

  Step 1: minNum = 1, maxNum = 9, n = 4

  Step 2: bucketSize = max(1, (9-1)/(4-1)) = max(1, 8/3) = 2
          bucketCount = (9-1)/2 + 1 = 4 + 1 = 5

  Buckets: [bucket 0, bucket 1, bucket 2, bucket 3, bucket 4]
           Each bucket will store min and max of numbers assigned to it.

  Step 3: Assign numbers to buckets:
    - 3: idx = (3-1)/2 = 1
    - 6: idx = (6-1)/2 = 2
    - 9: idx = (9-1)/2 = 4
    - 1: idx = (1-1)/2 = 0

    After assignment:
      bucket 0: min=1, max=1, used
      bucket 1: min=3, max=3, used
      bucket 2: min=6, max=6, used
      bucket 3: unused
      bucket 4: min=9, max=9, used

  Step 4: Compute max gap by iterating buckets:
    - prevMax = 1
    - i=0: used, gap = 1-1=0, prevMax=1
    - i=1: used, gap = 3-1=2, prevMax=3
    - i=2: used, gap = 6-3=3, prevMax=6
    - i=3: unused, skip
    - i=4: used, gap = 9-6=3, prevMax=9

    The maximum gap is 3.

  --- Time Complexity Justification ---

  - Finding min and max: O(n)
  - Assigning numbers to buckets: O(n)
  - Scanning buckets to find max gap: O(n)
  - Total: O(n)

  This approach is more efficient than sorting (which is O(n log n)), achieving
  O(n) time by leveraging the pigeonhole principle and properties of the bucket
  construction.

  The key insight is that if we divide the range [min, max] into n-1 buckets
  (where n is the number of elements), the maximum possible gap cannot be within
  a single bucket. This is because the maximum difference between any two
  numbers within the same bucket is at most the bucket size, which is defined as
  bucketSize = max(1, (maxNum - minNum) / (n - 1)). However, the actual maximum
  gap could be larger than the bucket size, and such a gap can only occur
  between the maximum value of one bucket and the minimum value of the next
  non-empty bucket.

  To see why, consider that the minimum possible maximum gap (if the numbers are
  evenly distributed) is exactly the bucket size. If there were a larger gap
  within a bucket, then the bucket size would have been larger, contradicting
  our construction. Therefore, the true maximum gap must be between the maximum
  of one bucket and the minimum of the next non-empty bucket.

  By only tracking the min and max of each bucket and skipping empty buckets, we
  ensure that we do not miss any possible maximum gap, and we avoid unnecessary
  comparisons within buckets. This guarantees correctness and optimal
  efficiency.

*/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maximumGap(vector<int> &nums) {
    // If there are fewer than 2 elements, no gap exists
    if (nums.size() < 2)
      return 0;
    int n = nums.size();

    // Find the minimum and maximum values in the array
    int minNum = *min_element(nums.begin(), nums.end());
    int maxNum = *max_element(nums.begin(), nums.end());
    if (minNum == maxNum)
      return 0; // All elements are the same

    // Calculate bucket size and count
    int bucketSize = max(1, (maxNum - minNum) / (n - 1));
    int bucketCount = (maxNum - minNum) / bucketSize + 1;

    // Initialize buckets
    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);
    vector<bool> bucketUsed(bucketCount, false);

    // Place each number in a bucket
    for (int num : nums) {
      int idx = (num - minNum) / bucketSize;
      bucketMin[idx] = min(bucketMin[idx], num);
      bucketMax[idx] = max(bucketMax[idx], num);
      bucketUsed[idx] = true;
    }

    // Scan through buckets to find the maximum gap
    int maxGap = 0;
    int prevMax = minNum;
    for (int i = 0; i < bucketCount; ++i) {
      if (!bucketUsed[i])
        continue; // Skip empty buckets
      // The gap is between the min of current bucket and max of previous
      // non-empty bucket
      maxGap = max(maxGap, bucketMin[i] - prevMax);
      prevMax = bucketMax[i];
    }
    return maxGap;
  }
};
// @lc code=end
