/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to check if a given string is a valid preorder
 * serialization of a binary tree, where non-null nodes are represented by their
 * values and null nodes by '#', all separated by commas. We must determine if
 * this string could represent a real binary tree's preorder traversal, without
 * reconstructing the tree itself.
 *
 * The key insight is that in a valid binary tree serialization, every non-null
 * node provides two "slots" for its children, and every node (null or not)
 * fills one slot. The serialization is valid if all slots are exactly filled by
 * the end, with no extra or missing slots.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses a "slot counting" approach:
 *   - Start with one slot for the root.
 *   - For each node in the preorder string:
 *       - Each node (including '#') fills one slot.
 *       - If the node is not '#', it creates two new slots (for its children).
 *   - If at any point we try to fill a slot when none are available, the
 * serialization is invalid.
 *   - At the end, all slots must be exactly filled (slot count is zero).
 *
 * Algorithmic Assumptions:
 *   - The input is always a valid comma-separated string of integers and '#'.
 *   - We do not reconstruct the tree; we only track slot usage.
 *
 * Time Complexity: O(N), where N is the length of the preorder string (since we
 * process each node once). Space Complexity: O(1), since we only use a few
 * integer variables.
 */

#include <sstream> // For std::stringstream to split the string
#include <string>  // For std::string

using std::string;

// @lc code=start
class Solution {
public:
  // Function to check if the given preorder serialization is valid
  bool isValidSerialization(string preorder) {
    int slots = 1; // Start with one slot for the root node

    std::stringstream ss(
        preorder); // Use stringstream to split the string by commas
    string token;

    // Process each node in the preorder string
    while (std::getline(ss, token, ',')) {
      // Each node fills one slot
      --slots;

      // If at any point slots become negative, the serialization is invalid
      if (slots < 0) {
        return false;
      }

      // If the node is not '#', it is a non-null node and creates two new slots
      // for its children
      if (token != "#") {
        slots += 2;
      }
      // If the node is '#', it is a null node and does not create any new slots
    }

    // At the end, all slots must be exactly filled (slots == 0)
    return slots == 0;
  }
};
/*
 * Example Input to Illustrate the Algorithm:
 * ----
 * Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
 *
 * Step-by-step explanation:
 *   - Start with 1 slot for the root.
 *   - "9" uses 1 slot (slots: 0), creates 2 new slots (slots: 2).
 *   - "3" uses 1 slot (slots: 1), creates 2 new slots (slots: 3).
 *   - "4" uses 1 slot (slots: 2), creates 2 new slots (slots: 4).
 *   - "#" uses 1 slot (slots: 3), creates 0 new slots.
 *   - "#" uses 1 slot (slots: 2), creates 0 new slots.
 *   - "1" uses 1 slot (slots: 1), creates 2 new slots (slots: 3).
 *   - "#" uses 1 slot (slots: 2), creates 0 new slots.
 *   - "#" uses 1 slot (slots: 1), creates 0 new slots.
 *   - "2" uses 1 slot (slots: 0), creates 2 new slots (slots: 2).
 *   - "#" uses 1 slot (slots: 1), creates 0 new slots.
 *   - "6" uses 1 slot (slots: 0), creates 2 new slots (slots: 2).
 *   - "#" uses 1 slot (slots: 1), creates 0 new slots.
 *   - "#" uses 1 slot (slots: 0), creates 0 new slots.
 *   - At the end, slots == 0, so the serialization is valid.
 */
//
// @lc code=end
