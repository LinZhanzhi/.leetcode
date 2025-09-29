/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to check if a given sequence of bytes (represented as
 * integers) forms a valid UTF-8 encoding. Each character in UTF-8 can be 1 to 4
 * bytes long, and the pattern of the leading bits in each byte tells us how
 * many bytes the character uses. For multi-byte characters, the first byte has
 * a specific pattern, and each following byte must start with '10'. We need to
 * walk through the array and verify that every character follows these rules.
 *
 * High-Level Summary:
 * ----
 * The solution iterates through the data array, checking each byte to determine
 * if it starts a new UTF-8 character and, if so, how many bytes that character
 * should have. For each multi-byte character, it checks that the following
 * bytes are valid continuation bytes (i.e., they start with '10'). If any byte
 * does not fit the expected pattern, or if there are not enough continuation
 * bytes, the function returns false. Otherwise, it returns true.
 *
 * Time Complexity: O(N), where N is the number of bytes in the input array.
 * Space Complexity: O(1), as only a few variables are used for counting and
 * checking.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  // Function to check if the input data is a valid UTF-8 encoding
  bool validUtf8(vector<int> &data) {
    int n = data.size(); // Get the number of bytes in the input
    int i = 0;           // Index to iterate through the data

    while (i < n) {
      int byte = data[i] & 0xFF; // Only use the least significant 8 bits

      // Count the number of leading 1's in the current byte
      int numBytes = 0;
      int mask = 0x80; // 1000 0000 in binary

      // For the first byte, count how many leading 1's there are
      while (mask & byte) {
        numBytes++;
        mask >>= 1;
      }

      // If the first bit is 0, it's a 1-byte character
      if (numBytes == 0) {
        i++; // Move to the next byte
        continue;
      }

      // UTF-8 characters can only be 2, 3, or 4 bytes long
      if (numBytes == 1 || numBytes > 4) {
        // numBytes == 1 is invalid (10xxxxxx is only for continuation bytes)
        // numBytes > 4 is invalid (UTF-8 allows up to 4 bytes)
        return false;
      }

      // Check if there are enough bytes left for this character
      if (i + numBytes > n) {
        return false;
      }

      // Check the next numBytes - 1 bytes to ensure they are valid continuation
      // bytes
      for (int j = 1; j < numBytes; ++j) {
        int nextByte = data[i + j] & 0xFF; // Get the next byte
        // Continuation bytes must start with '10' (i.e., the two most
        // significant bits are 10)
        if ((nextByte & 0xC0) != 0x80) { // 0xC0 = 1100 0000, 0x80 = 1000 0000
          return false;
        }
      }

      // Move to the next character (skip the bytes we've just validated)
      i += numBytes;
    }

    // If we reach here, all bytes are valid
    return true;
  }
};
// @lc code=end
